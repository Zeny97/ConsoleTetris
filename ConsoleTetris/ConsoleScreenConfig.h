#ifndef CONSOLE_SCREEN_CONFIG_H
#define CONSOLE_SCREEN_CONFIG_H

#include <Windows.h>
#include <thread>
#include <vector>
#include <iostream>

class ConsoleScreenConfig
{
public:
	HANDLE hConsoleBuffer;
	HANDLE hConsole;
	ConsoleScreenConfig();
	void SetConsoleScreenFont(int width, int height, const wchar_t* fontName);
};

#endif // !CONSOLE_SCREEN_CONFIG_H