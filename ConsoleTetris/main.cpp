#include "TetrisGame.h"

int main()
{
	TetrisGame* game = new TetrisGame();
	game->Run();
	delete game;
	game = nullptr;
	return 0;
}



