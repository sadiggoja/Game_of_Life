#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"cell.h"

int sumOfNeighbors(int i, int j, int size, int **arena){
    int sum=0;
    if(i==0){
        if(j==0){
            sum=arena[i+1][j]+arena[i+1][j+1]+arena[i][j+1];
        }
        else if(j==(size-1)){
            sum=arena[i+1][j]+arena[i+1][j-1]+arena[i][j-1];
        }
        else{sum=arena[i+1][j]+arena[i+1][j-1]+arena[i+1][j+1]+arena[i][j-1]+arena[i][j+1];}
    }else if(i==(size-1)){
        if(j==0){sum=arena[i-1][j]+arena[i][j+1]+arena[i-1][j+1];}
        else if(j==(size-1)){sum=arena[i-1][j]+arena[i-1][j-1]+arena[i][j-1];}
        else {sum=arena[i-1][j]+arena[i-1][j-1]+arena[i-1][j+1]+arena[i][j-1]+arena[i][j+1];}
    }else if (j==0){
        sum=arena[i][j+1]+arena[i-1][j]+arena[i+1][j]+arena[i-1][j+1]+arena[i+1][j+1];
    }else if (j==(size-1)){
        sum=arena[i][j-1]+arena[i-1][j]+arena[i+1][j-1]+arena[i+1][j]+arena[i-1][j-1];
    }else {
        sum=arena[i-1][j-1]+arena[i-1][j]+arena[i-1][j+1]+arena[i][j+1]+arena[i][j-1]+arena[i+1][j-1]+arena[i+1][j]+arena[i+1][j+1];
    }
    return sum;
}

int cellSituation (int i, int j, int size, int **arena){
    int neighbors=sumOfNeighbors(i,j,size,arena);
    if(arena[i][j]==0){
        if(neighbors==3){
            return 1;
        }else {
            return 0;
        }
    }
    if(arena[i][j]==1){
        if(neighbors==2 || neighbors==3){
            return 1;
        }
        else {
            return 0;
        }
    }

}