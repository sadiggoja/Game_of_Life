#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include"arena.h"
#include"cell.h"
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <SDL.h>

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

int main(int argc, char *argv[]){ 
    // int type=1;
    if(argc==2){
        if(argv[1][0]=='0') {type=0;}
        else if(argv[1][0]=='1'){type=1;}
    } else{
        printf("give type\n 0 (zero) for clipped \n 1 (one) for  circular\n type: ");
        scanf("%d",&type);}
    int size;
    printf("give size: ");
    scanf("%d", &size);
    int **newGame=randomGenerate(size,newArena(size));
    // printArenaDigits(size, newGame);
    playGame(size,newGame);
    int choice;
    printf("if you want to see SDL version please enter 2 or any other number to quit program");
    scanf("%d",&choice);
    if(choice==2){
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr,"Problem can not init SDL2 \n");
		return 0;
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
		draw_SDL(renderer,newGame,size);
		SDL_RenderPresent(renderer);

	}
	SDL_Quit();
    }
    
    return 0;
}