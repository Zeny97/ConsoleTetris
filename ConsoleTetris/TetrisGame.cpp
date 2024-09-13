#include "TetrisGame.h"
#include <ctime>
#include <cstdlib>
#include <WinUser.h>

TetrisGame::TetrisGame(){
	std::srand(std::time(nullptr));
	SpawnNewTetromino();
}

void TetrisGame::SpawnNewTetromino(){
	currentTetrominoType = std::rand() % (int)ETetrominoType::ENUM_MAX;
	currentRotation = 0;
	currentPosX =  FIELD_WIDTH / 2;
	currentPosY = 0;
}

void TetrisGame::Init(){
	ConsoleScreen* consoleScreen = new ConsoleScreen;
	GameField* gameField = new GameField;

	consoleScreen->PrintConsoleScreen();
}

void TetrisGame::Run(){
	
	bool isRunning = true;
	while (isRunning)
	{
		gameField->PlaceTetromino(currentTetromino, currentTetrominoType, currentRotation, currentPosX, currentPosY);
		HandleInput();
		UpdateTetrominoPosition();
		gameField->CheckAndClearLines();
	}
	EndGame();
}

void TetrisGame::HandleInput(){
	if (GetAsyncKeyState(VK_LEFT)){

	}
	else if (GetAsyncKeyState(VK_RIGHT)){

	}
	else if (GetAsyncKeyState(VK_UP)){

	}
	else if (GetAsyncKeyState(VK_DOWN)){

	}
	else if (GetAsyncKeyState(0x58)){ // X Key

	}
	else if (GetAsyncKeyState(0x59)){ // Y Key

	}
}

void TetrisGame::UpdateTetrominoPosition(){
	// TODO: Implementiere Tetrominopositionsupdate nach x, wobei x f�r einen Zeitwert steht.
}

void TetrisGame::EndGame(){
	DELETE_POINTER(gameField);
	DELETE_POINTER(currentTetromino);
	std::cout << "Game Over!" << std::endl;
}