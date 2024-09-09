#ifndef TETRISGAME_H
#define TETRISGAME_G

#include "GameField.h"
#include "Tetromino.h"

class TetrisGame 
{
private:
	GameField* gameField;
	Tetromino* currentTetromino;
	int currentTetrominoType;
	int currentRotation;
	int currentPosX;
	int currentPosY;

public:
	TetrisGame();
	void Run();
	void SpawnNewTetromino();
	void HandleInput();
	void UpdateTetrominoPosition();
	void EndGame();
};

#endif