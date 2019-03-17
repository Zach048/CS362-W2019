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

struct gameState state1, state2, state3;
int seed = 1000;
int numPlayer = 2;
int maxBonus = 10;
int p, r, handCount;
int bonus;
int k[10] = {adventurer, council_room, feast, steward, mine, remodel, smithy, village, baron, great_hall};

void testBuyCard()
{
	
	printf("\n----------Start Testing buyCard()----------\n");


	initializeGame(numPlayer, k, seed, &state1);
	state1.coins = 10;
	state1.numBuys = 1;
	int test1 = buyCard(village, &state1);
	
	if(state1.coins == 7 && test1 == 0)
		printf("buyCard(): PASS when testing buying Village with 10 coins. Actual: %d Expected: 7\n", state1.coins);		
	else
		printf("buyCard(): FAIL when testing buying Village with 10 coins. Actual: %d Expected: 7\n", state1.coins);
	if(state1.deckCount[0] == 6 && test1 == 0)
		printf("buyCard(): PASS when testing adding Village to deck after purchase. Actual: %d Expected: 6\n", state1.deckCount[0]);		
	else
		printf("buyCard(): FAIL when testing adding Village to deck after purchase. Actual: %d Expected: 6\n", state1.deckCount[0]);
	
	initializeGame(numPlayer, k, seed, &state2);
	state2.coins = 1;
	state2.numBuys = 1;
	int test2 = buyCard(smithy, &state2);

	if(state2.coins == 1 && test2 < 0)
		printf("buyCard(): PASS when testing buying Smithy with 1 coin. Can't buy, coins unchanged. Actual: %d Expected: 1\n", state2.coins);		
	else
		printf("buyCard(): FAIL when testing buying Smithy with 1 coin. Can't buy, coins unchanged. Actual: %d Expected: 1\n", state2.coins);
	
	initializeGame(numPlayer, k, seed, &state3);
	state3.coins = 10;
	state3.numBuys = 0;
	int test3 = buyCard(council_room, &state1);

	if(state3.coins == 10 && test3 < 0)
		printf("buyCard(): PASS when testing buying Council Room with 10 coins but no buys. Actual: %d Expected: 10\n", state3.coins);		
	else
		printf("buyCard(): FAIL when testing buying Room with 10 coins but no buys. Actual: %d Expected: 10\n", state3.coins);

	printf("\n----------End Testing buyCard()----------\n");

}

int main(int argc, char *argv[])
{
    testBuyCard();
    return 0;
}