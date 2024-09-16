#include "TetrisGame.h"
#include "Macros.h"
#include <Windows.h>
#include <ctime>

TetrisGame::TetrisGame(){
	gameField = nullptr;
	currentTetromino = nullptr;
	std::srand(std::time(nullptr));
}

void TetrisGame::SpawnNewTetromino(){
	currentTetrominoType = 1;//std::rand() % (int)ETetrominoType::ENUM_MAX;
	currentRotation = 0;
	currentPosX =  FIELD_WIDTH / 2 - 2;
	currentPosY = 0;
	currentTetromino = new Tetromino();
}

void TetrisGame::Init(){
	CLEAR_SCREEN;
	gameField = new GameField();
	gameField->InitializeGamefield();
	gameField->DrawGamefield();
	SpawnNewTetromino();
}

void TetrisGame::Run(){
	
	bool isRunning = true;
	while (isRunning)
	{
		DrawCurrentTetromino();
		HandleInput();
		gameField->CheckAndClearLines();
		Sleep(500);
		UpdateTetrominoPosition();
	}
	EndGame();
}

void TetrisGame::HandleInput(){
	if (GetAsyncKeyState(VK_LEFT)) {
		// Move left
		DrawCurrentTetromino(true); // Clear previous position
		currentPosX = max(0, currentPosX - 1);
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		// Move right
		DrawCurrentTetromino(true); // Clear previous position
		currentPosX = min(FIELD_WIDTH - 4, currentPosX + 1);
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		// Drop faster
		DrawCurrentTetromino(true); // Clear previous position
		currentPosY = min(FIELD_HEIGHT - 4, currentPosY + 1);
	}
	else if (GetAsyncKeyState(VK_UP)) {
		// Hard drop
		DrawCurrentTetromino(true); // Clear previous position
		while (currentPosY < FIELD_HEIGHT - 4)
			currentPosY++;
	}
	else if (GetAsyncKeyState(0x58)){ // X Key
		if (currentRotation == 3){
			currentRotation = 0;
			return;
		}
		currentRotation++;
	}
	else if (GetAsyncKeyState(0x59)){ // Y Key
		if (currentRotation == 0) {
			currentRotation = 3;
			return;
		}
		currentRotation = 3;
	}
}

void TetrisGame::UpdateTetrominoPosition(){
	// Move tetromino down by default
	DrawCurrentTetromino(true); // Clear previous position
	currentPosY = min(FIELD_HEIGHT - 4, currentPosY + 1);
}

void TetrisGame::DrawCurrentTetromino(bool clear) {
	char block = clear ? ' ' : '\u2588'; // Clear with space or draw with block
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (currentTetromino->GetTetrominoType(currentTetrominoType, currentRotation, y, x) == 1) {
				COORD pos = { (short)(currentPosX + x), (short)(currentPosY + y) };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << block;
			}
		}
	}
}

void TetrisGame::EndGame(){
	DELETE_POINTER(gameField);
	DELETE_POINTER(currentTetromino);
	std::cout << "Game Over!" << std::endl;
}