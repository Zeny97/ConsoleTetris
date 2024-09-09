#ifndef TETROMINOS_H
#define TETROMINOS_H


class Tetromino
{
public:
	Tetromino();
	int GetTetrominoType(int Type, int Rotation, int X, int Y);
};

enum TetrominoTypes 
{
	O = 0,
	I,
	J,
	L,
	S,
	Z,
	T,
	ENUM_MAX
};

#endif

