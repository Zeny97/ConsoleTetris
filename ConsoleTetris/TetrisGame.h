#ifndef TETRISGAME_H
#define TETRISGAME_G

#include "GameField.h"
#include "ConsoleScreen.h"
#include "Tetromino.h"

#define DELETE_POINTER(pointer) delete pointer; pointer = nullptr
#define PRINT_STUFF_HERE(X,Y) printf("\033[%d;%dH",Y,X)

class TetrisGame 
{
public:
	GameField* gameField;
	ConsoleScreen* consoleScreen;
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