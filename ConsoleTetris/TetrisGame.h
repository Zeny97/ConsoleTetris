#ifndef TETRISGAME_H
#define TETRISGAME_H

#include "GameField.h"
#include "Tetromino.h"
#include <WinUser.h>
#include <vector>

class TetrisGame 
{
private:
	bool leftKeyPressed, rightKeyPressed, downKeyPressed, upKeyPressed, xKeyPressed, yKeyPressed;
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
	void DrawCurrentTetromino(bool clear = false);
	void UpdateTetrominoPosition();
	void LockTetrominoInPlace();
	bool CheckCollision(int offsetX, int offsetY, int rotation);
	void HandleInput();
	void SetTetrominoColor(int tetrominoType);
};
#endif