#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "GameField.h"
#include "Tetromino.h"
#include <WinUser.h>
#include <vector>

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
	void DrawCurrentTetromino(bool clear = false);
};
#endif