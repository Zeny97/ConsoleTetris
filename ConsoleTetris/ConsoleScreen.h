#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include <Windows.h>
#include <thread>
#include <vector>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 30

class ConsoleScreen
{
public:
    ConsoleScreen();
    ConsoleScreen(int, int);
    CreateConsoleScreen
    const int m_iconsoleScreenWidth = 0;
    const int m_iconsoleScreenHeight = 0;
    wchar_t* consoleScreen = nullptr;
    HANDLE hConsole;
};
#endif

