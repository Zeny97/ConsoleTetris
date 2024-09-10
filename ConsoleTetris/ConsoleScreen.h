#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include <Windows.h>
#include <thread>
#include <vector>

class ConsoleScreen
{
public:
    ConsoleScreen(int, int);
    const int m_iconsoleScreenWidth;
    const int m_iconsoleScreenHeight;
    wchar_t* consoleScreen;
    HANDLE hConsole;
};
#endif

