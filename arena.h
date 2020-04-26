#ifndef ARENA
#define ARENA


int **newArena(int size);
int **copyArena(int size, int **arena);
int **randomGenerate(int size, int **arena);
void printArenaDigits(int size, int **arena);
#endif
