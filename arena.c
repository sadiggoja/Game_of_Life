#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"arena.h"

int **newArena(int size){
	
    int ** arena = malloc(size*sizeof(int *));
	for(int i=0; i< size; i++) arena[i] = malloc(size*sizeof(int));
	
    return arena;
}

int **copyArena(int size, int **arena){
    
    int **copy=(int**)malloc(size*sizeof(int*));
    for(int i=0; i<size;i++) 
        copy[i]=(int*)malloc(size*sizeof(int));
    
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++)
            copy[i][j]=arena[i][j];
    }

    return copy;
}


int **randomGenerate(int size, int **arena){
    
    srand(time(0));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            arena[i][j]=rand()%2;
        }
    }

    return arena;
}

void printArenaDigits(int size, int **arena){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d ", arena[i][j]);
        }
        printf("\n");
    }

}