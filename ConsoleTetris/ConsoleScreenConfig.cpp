#include "ConsoleScreenConfig.h"
#include "Macros.h"

ConsoleScreenConfig::ConsoleScreenConfig()
{

}

void ConsoleScreenConfig::SetConsoleScreenFont(int width, int height, const wchar_t* fontName)
{
	hConsoleBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (hConsoleBuffer == INVALID_HANDLE_VALUE) {
		std::cerr << "Error getting console handle!" << std::endl;
		return;
	}
	SetConsoleActiveScreenBuffer(hConsoleBuffer);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Get console handle
	if (hConsole == INVALID_HANDLE_VALUE) {
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
	wcscpy_s(cfi.FaceName, fontName);          // Set the font name, e.g., "Consolas"

	// Set the font style to normal weight
	cfi.FontWeight = FW_NORMAL;

	// Set the console font using SetCurrentConsoleFontEx
	if (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi)) {
		std::cerr << "Error setting console font!" << std::endl;
	}
	else {
		std::cout << "Console font set successfully!" << std::endl;
	}
}


