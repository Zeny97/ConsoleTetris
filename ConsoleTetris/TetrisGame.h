#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "GameField.h"
#include "Tetromino.h"
#include <WinUser.h>
#include <vector>

class TetrisGame 
{
private:
	bool leftKeyPressed, rightKeyPressed, downKeyPressed, xKeyPressed, yKeyPressed;
	GameField* gameField;
	Tetromino* currentTetromino;

	int currentTetrominoType = 0;
	int currentRotation = 0;
	int currentPosX = 0;
	int currentPosY = 0;

public:
	TetrisGame();
	void Init();
	void Run();
	void EndGame();
	void SpawnNewTetromino();
	void HandleInput();
	void UpdateTetrominoPosition();
	bool CheckCollision(int offsetX, int offsetY);
	void DrawCurrentTetromino(bool clear = false);
	void LockTetrominoInPlace();
};
#endif