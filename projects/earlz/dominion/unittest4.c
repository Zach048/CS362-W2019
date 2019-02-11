/*********************************************
* CS362 - Assignment 3
* Zach Earl
* 2/10/19
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct gameState state;

void testWhoseTurn()
{
	printf("\n----------Start Testing whoseTurn()----------\n");


	state.whoseTurn =  0;
	if(whoseTurn(&state) == 0)
		printf("whoseTurn(): PASS when it is player 1's turn: %d\n", state.whoseTurn);
	else
		printf("whoseTurn(): FAIL when it is player 1's turn: %d\n", state.whoseTurn);
	
	state.whoseTurn =  1;
	if(whoseTurn(&state) == 1)
		printf("whoseTurn(): PASS when it is player 2's turn: %d\n", state.whoseTurn);
	else
		printf("whoseTurn(): FAIL when it is player 2's turn: %d\n", state.whoseTurn);

	printf("\n----------End Testing whoseTurn()----------\n");

}

int main(int argc, char *argv[])
{
    testWhoseTurn();
    return 0;
}