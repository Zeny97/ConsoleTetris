#ifndef TETRISGAME_H
#define TETRISGAME_G

#include "GameField.h"
#include "Tetromino.h"
#include <WinUser.h>

class TetrisGame 
{
public:
	GameField* gameField;
	Tetromino* currentTetromino;

	int currentTetrominoType;
	int currentRotation;
	int currentPosX;
	int currentPosY;

	TetrisGame();
	void Init();
	void Run();
	void SpawnNewTetromino();
	void HandleInput();
	void UpdateTetrominoPosition();
	void EndGame();
};

#endif