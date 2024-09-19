#include "Tetromino.h"
#include "Macros.h"

char defTetrominos[7 /* type */][4 /*rotation */][4 /* horizontal */][4 /* vertical */] =
{
	// Square-Piece
	{
		// Rotation 0
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		//Rotation 2
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{0, 0, 0, 0},
			{0, 1, 1, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
	},
	// I-Piece
	{
		// Rotation 0
		{
			{0, 0, 0, 0},
			{2, 2, 2, 2},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 2, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{2, 2, 2, 2},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 2, 0, 0}
		},
	},
	// L-Piece
	{
		// Rotation 0
		{
			{3, 0, 0, 0},
			{3, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 3, 3, 0},
			{0, 3, 0, 0},
			{0, 3, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{3, 3, 3, 0},
			{0, 0, 3, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{0, 3, 0, 0},
			{0, 3, 0, 0},
			{3, 3, 0, 0},
			{0, 0, 0, 0}
		},
	},
	// J-Piece
	{
		// Rotation 0
		{
			{0, 0, 4, 0},
			{4, 4, 4, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 4, 4, 0},
			{0, 0, 0, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{4, 4, 4, 0},
			{4, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{4, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 0, 0, 0}
		},
	},
	// S-Piece
	{
		// Rotation 0
		{
			{0, 5, 5, 0},
			{5, 5, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 5, 0, 0},
			{0, 5, 5, 0},
			{0, 0, 5, 0},
			{0, 0, 0, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{0, 5, 5, 0},
			{5, 5, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{5, 0, 0, 0},
			{5, 5, 0, 0},
			{0, 5, 0, 0},
			{0, 0, 0, 0}
		},
	},
	// Z-Piece
	{
		// Rotation 0
		{
			{6, 6, 0, 0},
			{0, 6, 6, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 0, 6, 0},
			{0, 6, 6, 0},
			{0, 6, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{6, 6, 0, 0},
			{0, 6, 6, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{0, 6, 0, 0},
			{6, 6, 0, 0},
			{6, 0, 0, 0},
			{0, 0, 0, 0}
		},
	},
	// T-Piece
	{
		// Rotation 0
		{
			{0, 7, 0, 0},
			{7, 7, 7, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 1
		{
			{0, 7, 0, 0},
			{0, 7, 7, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 2
		{
			{0, 0, 0, 0},
			{7, 7, 7, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0}
		},
		// Rotation 3
		{
			{0, 7, 0, 0},
			{7, 7, 0, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0}
		},
	}
};

int Tetromino::GetTetrominoType(int Type, int Rotation, int X, int Y){
	return defTetrominos[Type][Rotation][X][Y];
}