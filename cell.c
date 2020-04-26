#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<unistd.h>
#include"cell.h"

int sumOfNeighbors(int i, int j, int size, int **arena){          // For each cell checks the number of neighbours
    int sum=0;                                                    // Since alive cell equals to '1',so the sum of neighbours will be the alive cells(Neighbours).
    if(i==0){                                                                                           // IT check the upper side of board
        if(j==0){        
            sum=arena[i+1][j]+arena[i+1][j+1]+arena[i][j+1];                                            // Left upper cell as it has 3 neigh.
        }else if(j==(size-1)){  
                sum=arena[i+1][j]+arena[i+1][j-1]+arena[i][j-1];                                        // Right upper cell as it has 3 neigh.
              }else{
                    sum=arena[i+1][j]+arena[i+1][j-1]+arena[i+1][j+1]+arena[i][j-1]+arena[i][j+1];      // Middle of the upper cells as they have 5 neigh.
               }
    }else if(i==(size-1)){                                                                               // IT checks the bottom cells
                if(j==0){
                     sum=arena[i-1][j]+arena[i][j+1]+arena[i-1][j+1];                                    // Left bottom cell as it has 3 neigh                          
                }else if(j==(size-1)){
                         sum=arena[i-1][j]+arena[i-1][j-1]+arena[i][j-1];                                // Right bottom cell as it has 3 neigh
                      }else{
                           sum=arena[i-1][j]+arena[i-1][j-1]+arena[i-1][j+1]+arena[i][j-1]+arena[i][j+1];  // Middle of the bottom cells as they have 5 neigh
                       }
          }else if(j==0){
                  sum=arena[i][j+1]+arena[i-1][j]+arena[i+1][j]+arena[i-1][j+1]+arena[i+1][j+1];           // Middle cells of the RIGHT side check
                }else if(j==(size-1)){
                         sum=arena[i][j-1]+arena[i-1][j]+arena[i+1][j-1]+arena[i+1][j]+arena[i-1][j-1];    // Middle cells of the LEFT side check
                      }else{
                             sum=arena[i-1][j-1]+arena[i-1][j]+arena[i-1][j+1]+arena[i][j+1]+arena[i][j-1]+arena[i+1][j-1]+arena[i+1][j]+arena[i+1][j+1];   // And the aside part of the cells that is situated in the middle and have 8 neighbours.              
                       }
    return sum;
}

/*
 CellSituatuin function get main 2D array 
 check the rules 
 return new integer
 ref* to game.c -> int **GameStep(int size, int **game)
*/
int cellSituation (int i, int j, int size, int **arena){   
    int neighbors=sumOfNeighbors(i,j,size,arena);  // gets the number of alive neighbours for a given cell
    if(arena[i][j]==0){                            // if it's died cell
        if(neighbors==3){     
            return 1;       // return 1 if alive neighbours are 3 as its given in rules
        }else {
            return 0;
        }
    }
    if(arena[i][j]==1){                             //if cell is alive
        if(neighbors==2 || neighbors==3){
            return 1;                               // return 1 if alive neighbours are 2 or 3 (For a given rules)
        }
        else {
            return 0;                     
        }
    }

}

        