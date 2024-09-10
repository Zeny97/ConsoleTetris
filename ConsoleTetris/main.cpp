#include "main.h"
#include "TetrisGame.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	TetrisGame* game = new TetrisGame();
	game->Run();
	delete game;
	game = nullptr;
	return 0;
}



