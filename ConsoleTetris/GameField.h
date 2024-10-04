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
	uint8_t gamefield[FIELD_HEIGHT][FIELD_WIDTH];
	GameField();
	void InitializeGamefield();
	void PrintTetrisGameUI();
	void DrawGamefield();
	bool CheckLine(int y);
	void ClearLine(int y);
	void LineClear();
	unsigned char GetCellValue(int coordX, int coorY);
	void SetCellValueToBlock(int coordX, int coorY);

	
};
#endif