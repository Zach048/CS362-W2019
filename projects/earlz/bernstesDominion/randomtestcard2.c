/*********************************************
* CS362 - Assignment 4
* Zach Earl
* 3/2/19
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int handTest = 0, deckTest = 0, discardTest = 0, actionsTest = 0, oppHandCount = 0, oppDeckCount = 0, otherTest = 0;

void checkVillage(struct gameState G, int player, int opponent) 
{
	struct gameState testG;
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(village, 0, 0, 0, &testG, 0, 0);
	// Village is removed from hand, +1 card to hand
	if(testG.handCount[player] == G.handCount[player]+1-1)
		handTest++;
	//printf("h: %d %d \n", testG.handCount[player], G.handCount[player]);
	// Add 2 actions
	if(testG.numActions == G.numActions+2)
		actionsTest++;
	//-1 cards removed from deck 
	if(testG.deckCount[player] == G.deckCount[player]-1)
		deckTest++;
	//printf("d: %d %d \n", testG.deckCount[player], G.deckCount[player]);

	// Village was played, -1 from play count
	if(testG.playedCardCount == G.playedCardCount+1)
		discardTest++;
	//printf("p: %d %d \n", testG.playedCardCount, G.playedCardCount);
	if(player == 0)
		opponent = 1;
	testG.whoseTurn = opponent;
	if(testG.handCount[opponent] == G.handCount[opponent])
		oppHandCount++;
	if(testG.deckCount[opponent] == G.deckCount[opponent])
		oppDeckCount++;

	int i;
	int j = 0;
	for(i = 0; i < 17; i++)
		if(supplyCount(i, &testG) == supplyCount(i, &G))
			j++;
	if(j == 17)
		otherTest++;

}

int main(int argc, char *argv[])
{
	int seed = 1000;
	int numPlayers = 2;
	int player = 0;
	int opponent = 0;
	struct gameState G;
	srand(time(NULL));
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};

	int i;
	for (i = 0; i < 2000; i++) 
	{
    	initializeGame(numPlayers, k, seed, &G);
		player = floor(Random() * 2);
    	G.deckCount[player] = floor(Random() * MAX_DECK);
    	G.numActions = 0;
    	G.handCount[player] = floor(Random() * MAX_HAND);
    	G.playedCardCount = floor(Random() * MAX_DECK-1);
    	G.whoseTurn = player;
    	checkVillage(G, player, opponent);
  	}
  	printf("\n----------Start Testing playVillage()----------\n");

    if(handTest + deckTest + discardTest + actionsTest + oppHandCount + oppDeckCount + otherTest == 14000)
    	printf("ALL RANDOM TESTS PASSED FOR Village\n");
    else
    {
    	printf("RANDOM TESTS FAILED:\n");
    	printf("One card added to hand failed: %d/2000\n", handTest);
    	printf("One card removed from deck: %d/2000\n", deckTest);
    	printf("Village card play count failed: %d/2000\n", discardTest);
    	printf("Two actions added to hand: %d/2000\n", actionsTest);
    	printf("Opponent hand count failed: %d/2000\n", oppHandCount);
    	printf("Opponent deck count failed: %d/2000\n", oppDeckCount);
    	printf("Other cards were not effected failed: %d/2000\n", otherTest);

    }
    printf("\n----------End Testing playVillage()----------\n");

    return 0;
}