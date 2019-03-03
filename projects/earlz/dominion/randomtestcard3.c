#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN 3

int handTest = 0, deckTest = 0, discardTest = 0, playedTest = 0, sameCardDiscarded = 0, coinTest = 0;
int oppHandTest = 0, oppDeckTest = 0, oppCoinTest = 0, oppDiscardTest = 0;
void checkAdventurer(struct gameState G, int player, int opponent) 
{
	struct gameState testG;
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.deck[player][testG.deckCount[player]-1] = village;
	testG.deck[player][testG.deckCount[player]-2] = copper;
	testG.deck[player][testG.deckCount[player]-3] = silver;

	// printf("%d %d\n", testG.deck[player][testG.deckCount[player]-1], testG.deckCount[player]-1); 
	// printf("%d\n", testG.deck[player][testG.deckCount[player]-2]); 
	// printf("%d\n", testG.deck[player][testG.deckCount[player]-3]); 

	// printf("bh: %d %d \n", testG.handCount[player], G.handCount[player]);

	cardEffect(adventurer, 0, 0, 0, &testG, 0, 0);
	// Adventurer adds two treasures and removes itself
	if(testG.handCount[player] == G.handCount[player]+2-1)
		handTest++;
	//printf("h: %d %d \n", testG.handCount[player], G.handCount[player]+2-1);
	//-3 cards removed from deck to hand
	if(testG.deckCount[player] == G.deckCount[player]-3)
		deckTest++;
	//printf("de: %d %d \n", testG.deckCount[player], G.deckCount[player]-3);

	// Adventurer was played, +1 from play count
	if(testG.playedCardCount == G.playedCardCount+1)
		playedTest++;
	//printf("p: %d %d \n", testG.playedCardCount, G.playedCardCount+1);
	// Add 3 coins
	if(testG.coins == G.coins+3)
		coinTest++;
	//printf("c: %d %d \n", testG.coins, G.coins+3);
	// Add Village to discared
	if(testG.discardCount[player] == G.discardCount[player]+1)
		discardTest++;
	//printf("d: %d %d \n", testG.discardCount[player], G.discardCount[player]+1);
	// Check to make sure Village is in both discard piles
	G.discard[player][G.discardCount[player]-1] = village;
	if(testG.discard[player][testG.discardCount[player]-1] == G.discard[player][G.discardCount[player]-1])
		sameCardDiscarded++;
	//printf("sc %d %d\n",  testG.discard[player][testG.discardCount[player]-1], G.discard[player][G.discardCount[player]-1]);
	if(player == 0)
		opponent = 1;
	testG.whoseTurn = opponent;
	if(testG.handCount[opponent] == G.handCount[opponent])
		oppHandTest++;
	if(testG.deckCount[opponent] == G.deckCount[opponent])
		oppDeckTest++;
	if(testG.coins == G.coins)
		oppCoinTest++;
	if(testG.discardCount[opponent] == G.discardCount[opponent])
		oppDiscardTest++;


}

int main(int argc, char *argv[])
{
	int player = 0;
	int seed = 1000;
	int min = 3;
	int opponent = 0;
	srand(time(NULL));
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};

	int i;
	for (i = 0; i < 2000; i++) 
	{
    	initializeGame(2, k, seed, &G);
		player = floor(Random() * 2);
    	G.deckCount[player] = floor(Random() * ((MAX_DECK - MIN) + 1) + MIN);
    	G.handCount[player] = floor(Random() * ((MAX_DECK - MIN) + 1) + MIN);
    	G.playedCardCount = floor(Random() * ((MAX_DECK - MIN) + 1) + MIN-1);
    	G.whoseTurn = player;
    	G.coins = floor(Random() * 10);
    	G.discardCount[player] = 0;
    	checkAdventurer(G, player, opponent);
  	}
  	printf("\n----------Start Testing playAdventurer()----------\n");

    if(handTest + deckTest + discardTest + playedTest + coinTest + sameCardDiscarded 
    	+ oppHandTest + oppDeckTest + oppCoinTest + oppDiscardTest == 20000)
    	printf("ALL RANDOM TESTS PASSED FOR ADVENTURER\n");
    else
    {
    	printf("RANDOM TESTS FAILED:\n");
    	printf("Two cards added and one removed from hand failed: %d/2000\n", handTest);
    	printf("Three cards removed from deck failed: %d/2000\n", deckTest);
    	printf("Adventurer card in play pile failed: %d/2000\n", playedTest);
    	printf("One card discarded to get two teasures failed: %d/2000\n", discardTest);
    	printf("Three treasures were added to coins failed: %d/2000\n", coinTest);
    	printf("Same Village card discarded to get two teasures failed: %d/2000\n", sameCardDiscarded);
		printf("Opponent hand count failed: %d/2000\n", oppHandTest);
    	printf("Opponent deck count failed: %d/2000\n", oppDeckTest);
    	printf("Opponent coin count failed: %d/2000\n", oppCoinTest);
    	printf("Opponent discard count failed: %d/2000\n", oppDiscardTest);
	}
	printf("\n----------End Testing playAdventurer()----------\n");

    return 0;
}