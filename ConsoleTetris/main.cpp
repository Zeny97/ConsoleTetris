#include "main.h"
#include "TetrisGame.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	TetrisGame* game = new TetrisGame();
	
	game->Init();
	game->Run();
	game->EndGame();

	delete game;
	game = nullptr;
	return 0;
}



