#include<stdio.h>
#include<stdlib.h>
#include"arena.h"
#include<time.h> 
#include<unistd.h>
int **array2d(int size){
	int ** arr = malloc(size*sizeof(int *));
	for(int i=0; i< size; i++) arr[i] = malloc(size*sizeof(int));
	return arr;
}
int sumOfNeighbors(int i, int j, int size, int **arr){
    int sum=0;
    if(i==0){
        if(j==0){
        // printf("yes");
            
            sum=arr[i+1][j]+arr[i+1][j+1]+arr[i][j+1];
            }
        else if(j==(size-1)){
            sum=arr[i+1][j]+arr[i+1][j-1]+arr[i][j-1];
            }
        else{sum=arr[i+1][j]+arr[i+1][j-1]+arr[i+1][j+1]+arr[i][j-1]+arr[i][j+1];}
    } else if(i==(size-1)){
        if(j==0){sum=arr[i-1][j]+arr[i][j+1]+arr[i-1][j+1];}
        else if(j==(size-1)){sum=arr[i-1][j]+arr[i-1][j-1]+arr[i][j-1];}
        else {sum=arr[i-1][j]+arr[i-1][j-1]+arr[i-1][j+1]+arr[i][j-1]+arr[i][j+1];}
    }else if (j==0){

        sum=arr[i][j+1]+arr[i-1][j]+arr[i+1][j]+arr[i-1][j+1]+arr[i+1][j+1];
    }else if (j==(size-1)){

        sum=arr[i][j-1]+arr[i-1][j]+arr[i+1][j-1]+arr[i+1][j]+arr[i-1][j-1];
    }else {

        sum=arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j+1]+arr[i][j-1]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
    }
    return sum;
}
int main(){
    // printf("%d\n",newArena(15));

	// // clear screen
	// printf("\033[2J");
    int **mans=array2d(5);
    // while(1){
    int size=5;
	// hide cursor
	// printf("\033[?25l");


    srand(time(0));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            mans[i][j]=rand()%2;
            printf("%d ", mans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", sumOfNeighbors(i,j,5,mans));
        }
        printf("\n");
    }
    printf("\n");
    


    // for(int i=0; i<5; i++){
    //     printf("\033[%d;4H",i+2);
    //     for(int j=0; j<5; j++){
    //         if(mans[i][j]==1){
    //             printf("\033[40m  ");
    //         }else{
    //             printf("\033[104m  ");
    //         }
    //     }
    //     printf("\n");
    // }
	// printf("\033[?25h");
    // sleep(1);
    // }
    // 	printf("\033[?25h");

        return 0;

}