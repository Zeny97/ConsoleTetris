#include "TetrisGame.h"
#include "Macros.h"
#include <Windows.h>
#include <ctime>
#include <chrono>

TetrisGame::TetrisGame() : leftKeyPressed(false), rightKeyPressed(false), downKeyPressed(false),
xKeyPressed(false), yKeyPressed(false) {
	gameField = nullptr;
	currentTetromino = nullptr;
	std::srand(std::time(nullptr));
}

void TetrisGame::SpawnNewTetromino() {
	currentTetrominoType = std::rand() % (int)ETetrominoType::ENUM_MAX - 1;
	currentRotation = 0;
	currentPosX = FIELD_WIDTH / 2 - 2;
	currentPosY = 0;
	currentTetromino = new Tetromino();
}

void TetrisGame::Init() {
	CLEAR_SCREEN;
	gameField = new GameField();
	gameField->InitializeGamefield();
	gameField->DrawGamefield();
	SpawnNewTetromino();
}

void TetrisGame::Run() {

	bool isRunning = true;

	// Timer setup using chrono
	auto lastFallTime = std::chrono::steady_clock::now();
	const int fallIntervalMs = 600;

	while (isRunning)
	{
		DrawCurrentTetromino();
		HandleInput();
		gameField->CheckAndClearLines();

		// Get the current time
		auto currentTime = std::chrono::steady_clock::now();
		int elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastFallTime).count();

		// If enough time has passed, update tetromino position
		if (elapsedMs >= fallIntervalMs) {
			if (!CheckCollision(0, 1)) {  // Move tetromino down if no collision
				UpdateTetrominoPosition();
			}
			else {
				LockTetrominoInPlace();
				SpawnNewTetromino();
				//if (CheckCollision(0, 0)) {  // Check if the new piece can spawn
				//	isRunning = false;       // If not, end the game
				//}
			}
			lastFallTime = currentTime; // Reset the timer
		}
	}
	EndGame();
}

// Function to check if moving the tetromino would result in a collision
bool TetrisGame::CheckCollision(int offsetX, int offsetY) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, currentRotation, y, x) != 0) {
				int newX = currentPosX + x + offsetX;
				int newY = currentPosY + y + offsetY;

				// Check bounds
				if (newX < 0 || newX >= FIELD_WIDTH || newY >= FIELD_HEIGHT) {
					return true; // Collision detected
				}

				// Check if there's already a piece in the new position
				if (gameField->GetCellValue(newX, newY) != 0) {
					return true; // Collision detected
				}
			}
		}
	}
	return false; // No collision
}

// Function to lock the tetromino in place
void TetrisGame::LockTetrominoInPlace() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, currentRotation, y, x) != 0) {
				gameField->SetCellValueToBlock(currentPosX + x, currentPosY + y); // Lock block in place
			}
		}
	}
}

void TetrisGame::HandleInput() {

	// Check for LEFT key press
	if (GetAsyncKeyState(VK_LEFT)) {
		if (!leftKeyPressed) { 
			DrawCurrentTetromino(true); // Clear previous position
			currentPosX = max(0, currentPosX - 1);
			leftKeyPressed = true;
		}
	}
	else {
		leftKeyPressed = false; // Reset when the key is released
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (!rightKeyPressed) {
			DrawCurrentTetromino(true); // Clear previous position
			currentPosX = min(FIELD_WIDTH - 4, currentPosX + 1);
			rightKeyPressed = true;
		}
		// Move right
	}
	else {
		rightKeyPressed = false;
	}

	if (GetAsyncKeyState(VK_DOWN)) {
		if (!downKeyPressed) {
			// Drop faster
			DrawCurrentTetromino(true); // Clear previous position
			currentPosY = min(FIELD_HEIGHT - 4, currentPosY + 1);
			downKeyPressed = true;
		}
	}
	else {
		downKeyPressed = false;
	}

	if (GetAsyncKeyState(VK_UP)) {
		// Hard drop
		DrawCurrentTetromino(true); // Clear previous position
		while (currentPosY < FIELD_HEIGHT - 4)
			currentPosY++;
	}

	if (GetAsyncKeyState(0x58)) { // X Key - Rotate clockwise
		if (!xKeyPressed) {
			DrawCurrentTetromino(true); // Clear previous position before rotating
			currentRotation = (currentRotation + 1) % 4;
			xKeyPressed = true;
		}
	}
	else {
		xKeyPressed = false;
	}

	if (GetAsyncKeyState(0x59)) { // Y Key - Rotate counter-clockwise
		if (!yKeyPressed) {
			DrawCurrentTetromino(true); // Clear previous position before rotating
			currentRotation = (currentRotation == 0) ? 3 : currentRotation - 1;
			yKeyPressed = true;
		}
	}
	else {
		yKeyPressed = false;
	}
}

void TetrisGame::UpdateTetrominoPosition() {
	// Move tetromino down by default
	DrawCurrentTetromino(true); // Clear previous position
	currentPosY = min(FIELD_HEIGHT - 4, currentPosY + 1);
}

void TetrisGame::DrawCurrentTetromino(bool clear) {
	const char* block = clear ? " " : u8"\u2588"; // Clear with space or draw with block
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

void TetrisGame::EndGame() {
	DELETE_POINTER(gameField);
	DELETE_POINTER(currentTetromino);
	std::cout << "Game Over!" << std::endl;
}