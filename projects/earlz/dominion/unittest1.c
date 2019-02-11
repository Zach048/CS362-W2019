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
int seed = 1000;
int numPlayer = 2;
int maxBonus = 10;
int p, r, handCount;
int bonus;
int k[10] = {adventurer, council_room, feast, steward, mine, remodel, smithy, village, baron, great_hall};

void testUpdateCoins()
{
	printf("\n----------Start Testing updateCoins()----------\n");


	int i;
	initializeGame(numPlayer, k, seed, &state);
	for (i = 0; i < 5; i++)
		state.hand[0][i] = copper; 
	
	updateCoins(0, &state, 0);

	if(state.coins == 5)
        printf("updateCoins(): PASS when test contains 10 copper treasures. Total coins: %d/5\n", state.coins);
    else
        printf("updateCoins(): FAIL when test contains 10 copper treasures. Total coins: %d/5\n", state.coins);

    for (i = 0; i < 5; i++)
		state.hand[0][i] = silver; 
	
	updateCoins(0, &state, 0);

	if(state.coins == 10)
        printf("updateCoins(): PASS when test contains 10 silver treasures. Total coins: %d/10\n", state.coins);
    else
        printf("updateCoins(): FAIL when test contains 10 silver treasures. Total coins: %d/10\n", state.coins);

    for (i = 0; i < 5; i++)
		state.hand[0][i] = gold; 
	
	updateCoins(0, &state, 0);

	if(state.coins == 15)
        printf("updateCoins(): PASS when test contains 10 gold treasures. Total coins: %d/15\n", state.coins);
    else
        printf("updateCoins(): FAIL when test contains 10 gold treasures. Total coins: %d/15\n", state.coins);

    for (i = 0; i < 5; i++)
		state.hand[0][i] = copper; 
	
	updateCoins(0, &state, 1);

	if(state.coins == 6)
        printf("updateCoins(): PASS when test contains 10 copper teasures and 1 bonus point. Total coins: %d/6\n", state.coins);
    else
        printf("updateCoins(): FAIL when test contains 10 copper teasures and 1 bonus point. Total coins: %d/6\n", state.coins);

    for (i = 0; i < 5; i++)
		state.hand[0][i] = smithy; 
	
	updateCoins(0, &state, 0);

	if(state.coins == 0)
        printf("updateCoins(): PASS when test contains 0 treasures. Total coins: %d/0\n", state.coins);
    else
        printf("updateCoins(): FAIL when test contains 0 treasures. Total coins: %d/0\n", state.coins);

    printf("\n----------End Testing updateCoins()----------\n");

}

int main(int argc, char *argv[])
{
    testUpdateCoins();
    return 0;
}