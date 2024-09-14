#include "main.h"
#include "Macros.h"
#include "TetrisGame.h"
#include <iostream>
#include <Windows.h>

void SetConsoleScreenFont(int,int,const wchar_t*);

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleScreenFont(32, 32, L"Terminal");
	
	TetrisGame* game = new TetrisGame();
	game->Init();
	game->Run();
	DELETE_POINTER(game);
	return 0;
}

void SetConsoleScreenFont(int width, int height, const wchar_t* fontName)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);  // Get console handle
	if (consoleHandle == INVALID_HANDLE_VALUE) {
		std::cerr << "Error getting console handle!" << std::endl;
		return;
	}

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);  // Set the size of the structure
	cfi.nFont = 0;                             // Use first font index

	// Set the font width and height (equal dimensions for a square font)
	cfi.dwFontSize.X = width;                  // Font width
	cfi.dwFontSize.Y = height;                 // Font height

	// Specify the font name (monospaced font)
	wcscpy_s(cfi.FaceName, fontName);
	cfi.FontWeight = FW_NORMAL;

	// Set the console font using SetCurrentConsoleFontEx
	SetCurrentConsoleFontEx(consoleHandle, FALSE, &cfi);
}