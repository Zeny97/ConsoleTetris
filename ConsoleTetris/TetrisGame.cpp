#include "TetrisGame.h"
#include <ctime>
#include <cstdlib>

TetrisGame::TetrisGame() 
{
	std::srand(std::time(nullptr));
	SpawnNewTetromino();
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
	GameField* gameField = new GameField;
	bool isRunning = true;
	while (isRunning)
	{
		system("cls");
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
	// TODO: Implementiere Eingabelogik für Bewegung (links/rechts) und Rotation
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