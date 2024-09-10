#ifndef TETROMINOS_H
#define TETROMINOS_H


class Tetromino
{
public:
	int GetTetrominoType(int Type, int Rotation, int X, int Y);
};

enum class ETetrominoType : unsigned char
{
	TT_O = 0,
	TT_I,
	TT_J,
	TT_L,
	TT_S,
	TT_Z,
	TT_T,
	ENUM_MAX
};

#endif

