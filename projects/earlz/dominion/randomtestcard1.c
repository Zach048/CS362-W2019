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

int handTest = 0, deckTest = 0, discardTest = 0, oppHandCount = 0, oppDeckCount = 0, otherTest = 0;

void checkSmithy(struct gameState G, int player, int opponent) 
{
	struct gameState testG;
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, 0, 0, 0, &testG, 0, 0);
	// Smithy is removed from hand, +3 cards to hand
	if(testG.handCount[player] == G.handCount[player]+3-1)
		handTest++;
	//printf("h: %d %d \n", testG.handCount[player], G.handCount[player]);
	//-3 cards removed from deck to hand
	if(testG.deckCount[player] == G.deckCount[player]-3)
		deckTest++;
	//printf("d: %d %d \n", testG.deckCount[player], G.deckCount[player]);

	// Smithy was played, -1 from play count
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
    	G.playedCardCount = floor(Random() * MAX_DECK-1);
    	G.handCount[player] = floor(Random() * MAX_HAND);
    	G.whoseTurn = player;
    	checkSmithy(G, player, opponent);
  	}
  	printf("\n----------Start Testing playSmithy()----------\n");

    if(handTest + deckTest + discardTest + oppHandCount + oppDeckCount + otherTest == 12000)
    	printf("ALL RANDOM TESTS PASSED FOR SMITHY\n");
    else
    {
    	printf("RANDOM TESTS FAILED:\n");
    	printf("Three cards added to hand failed: %d/2000\n", handTest);
    	printf("Three cards removed from deck: %d/2000\n", deckTest);
    	printf("Smithy card discarded failed: %d/2000\n", discardTest);
    	printf("Opponent hand count failed: %d/2000\n", oppHandCount);
    	printf("Opponent deck count failed: %d/2000\n", oppDeckCount);
    	printf("Other cards were not effected failed: %d/2000\n", otherTest);

    }
    printf("\n----------End Testing playSmithy()----------\n");

    return 0;
}



