#include "TetrisGame.h"
#include "GameField.h"
#include "Tetromino.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

TetrisGame::TetrisGame() 
{
	std::srand(std::time(nullptr));
	SpawnNewTetromino();
}

void TetrisGame::SpawnNewTetromino() 
{
	currentTetrominoType = std::rand() % (TetrominoTypes::ENUM_MAX - 1);
	currentRotation = 0;
	currentPosX =  FIELD_WIDTH / 2;
	currentPosY = 0;
}

void TetrisGame::Run() 
{
	system("cls");
	gameField->DrawGameField();
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

void TetrisGame::HandleInput()
{
	// TODO: Implementiere Eingabelogik für Bewegung (links/rechts) und Rotation
}

void TetrisGame::UpdateTetrominoPosition()
{
	// currentPosY++;
}

void TetrisGame::EndGame()
{
	delete gameField;
	delete currentTetromino;
	gameField = nullptr;
	currentTetromino = nullptr;
	std::cout << "Game Over!" << std::endl;
}