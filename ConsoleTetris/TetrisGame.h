#ifndef TETRISGAME_H
#define TETRISGAME_G

#include "GameField.h"
#include "Tetromino.h"

class TetrisGame 
{
private:
	GameField* gameField = nullptr;
	Tetromino* currentTetromino = nullptr;
	int currentTetrominoType = 0;
	int currentRotation = 0;
	int currentPosX = 0;
	int currentPosY = 0;

public:
	TetrisGame();
	void Init();
	void Run();
	void SpawnNewTetromino();
	void HandleInput();
	void UpdateTetrominoPosition();
	void EndGame();
};

#endif