#ifndef MACROS_H
#define MACROS_H

#define DELETE_POINTER(pointer) delete pointer; pointer = nullptr
#define PRINT_STUFF_HERE(X,Y) printf("\033[%d;%dH",Y,X)
#define CLEAR_SCREEN system("cls")

#endif // !MACROS_H

