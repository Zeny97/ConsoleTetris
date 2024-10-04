#include "GameField.h"
#include "Macros.h"

GameField::GameField(){
}

void GameField::InitializeGamefield()
{
	COORD coord;
	coord.X = 2;
	coord.Y = 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

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

bool GameField::CheckLine(int y) {
    for (int x = 0; x < FIELD_WIDTH; x++) {
        if (gamefield[y][x] == 0) {
            return false; // Wenn ein Feld leer ist, ist die Linie nicht voll
        }
    }
    return true; // Alle Felder in der Linie sind gefüllt
}

void GameField::ClearLine(int y) {
    // Verschiebe alle darüber liegenden Linien eine Zeile nach unten
    for (int line = y; line > 0; line--) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            gamefield[line][x] = gamefield[line - 1][x];
        }
    }
    // Setze die oberste Linie auf leer
    for (int x = 0; x < FIELD_WIDTH; x++) {
        gamefield[0][x] = 0;
    }
}

void GameField::LineClear() {
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        if (CheckLine(y)) {
            ClearLine(y);
            y--; // Nach dem Löschen eine Zeile zurückgehen, da die aktuelle Zeile nach unten geschoben wurde
        }
    }
}


unsigned char GameField::GetCellValue(int coordX, int coordY)
{
	return gamefield[coordY][coordX];
}

void GameField::SetCellValueToBlock(int coordX,int coordY)
{
	gamefield[coordY][coordX] = 1;
}

void GameField::PrintTetrisGameUI()
{
	std::cout << "█          ██████████████████████\n"; 
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Justins Tetris    █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Controls :        █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Move : ← →        █\n";
	std::cout << "█          █  Rotate : y, x     █\n";
	std::cout << "█          █  Soft Drop : ↓     █\n";
	std::cout << "█          █  Hard Drop : ↑     █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Next Piece :      █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Score :           █\n";
	std::cout << "█          █                    █\n";
	std::cout << "█          █  Lvl : [01]        █\n";
	std::cout << "█          █  Lines : [00 / 00] █\n";
	std::cout << "█          █  Time : [00:00]    █\n";
	std::cout << "████████████                    █\n";
	std::cout << "█████████████████████████████████\n";
}

//void GameField::PrintTetrisGameInfo()
//{
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//	std::cout << "";
//}

