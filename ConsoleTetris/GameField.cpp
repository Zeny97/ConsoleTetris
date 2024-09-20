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
	return gamefield[coordY][coordX];
}

void GameField::SetCellValueToBlock(int coordX,int coordY)
{
	gamefield[coordY][coordX] = 1;
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
//	std::cout << "██████████████████████\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Justins Tetris    █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Controls :        █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Move : ← →        █\n";
//	std::cout << "█  Rotate : y, x     █\n";
//	std::cout << "█  Drop : ↓          █\n";
//	std::cout << "█  Hard Drop : ↑     █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Next Piece :      █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Score :           █\n";
//	std::cout << "█                    █\n";
//	std::cout << "█  Lvl : [01]        █\n";
//	std::cout << "█  Lines : [00 / 00] █\n";
//	std::cout << "█  Time : [00:00]    █\n";
//	std::cout << "█                    █\n";
//	std::cout << "██████████████████████\n";
//}

