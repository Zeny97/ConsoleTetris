#include "GameField.h"
#include "Macros.h"

GameField::GameField(){
}

void GameField::InitializeGamefield()
{
	for (int y = 0; y < FIELD_HEIGHT; y++){
		for (int x = 0; x < FIELD_WIDTH; x++){
			gamefield[y][x] = 0;
		}
	}
}

void GameField::DrawGamefield(){
	for (int y = 0; y < FIELD_HEIGHT - 1; y++){
		for (int x = 0; x < FIELD_WIDTH - 1; x++){
			std::cout << gamefield[y][x];
		}
		std::cout << std::endl;
	}
}

void GameField::CheckAndClearLines(){
	
}

unsigned char GameField::GetCellValue(int coordX, int coordY)
{
	return gamefield[coordX][coordY];
}

void GameField::SetCellValueToBlock(int coordX,int coordY)
{
	//gamefield[coordX][coordY] = 1;
}

//void GameField::PrintTetrisGamePlayfield()
//{
//	std::cout << "████████████";
//	std::cout << "████████████";
//	std::cout << "████████████";
//	std::cout << "████████████";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "█          █";
//	std::cout << "████████████";
//}
//
//void GameField::PrintTetrisGameInfo()
//{
//	std::cout << "██████████████████████";
//	std::cout << "█                    █";
//	std::cout << "█  Justins Tetris    █";
//	std::cout << "█                    █";
//	std::cout << "█  Controls :        █";
//	std::cout << "█                    █";
//	std::cout << "█  Move : ← →        █";
//	std::cout << "█  Rotate : y, x     █";
//	std::cout << "█  Drop : ↓          █";
//	std::cout << "█  Hard Drop : ↑     █";
//	std::cout << "█                    █";
//	std::cout << "█  Next Piece :      █";
//	std::cout << "█                    █";
//	std::cout << "█                    █";
//	std::cout << "█                    █";
//	std::cout << "█  Score :           █";
//	std::cout << "█                    █";
//	std::cout << "█  Lvl : [01]        █";
//	std::cout << "█  Lines : [00 / 00] █";
//	std::cout << "█  Time : [00:00]    █";
//	std::cout << "█                    █";
//	std::cout << "██████████████████████";
//}

