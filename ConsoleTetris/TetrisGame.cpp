#include "TetrisGame.h"
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
	currentTetrominoType = std::rand() % 7;
	currentRotation = 0;
	currentPosX = 10 / 2 - 2;
	currentPosY = 0;
}

void TetrisGame::Run() 
{
	bool isRunning = true;
	while (isRunning)
	{
		system("cls");
		gameField.DrawGameField();
		gameField.PlaceTetromino(currentTetromino, currentTetrominoType, currentRotation, currentPosX, currentPosY);

		HandleInput();
		Update();
		gameField.CheckAndClearLines();
	}
}

void TetrisGame::HandleInput()
{
	// TODO: Implementiere Eingabelogik für Bewegung (links/rechts) und Rotation
}

void TetrisGame::Update()
{
	// currentPosY++;
}

void TetrisGame::EndGame()
{
	std::cout << "Game Over!" << std::endl;
}