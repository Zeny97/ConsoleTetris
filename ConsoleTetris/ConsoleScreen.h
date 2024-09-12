#ifndef CONSOLESCREEN_H
#define CONSOLESCREEN_H

#include <Windows.h>
#include <thread>
#include <vector>

#define CONSOLE_SCREEN_WIDTH 60
#define CONSOLE_SCREEN_HEIGHT 30

class ConsoleScreen{
public:
    ConsoleScreen();
    void PrintConsoleScreen();
};
#endif

