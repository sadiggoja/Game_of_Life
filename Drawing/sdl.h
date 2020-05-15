#include <SDL.h>
#ifndef SDL
#define SDL


void draw_SDL(SDL_Renderer* renderer,int **arena,int size);
void playGame_SDL(int size, int **arena);

#endif