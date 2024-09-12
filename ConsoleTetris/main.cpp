#include <iostream>
#include <windows.h>
#include "main.h"
#include "TetrisGame.h"

#define DELETE_POINTER(pointer) delete pointer; pointer = nullptr
#define PRINT_STUFF_HERE(X,Y) printf("\033[%d;%dH",Y,X)
#define CLEAR_SCREEN system("cls")

int main(){
	SetConsoleOutputCP(CP_UTF8);
	CLEAR_SCREEN;

	TetrisGame* game = new TetrisGame();
	game->Init();

	DELETE_POINTER(game);
	return 0;
}



