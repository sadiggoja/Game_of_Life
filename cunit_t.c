#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "game.h"
#include "arena.h"
#include "cell.h"

int size=5;


void is_Initialized(void){
	CU_ASSERT_PTR_NOT_NULL_FATAL(newArena(size))
}
void is_Generated(void){
	CU_ASSERT_PTR_NOT_NULL(randomGenerate(size, newArena(size)));	
}

void passing_by_ref_check(void){
	int **arena=randomGenerate(size,newArena(size));
	int **copy=copyArena(size, arena);
	CU_ASSERT_EQUAL(GameStep(size,arena),arena);
	int **copy2=copyArena(size,arena);
	CU_ASSERT_NOT_EQUAL(GameStep(size,arena),copy2);

}
void alive_neigh_check(void){
	int **boardofcell=newArena(size);
	boardofcell[0][0]=1;
	boardofcell[0][1]=0;
	boardofcell[1][0]=1;
	boardofcell[1][1]=1;
	boardofcell[0][size-1]=0;
	boardofcell[1][size-1]=1;
	type=0;//clipped
	CU_ASSERT_EQUAL(sumOfNeighbors(0, 0,size, boardofcell),2);
	type=1;//circular
	CU_ASSERT_EQUAL(sumOfNeighbors(0, 0,size, boardofcell),3);

}
void cell_next_step_check(void){
int **boardofcell=newArena(size);
	boardofcell[0][0]=0;
	boardofcell[0][1]=0;
	boardofcell[1][0]=1;
	boardofcell[1][1]=1;
	boardofcell[0][size-1]=0;
	boardofcell[1][size-1]=1;
	type=0;//clipped
	CU_ASSERT_FALSE(cellSituation(0, 0,size,boardofcell));
    type=1;//circular
    CU_ASSERT_TRUE(cellSituation(0,0,size,boardofcell));
    boardofcell[0][0]=1;
    type=0;
    CU_ASSERT_TRUE(cellSituation(0, 0,size,boardofcell));
    type=1;
    CU_ASSERT_TRUE(cellSituation(0, 0,size,boardofcell));
}



int main(int argc, char const *argv[])
{

  
    
	if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
	
	CU_pSuite pSuite = CU_add_suite("Suite_arena", NULL, NULL);
	CU_pSuite pSuite2 = CU_add_suite("Suite_game", NULL, NULL);
	CU_pSuite pSuite3 = CU_add_suite("Suite_cell", NULL, NULL);

	CU_ADD_TEST(pSuite,is_Generated);
	CU_ADD_TEST(pSuite,is_Initialized);
	CU_ADD_TEST(pSuite2,passing_by_ref_check);
    CU_ADD_TEST(pSuite3,alive_neigh_check);
    CU_ADD_TEST(pSuite3,cell_next_step_check);


    CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	
   
	return 0;
}