#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"arena.h"
#include"cell.h"

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
    
    printf("\33[1J");                      // clear screen
    while(1){
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
        }
    
}
