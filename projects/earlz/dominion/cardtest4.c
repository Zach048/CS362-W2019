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

int testGreatHall(struct gameState testG, struct gameState G, int player, int opponent)
{
	printf("\n----------Start Testing Great Hall()----------\n");


	int test = myAssert(testG.numActions == G.numActions+1, "Number of actions + 1 when playing Great Hall.", testG.numActions, G.numActions+1-1);
	test += myAssert(testG.handCount[player] == G.handCount[player]+1-1, "Handcount + 1 when playing Great Hall.", testG.handCount[player], G.handCount[player]+1-1);
	test += myAssert(testG.playedCardCount == G.playedCardCount+1, "Played card deck - 1 when playing Great Hall.", testG.playedCardCount, G.playedCardCount+1);
	//test += myAssert(testG.discardCount[player] == G.discardCount[player]+1, "Discard count + 1 when playing Great Hall.");
	test += myAssert(testG.deckCount[player] == G.deckCount[player]-1, "Deckcount - 1 when playing Great Hall", testG.deckCount[player], G.deckCount[player]-1);
	test+= myAssert(scoreFor(player, &testG) == scoreFor(player, &G)+1, "Score for player + 1 when playing Great Hall", scoreFor(player, &testG), scoreFor(player, &G)+1);
	test += myAssert(testG.handCount[opponent] == G.handCount[opponent], "Opponent's handcount was unaltered when playing Village.", testG.handCount[opponent], G.handCount[opponent]);
	test += myAssert(testG.deckCount[opponent] == G.deckCount[opponent], "Opponent's deckcount was unaltered when playing Village.", testG.deckCount[opponent], G.deckCount[opponent]);
	//test += myAssert(testG.numActions[opponent] == G.numActions[opponent], "Opponent's number of actions were unaltered when playing Village.");
	//test += myAssert(testG.discardCount[opponent] == testG.discardCount[opponent], "Opponent's discard count was unaltered when playing Village.")
	test += myAssert(scoreFor(opponent, &testG) == scoreFor(opponent, &G), "Score for opponent when playing Great Hall remain unaltered.", scoreFor(opponent, &testG), scoreFor(opponent, &G));

	int i;
	int j = 0;
	for(i = 0; i < 17; i++)
		if(supplyCount(i, &testG) == supplyCount(i, &G))
			j++;
	test += myAssert(j == 17, "No state change occurred to victory or kingdom card piles.", j, 17);

	return test == 12;

	printf("\n----------End Testing Great Hall----------\n");

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
	// initialize a game state and player cards


	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	//scoreFor(player, &testG);

    if(testGreatHall(testG, G, player, opponent))
    	printf("TESTED SUCCESSFULLY WHEN PLAYING GREAT HALL.\n");
    else
    	printf("FAILURE WHEN TESTING PLAYING GREAT HALL.\n");
    return 0;
}