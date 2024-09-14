#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Tetromino.h" // Inkludiere Tetromino, weil es in der Klasse verwendet wird
#include <iostream>
#include <Windows.h>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

class GameField
{
public:
	unsigned char gamefield[FIELD_HEIGHT][FIELD_WIDTH];
	GameField();
	void InitializeGamefield();
	void DrawGamefield();
	void CheckAndClearLines();
};
#endif