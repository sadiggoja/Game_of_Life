#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>
#include "arena.h"
#include "cell.h"
#include "sdl.h"
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

/*
GameStep function generates new board(2Darray)
As it follows the rules by applying cellSituation() function in t
*/
int **GameStep(int size, int **game){  
    int **copy=copyArena(size,game);
    for(int i=0;i<size;i++){
        for (int j=0; j<size;j++){
            game[i][j]=cellSituation(i, j, size, copy);        // Edit cell    
        }
    }
    return game;                                           // Returns new board
}

/*
Drawing part*
The function performs ANSI codes that indicate the alive and dead cells
Following the rule for '0' cells it gives white color and for '1' red color
*/

void playGame(int size, int **arena){
    
    printf("\33[1J");  
    int counter;                    // clear screen
    while(counter<12){
        printf("\033[?25l");                // Hide cursor
        for(int i=0; i<size; i++){
            printf("\033[%d;4H",i+2);
            for(int j=0; j<size; j++){
                if(arena[i][j]==1){
                    printf("\033[41m  ");   // Red color
                }else{
                    printf("\033[47m  ");   // White color
                }
            }
            printf("\n");
            }
        printf("\033[?25h");
        sleep(1);
        arena=GameStep(size, arena);
        counter++;
        }
    
}

void draw_SDL(SDL_Renderer* renderer,int **arena,int size)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

    int dif=500/size;
	int row=0;
	for(int i=0; i<size; ++i)
	{
        int col=0;
		for(int j=0; j<size; ++j){
           if(arena[i][j]==1){
               SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
               for(int m=0; m<100;m++){
                   for(int n=0; n<100;n++){
                       SDL_RenderDrawPoint(renderer,n+col,m+row);
                   }
               }

           }else{
               SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
               for(int m=0;m<100;m++){
                   for(int n=0;n<100;n++){
                       SDL_RenderDrawPoint(renderer,n+col,m+row);
                   }
               }

           }
            col=col+dif;
        }  
        row=row+dif;    
	}
    sleep(1);
    arena=GameStep(size,arena);

	// MOUSE INTERACTION
	int x,y;
	if ( SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT) ) // one & it is for bits AND
	{
		// USE COLOR
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		SDL_RenderDrawPoint(renderer,x,y);
	}
}
void playGame_SDL(int size, int **arena){
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr,"Problem can not init SDL2 \n");
		return;
	}

	SDL_Window* window = SDL_CreateWindow("Life",
										  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										  500, 500, SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	assert (renderer != NULL);

// SIMPLE EVENT & DRAWING LOOP
    
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		draw_SDL(renderer,arena,size);
		SDL_RenderPresent(renderer);

	}
	SDL_Quit();

}
