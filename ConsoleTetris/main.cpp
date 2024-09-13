#include "main.h"
#include "Macros.h"

int main(){

	CLEAR_SCREEN;
	SetConsoleOutputCP(CP_UTF8);

	ConsoleScreenConfig* config = new ConsoleScreenConfig;
	config->SetConsoleScreenFont(32, 32, L"Terminal");
	DELETE_POINTER(config);
	
	TetrisGame* game = new TetrisGame();
	game->Init();
	DELETE_POINTER(game);
	return 0;
}



