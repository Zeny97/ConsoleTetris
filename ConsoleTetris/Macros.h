#ifndef MACROS_H
#define MACROS_H

#define DELETE_POINTER(pointer) delete pointer; pointer = nullptr
#define CHANGE_CONSOLE_COLOR(R,G,B) std::cout<< "\x1b[38;2;"<<(unsigned int)R<< ";" <<(unsigned int)G<< ";" <<(unsigned int)(B/10)<< "0m"
#define PRINT_STUFF_HERE(X,Y) printf("\033[%d;%dH",Y,X)
#define CLEAR_SCREEN system("cls")

#endif // !MACROS_H

