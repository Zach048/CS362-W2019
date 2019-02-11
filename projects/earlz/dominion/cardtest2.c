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
#include <string.h>

int myAssert(int result, char* message, int a, int e)
{
	if(!result)
	{
		printf("FAILED: %s Tested: %d Expected: %d\n", message, a, e);
		return 0;
	}
	else
		printf("PASSED: %s Tested: %d Expected: %d\n", message, a, e);
	{
		return 1;
	}
}

int testAdventurer(struct gameState testG, struct gameState G, int player, int opponent)
{
	printf("\n----------Start Testing playAdventurer()----------\n");


	int test = myAssert(testG.handCount[player] == G.handCount[player]+2-1, "Handcount when playing Adventurer:", testG.handCount[player], G.handCount[player]+2-1);
	test += myAssert(testG.deckCount[player] = G.deckCount[player]-3, "Deck count when playing Adventurer:", testG.deckCount[player], G.deckCount[player]-3);
	test += myAssert(testG.coins == G.coins+3, "Coins in hand when playing Adventurer:", testG.coins, G.coins+3);
	test += myAssert(testG.discardCount[player] == G.discardCount[player]+1, "Discarded card count after playing Adventurer:", testG.discardCount[player], G.discardCount[player]+1);
	test += myAssert(testG.playedCardCount == G.playedCardCount+1, "Played card deck when playing Adventurer:", testG.playedCardCount, G.playedCardCount+1);

	G.discard[player][0] = village;
	test += myAssert(testG.discard[player][0] == G.discard[player][0], "Cards were discarded when playing Adventurer:", testG.discard[player][0], G.discard[player][0]);
	
	testG.whoseTurn = opponent;
	test += myAssert(testG.handCount[opponent] == G.handCount[opponent], "Opponent's hand count was unaltered when playing Adventurer:", testG.handCount[opponent], G.handCount[opponent]);
	test += myAssert(testG.deckCount[opponent] == G.deckCount[opponent], "Opponent's deck count was unaltered when playing Adventurer:", testG.handCount[opponent], G.handCount[opponent]);
	test += myAssert(testG.coins == G.coins, "Opponent's coins were unaltered when playing Adventurer:", testG.coins, G.coins);
	test += myAssert(testG.discardCount[opponent] == G.discardCount[opponent], "Opponent's discarded card count after playing Adventurer:", testG.discardCount[opponent], G.discardCount[opponent]);



	int i;
	int j = 0;
	for(i = 0; i < 17; i++)
		if(supplyCount(i, &testG) == supplyCount(i, &G))
			j++;
	test += myAssert(j == 17, "No state change occurred to victory or kingdom card piles.", j, 17);

	return test == 11;

	printf("\n----------End Testing playAdventurer()----------\n");

}

int main(int argc, char *argv[])
{
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	int player = 0;
	int opponent = 1; // state should not be changed 
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	//printf("top: %d\n", testG.deck[player][0]);
	testG.deck[player][4] = village;
	testG.deck[player][3] = copper;
	testG.deck[player][2] = silver;


	cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    if(testAdventurer(testG, G, player, opponent))
    	printf("TESTED SUCCESSFULLY WHEN PLAYING ADVENTURER.\n");
    else
    	printf("FAILURE WHEN TESTING PLAYING ADVENTURER.\n");
    return 0;
}