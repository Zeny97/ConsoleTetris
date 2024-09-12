#include "TetrisGame.h"
#include "ConsoleScreen.h"
#include <ctime>
#include <cstdlib>
#include <WinUser.h>

TetrisGame::TetrisGame() 
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	SpawnNewTetromino();
}

void TetrisGame::Init()
{
	ConsoleScreen* consoleScreen = new ConsoleScreen;

	GameField* gameField = new GameField;
}

void TetrisGame::SpawnNewTetromino() 
{
	currentTetrominoType = std::rand() % (int)ETetrominoType::ENUM_MAX;
	currentRotation = 0;
	currentPosX =  FIELD_WIDTH / 2;
	currentPosY = 0;
}

void TetrisGame::Run() 
{

	bool isRunning = true;
	system("cls");
	while (isRunning)
	{
		gameField->DrawGameField();
		/*gameField->PlaceTetromino(currentTetromino, currentTetrominoType, currentRotation, currentPosX, currentPosY);
		HandleInput();
		UpdateTetrominoPosition();
		gameField->CheckAndClearLines();*/
	}
	EndGame();
}

void TetrisGame::HandleInput()
{
	if (GetAsyncKeyState(VK_LEFT)){
		UpdateTetrominoPosition();
	}
	else if (GetAsyncKeyState(VK_RIGHT)){
		UpdateTetrominoPosition();
	}
	else if (GetAsyncKeyState(VK_UP)) {
		UpdateTetrominoPosition();
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		UpdateTetrominoPosition();
	}
	else if (GetAsyncKeyState(0x58)) {
		UpdateTetrominoPosition();
	}
	else if (GetAsyncKeyState(0x59)) {
		UpdateTetrominoPosition();
	}
}

void TetrisGame::UpdateTetrominoPosition()
{

	// TODO: Implementiere Tetrominopositionsupdate nach x, wobei x für einen Zeitwert steht.
}

void TetrisGame::EndGame()
{
	delete gameField;
	delete currentTetromino;
	gameField = nullptr;
	currentTetromino = nullptr;
	std::cout << "Game Over!" << std::endl;
}