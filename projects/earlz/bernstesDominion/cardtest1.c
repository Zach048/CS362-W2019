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

int testSmithy(struct gameState testG, struct gameState G, int player, int opponent)
{
	printf("\n----------Start Testing playSmithy()----------\n");


	// Smithy is removed from hand, +3 cards to hand
	int test = myAssert(testG.handCount[player] == G.handCount[player]+3-1, "Handcount when playing Smithy:", testG.handCount[player], G.handCount[player]+3-1);
	//-3 cards removed from deck to hand
	test += myAssert(testG.deckCount[player] == G.deckCount[player]-3, "Deck count when playing Smithy:", testG.deckCount[player], G.deckCount[player]-3);
	// Smithy was played, -1 from play count
	test += myAssert(testG.playedCardCount == G.playedCardCount+1, "Played card deck when playing Smithy:", testG.playedCardCount, G.playedCardCount+1);

	
	testG.whoseTurn = opponent;
	test += myAssert(testG.handCount[opponent] == G.handCount[opponent], "Opponent's handcount unaltered when playing Smithy:", testG.handCount[opponent], G.handCount[opponent]);
	test += myAssert(testG.deckCount[opponent] == G.deckCount[opponent], "Opponent's deck count unaltered when playing Smithy:", testG.deckCount[opponent], G.deckCount[opponent]);



	int i;
	int j = 0;
	for(i = 0; i < 17; i++)
		if(supplyCount(i, &testG) == supplyCount(i, &G))
			j++;
	test += myAssert(j == 17, "No state change occurred to the 17 victory or kingdom card piles:", j, 17); // None of the supply count was touched

	return test == 6;

	printf("\n----------End Testing playSmithy()----------\n");


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
	printf("deck: %d\n", G.deckCount[player]);
	memcpy(&testG, &G, sizeof(struct gameState));
	// initialize a game state and player cards
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    if(testSmithy(testG, G, player, opponent))
    	printf("TESTED SUCCESSFULLY WHEN PLAYING SMITHY.\n");
    else
    	printf("FAILURE WHEN TESTING PLAYING SMITHY.\n");
    return 0;
}




