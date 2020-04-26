#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include"arena.h"

void main(){ 
    
    int size;
    printf("give size: ");
    scanf("%d", &size);
    int **newGame=newArena(size);
    newGame=randomGenerate(size,newGame);
    // printArenaDigits(size, newGame);
    playGame(size,newGame);

}