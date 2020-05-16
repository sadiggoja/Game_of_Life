#include<stdio.h>
#include<stdlib.h>
#include"game.h"
#include"arena.h"
#include"cell.h"
#include"sdl.h"



int main(int argc, char *argv[]){ 
    // int type=1;
    if(argc==2){
        if(argv[1][0]=='0') {type=0;}
        else if(argv[1][0]=='1'){type=1;}
    } else{
        printf("give type\n 0 (zero) for clipped \n 1 (one) for  circular\n type: ");
        scanf("%d",&type);}
    int size;
    printf("%d", type);
    printf("give size: ");
    scanf("%d", &size);
    int **newGame=randomGenerate(size,newArena(size));
    // printArenaDigits(size, newGame);
    // playGame(size,newGame);
    int choice;
    printf("if you want to see SDL version please enter 2 or any other number to show it at console: ");
    scanf("%d",&choice);
    if(choice==2){
        playGame_SDL(size,newGame);
    }else {
        playGame(size,newGame);
    }
    
    return 0;
}