#ifndef TETROMINOS_H
#define TETROMINOS_H

enum TetrominoTypes
{
	Square,
	I,
	L,
	J,
	S,
	Z,
	T,
};

class Tetromino
{
public:
	int GetTetrominoType(int Type, int Rotation, int X, int Y);
};

#endif

