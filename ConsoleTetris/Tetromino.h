#ifndef TETROMINOS_H
#define TETROMINOS_H

class Tetromino{
public:
	int GetTetrominoType(int Type, int Rotation, int X, int Y);
};

enum class ETetrominoType : unsigned char{
	NONE = 0,
	LOCKED = 1,
	TT_O = 2, // Yellow
	TT_I = 3, // Cyan
	TT_J = 4, // Blue
	TT_L = 5, // Orange
	TT_S = 6, // Green
	TT_Z = 7, // Red
	TT_T = 8, // Purple
};
#endif