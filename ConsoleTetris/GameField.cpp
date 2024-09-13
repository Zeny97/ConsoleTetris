#include "GameField.h"
#include "Macros.h"

GameField::GameField() 
{

}

void GameField::InitGameField()
{
	for (int y = 0; y < GAMEFIELD_AREA_HEIGHT; y++)
	{
		for (int x = 0; x < GAMEFIELD_AREA_WIDTH; x++)
		{
			playfieldArea[y][x] = 1;
		}
		std::cout << std::endl;
	}
}

void GameField::DrawGamefield()
{
	SetCursorPos(1, 5);
	// Initialize the GameField with 0 (empty spaces)
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (playfield[y][x] == 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
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
					playfield[posY + y][posX + x] = 1;
			}
		}
	}
}

void GameField::ClearField()
{
	// Setze das Spielfeld zurück (auf 0)
	for (int y = 0; y < FIELD_HEIGHT; y++)
		for (int x = 0; x < FIELD_WIDTH; x++)
			playfield[y][x] = 0;
}

void GameField::CheckAndClearLines()
{
	// TODO: Überprüfe das Spielfeld und lösche volle Reihen
}

void GameField::PrintTetrisGamePlayfield()
{
	std::cout << "████████████";
	std::cout << "████████████";
	std::cout << "████████████";
	std::cout << "████████████";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "█          █";
	std::cout << "████████████";
}

void GameField::PrintTetrisGameInfo()
{
	std::cout << "██████████████████████";
	std::cout << "█                    █";
	std::cout << "█  Justins Tetris    █";
	std::cout << "█                    █";
	std::cout << "█  Controls :        █";
	std::cout << "█                    █";
	std::cout << "█  Move : ← →        █";
	std::cout << "█  Rotate : y, x     █";
	std::cout << "█  Drop : ↓          █";
	std::cout << "█  Hard Drop : ↑     █";
	std::cout << "█                    █";
	std::cout << "█  Next Piece :      █";
	std::cout << "█                    █";
	std::cout << "█                    █";
	std::cout << "█                    █";
	std::cout << "█  Score :           █";
	std::cout << "█                    █";
	std::cout << "█  Lvl : [01]        █";
	std::cout << "█  Lines : [00 / 00] █";
	std::cout << "█  Time : [00:00]    █";
	std::cout << "█                    █";
	std::cout << "██████████████████████";
}

