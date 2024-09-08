#include "GameField.h"

GameField::GameField() 
{
	// Initialize the GameField with 0 (empty spaces)
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			gameField[y][x] = 0;
		}
	}
}

void GameField::DrawGameField()
{
	// Initialize the GameField with 0 (empty spaces)
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if(gameField[y][x] == 1)
			{
				std::cout << "██";
			}
			else
			{
				std::cout << "  ";
			}
			std::cout << std::endl;
		}
	}
}

void GameField::PlaceTetromino(Tetromino* tetromino, int type, int rotation, int posX, int posY)
{
	//Setze das Tetromino auf das Spielfeld
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (tetromino->GetTetrominoType(type,rotation,posX,posY) == 1)
			{
				if (posY + y < 20 && posX + x < 10)
					gameField[posY + y][posX + x] = 1;
			}
		}
	}
}

void GameField::ClearField()
{
	// Setze das Spielfeld zurück (auf 0)
	for (int y = 0; y < FIELD_HEIGHT; y++)
		for (int x = 0; x < FIELD_WIDTH; x++)
			gameField[y][x] = 0;
}

void GameField::CheckAndClearLines()
{
	// TODO: Überprüfe das Spielfeld und lösche volle Reihen
}