#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "Tetromino.h" // Inkludiere Tetromino, weil es in der Klasse verwendet wird
#include <iostream>
#include <Windows.h>


#define GAMEFIELD_AREA_WIDTH 12
#define GAMEFIELD_AREA_HEIGHT 25
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

class GameField
{
public:
	unsigned char playfieldArea[GAMEFIELD_AREA_HEIGHT][GAMEFIELD_AREA_WIDTH];
	unsigned char playfield[FIELD_HEIGHT][FIELD_WIDTH];
	GameField();
	void InitGameField();
	void DrawGamefield();
	void PlaceTetromino(Tetromino* tetromino, int type, int rotation, int posX, int posY);
	void ClearField();
	void CheckAndClearLines();
	void PrintTetrisGamePlayfield();
	void PrintTetrisGameInfo();
};
#endif