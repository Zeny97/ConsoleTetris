#include "GameField.h"
#include "Macros.h"

GameField::GameField(){
	// No need to allocate memory, arrays are automatically allocated on stack
}

void GameField::InitializeGamefield()
{
	for (int y = 0; y < FIELD_HEIGHT; y++){
		for (int x = 0; x < FIELD_WIDTH; x++){
			gamefield[y][x] = ' ';
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
	// TODO: Überprüfe das Spielfeld und lösche volle Reihen
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

