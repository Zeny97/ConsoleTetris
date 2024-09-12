#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen()
{
}

ConsoleScreen::ConsoleScreen(int iscreenWidth, int iscreenHeight) : m_iconsoleScreenWidth(iscreenWidth), m_iconsoleScreenHeight(iscreenHeight)
{
    consoleScreen = new wchar_t[iscreenWidth * iscreenHeight];
    for (int i = 0; i < iscreenWidth * iscreenHeight; i++) consoleScreen[i] = L' ';
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
}