#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Tetromino.h" // Inkludiere Tetromino, weil es in der Klasse verwendet wird
#include <iostream>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

class GameField
{
public:
	unsigned char gameField[FIELD_HEIGHT][FIELD_WIDTH];
	GameField();
	void DrawGameField();
	void PlaceTetromino(Tetromino* tetromino, int type, int rotation, int posX, int posY);
	void ClearField();
	void CheckAndClearLines();
};
#endif