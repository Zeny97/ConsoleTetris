#include "TetrisGame.h"
#include "Macros.h"
#include <Windows.h>
#include <ctime>
#include <chrono>

TetrisGame::TetrisGame() : leftKeyPressed(false), rightKeyPressed(false), downKeyPressed(false), upKeyPressed(false), xKeyPressed(false), yKeyPressed(false) {
	gameField = nullptr;
	currentTetromino = nullptr;
	std::srand(std::time(nullptr));
}

void TetrisGame::Init() {
	CLEAR_SCREEN;
	gameField = new GameField();
	gameField->PrintTetrisGameUI();
	gameField->InitializeGamefield();
	gameField->DrawGamefield();
	SpawnNewTetromino();
}

void TetrisGame::Run() {

	bool isRunning = true;

	// Timer setup using chrono
	auto lastFallTime = std::chrono::steady_clock::now();
	const int baseFallIntervalMs = 600;
	const int fallIncreasePerLvlMs = 30;
	int fallIntervalMs = baseFallIntervalMs - fallIncreasePerLvlMs;

	while (isRunning)
	{
		DrawCurrentTetromino();
		HandleInput();

		// Get the current time
		auto currentTime = std::chrono::steady_clock::now();
		int elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFallTime).count();

		// If enough time has passed, update tetromino position
		if (elapsedMs >= fallIntervalMs) {
			if (!CheckCollision(0, 1, currentRotation)) {  // Move tetromino down if no collision
				UpdateTetrominoPosition();
			}
			else {
				LockTetrominoInPlace();
				DELETE_POINTER(currentTetromino);
				SpawnNewTetromino();
				if (CheckCollision(0, 0, currentRotation)) {  // Check if the new piece can spawn
					isRunning = false;       // If not, end the game
				}
			}
			lastFallTime = currentTime; // Reset the timer
		}
	}
	EndGame();
}

void TetrisGame::EndGame() {
	DELETE_POINTER(gameField);
	DELETE_POINTER(currentTetromino);
	CHANGE_CONSOLE_COLOR(255, 255, 255);
	std::cout << "Game Over!" << std::endl;
}

void TetrisGame::SpawnNewTetromino() {
	currentTetrominoType = std::rand() % ((int)ETetrominoType::ENUM_MAX - (int)ETetrominoType::TT_O);
	SetTetrominoColor(currentTetrominoType);
	currentRotation = 0;
	currentPosX = FIELD_WIDTH / 2 - 2;
	currentPosY = 0;
	currentTetromino = new Tetromino();
}

void TetrisGame::DrawCurrentTetromino(bool clear) {
	const char* block = clear ? " " : u8"\u2588"; // Clear or draw with block
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, currentRotation, y, x) != 0) {
				COORD pos = { (short)(currentPosX + x), (short)(currentPosY + y) };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << block;
			}
		}
	}
}

void TetrisGame::UpdateTetrominoPosition() {
	// Move tetromino down by default
	DrawCurrentTetromino(true); // Clear previous position
	currentPosY++;
}

void TetrisGame::LockTetrominoInPlace() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, currentRotation, y, x) != 0) {
				gameField->SetCellValueToBlock(currentPosX + x, currentPosY + y); // Lock block in place
				//gameField->LineClear();
			}
		}
	}
}

bool TetrisGame::CheckCollision(int offsetX, int offsetY, int rotation) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, rotation, y, x) != 0) {
				int newX = currentPosX + x + offsetX;
				int newY = currentPosY + y + offsetY;

				// Check bounds
				if (newX < 0 || newX >= FIELD_WIDTH || newY >= FIELD_HEIGHT) {
					return true; // Collision detected
				}

				// Check if there's already a block in the new position
				if (gameField->GetCellValue(newX, newY) == 1) {
					return true; // Collision detected
				}
			}
		}
	}
	return false; // No collision
}

void TetrisGame::HandleInput() {

	// Check for LEFT key press
	if (GetAsyncKeyState(VK_LEFT)) {
		if (CheckCollision(-1, 0, currentRotation)) {
			return;
		}

		if (!leftKeyPressed) {
			DrawCurrentTetromino(true); // Clear previous position
			currentPosX--;
			leftKeyPressed = true;
		}
	}
	else {
		leftKeyPressed = false; // Reset when the key is released
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (CheckCollision(1, 0, currentRotation)) {
			return;
		}

		if (!rightKeyPressed) {
			DrawCurrentTetromino(true); // Clear previous position
			currentPosX++;
			rightKeyPressed = true;
		}
		// Move right
	}
	else {
		rightKeyPressed = false;
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		if (CheckCollision(0, 1, currentRotation)) {
			return;
		}
		if (!downKeyPressed) {
			// Drop faster
			DrawCurrentTetromino(true); // Clear previous position
			currentPosY++;
			downKeyPressed = true;
		}
	}
	else {
		downKeyPressed = false;
	}

	if (GetAsyncKeyState(VK_UP)) {
		if (!upKeyPressed) {
			// Hard drop
			upKeyPressed = true;
			DrawCurrentTetromino(true); // Clear previous position
			while (!CheckCollision(0, 1, currentRotation))
				currentPosY++;
		}
	}
	else {
		upKeyPressed = false;
	}

	if (GetAsyncKeyState(0x58)) { // X Key - Rotate clockwise
		if (!xKeyPressed) {
			if (!CheckCollision(0, 0, currentRotation + 1)) {
				DrawCurrentTetromino(true); // Clear previous position before rotating
				currentRotation = (currentRotation + 1) % 4;
				xKeyPressed = true;
			}
		}
	}
	else {
		xKeyPressed = false;
	}

	if (GetAsyncKeyState(0x59)) { // Y Key - Rotate counter-clockwise
		if (!yKeyPressed) {
			if (!CheckCollision(0, 0, currentRotation - 1)) {
				DrawCurrentTetromino(true); // Clear previous position before rotating
				currentRotation = (currentRotation == 0) ? 3 : currentRotation - 1;
				yKeyPressed = true;
			}
		}
	}
	else {
		yKeyPressed = false;
	}
}

void TetrisGame::SetTetrominoColor(int tetrominoType) {
	// Je nach Tetromino-Nummer eine andere Farbe setzen
	switch (tetrominoType) {
	case 0: // Tetromino 0 (Beispiel: Gelb)
		CHANGE_CONSOLE_COLOR(255, 250, 50);
		break;
	case 1: // Tetromino I (Beispiel: Cyan)
		CHANGE_CONSOLE_COLOR(0, 235, 250);
		break;
	case 2: // Tetromino L (Beispiel: Orange)
		CHANGE_CONSOLE_COLOR(250, 70, 25);
		break;
	case 3: // Tetromino J (Beispiel: Blau)
		CHANGE_CONSOLE_COLOR(0, 120, 210);
		break;
	case 4: // Tetromino S (Beispiel: Grün)
		CHANGE_CONSOLE_COLOR(80, 220, 60);
		break;
	case 5: // Tetromino Z (Beispiel: Rot)
		CHANGE_CONSOLE_COLOR(235, 20, 30);
		break;
	case 6: // Tetromino T (Beispiel: Magenta)
		CHANGE_CONSOLE_COLOR(225, 10, 180);
		break;
	}
}