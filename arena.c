#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"arena.h"

int **newArena(int size){              // This functions generate 2D array with the same size 
	
    int ** arena = malloc(size*sizeof(int *));
	for(int i=0; i< size; i++) arena[i] = malloc(size*sizeof(int));
	
    return arena;
}

int **copyArena(int size, int **arena){  // copies the main 2D array to another one.
    
    int **copy=(int**)malloc(size*sizeof(int*));
    for(int i=0; i<size;i++) 
        copy[i]=(int*)malloc(size*sizeof(int));
    
    for(int i=0; i<size; i++){
        for(int j=0;j<size;j++)
            copy[i][j]=arena[i][j];
    }

    return copy;
}


int **randomGenerate(int size, int **arena){ // This function fills the array with 2 random integers ( 0 or 1)
    
    srand(time(0));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            arena[i][j]=rand()%2; 
        }
    }

    return arena;
}

void printArenaDigits(int size, int **arena){ // This function prints the 2D array 
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d ", arena[i][j]);
        }
        printf("\n");
    }

}