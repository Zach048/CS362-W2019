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

void testGetCost()
{
	printf("\n----------Start Testing getCost()----------\n");


	if(getCost(curse) == 0)
		printf("getCost(): PASS when testing returning cost %d for Curse.\n", getCost(curse));
	else
		printf("getCost(): FAIL when testing returning cost %d for Curse.\n", getCost(curse));
	
	if(getCost(estate) == 2)
		printf("getCost(): PASS when testing returning cost %d for Estate.\n", getCost(estate));
	else
		printf("getCost(): FAIL when testing returning cost %d for Estate.\n", getCost(estate));
	
	if(getCost(duchy) == 5)
		printf("getCost(): PASS when testing returning cost %d for Duchy.\n", getCost(duchy));
	else
		printf("getCost(): FAIL when testing returning cost %d for Duchy.\n", getCost(duchy));
	
	if(getCost(province) == 8)
		printf("getCost(): PASS when testing returning cost %d for Province.\n", getCost(province));
	else
		printf("getCost(): FAIL when testing returning cost %d for Province.\n", getCost(province));
	
	if(getCost(copper) == 0)
		printf("getCost(): PASS when testing returning cost %d for Copper.\n", getCost(copper));
	else
		printf("getCost(): FAIL when testing returning cost %d for Copper.\n", getCost(copper));
	
	if(getCost(silver) == 3)
		printf("getCost(): PASS when testing returning cost %d for Silver.\n", getCost(silver));
	else
		printf("getCost(): FAIL when testing returning cost %d for Silver.\n", getCost(silver));
	
	if(getCost(gold) == 6)
		printf("getCost(): PASS when testing returning cost %d for Gold.\n", getCost(gold));
	else
		printf("getCost(): FAIL when testing returning cost %d for Gold.\n", getCost(gold));
	
	if(getCost(adventurer) == 6)
		printf("getCost(): PASS when testing returning cost %d for Adventurer.\n", getCost(adventurer));
	else
		printf("getCost(): FAIL when testing returning cost %d for Adventurer.\n", getCost(adventurer));
	
	if(getCost(council_room) == 5)
		printf("getCost(): PASS when testing returning cost %d for Council Room.\n", getCost(council_room));
	else
		printf("getCost(): FAIL when testing returning cost %d for Council Room.\n", getCost(council_room));
	
	if(getCost(feast) == 4)
		printf("getCost(): PASS when testing returning cost %d for Feast.\n", getCost(feast));
	else
		printf("getCost(): FAIL when testing returning cost %d for Feast.\n", getCost(feast));
	
	if(getCost(gardens) == 4)
		printf("getCost(): PASS when testing returning cost %d for Gardens.\n", getCost(gardens));
	else
		printf("getCost(): FAIL when testing returning cost %d for Gardens.\n", getCost(gardens));
	
	if(getCost(mine) == 5)
		printf("getCost(): PASS when testing returning cost %d for Mine.\n", getCost(mine));
	else
		printf("getCost(): FAIL when testing returning cost %d for Mine.\n", getCost(mine));
	
	if(getCost(remodel) == 4)
		printf("getCost(): PASS when testing returning cost %d for Remodel.\n", getCost(remodel));
	else
		printf("getCost(): FAIL when testing returning cost %d for Remodel.\n", getCost(remodel));
	
	if(getCost(smithy) == 4)
		printf("getCost(): PASS when testing returning cost %d for Smithy.\n", getCost(smithy));
	else
		printf("getCost(): FAIL when testing returning cost %d for Smithy.\n", getCost(smithy));
	
	if(getCost(village) == 3)
		printf("getCost(): PASS when testing returning cost %d for Village.\n", getCost(village));
	else
		printf("getCost(): FAIL when testing returning cost %d for Village.\n", getCost(village));
	
	if(getCost(baron) == 4)
		printf("getCost(): PASS when testing returning cost %d for Baron.\n", getCost(baron));
	else
		printf("getCost(): FAIL when testing returning cost %d for Baron.\n", getCost(baron));
	
	if(getCost(great_hall) == 3)
		printf("getCost(): PASS when testing returning cost %d for Great Hall.\n", getCost(great_hall));
	else
		printf("getCost(): FAIL when testing returning cost %d for Great Hall.\n", getCost(great_hall));
	
	if(getCost(minion) == 5)
		printf("getCost(): PASS when testing returning cost %d for Minion.\n", getCost(minion));
	else
		printf("getCost(): FAIL when testing returning cost %d for Minion.\n", getCost(minion));
	
	if(getCost(steward) == 3)
		printf("getCost(): PASS when testing returning cost %d for Steward.\n", getCost(steward));
	else
		printf("getCost(): FAIL when testing returning cost %d for Steward.\n", getCost(steward));
	
	if(getCost(tribute) == 5)
		printf("getCost(): PASS when testing returning cost %d for Tribute.\n", getCost(tribute));
	else
		printf("getCost(): FAIL when testing returning cost %d for Tribute.\n", getCost(tribute));
	
	if(getCost(ambassador) == 3)
		printf("getCost(): PASS when testing returning cost %d for Ambassador.\n", getCost(ambassador));
	else
		printf("getCost(): FAIL when testing returning cost %d for Ambassador.\n", getCost(ambassador));
	
	if(getCost(cutpurse) == 4)
		printf("getCost(): PASS when testing returning cost %d for Cutpurse.\n", getCost(cutpurse));
	else
		printf("getCost(): FAIL when testing returning cost %d for Cutpurse.\n", getCost(cutpurse));
	
	if(getCost(embargo) == 2)
		printf("getCost(): PASS when testing returning cost %d for Embargo.\n", getCost(embargo));
	else
		printf("getCost(): FAIL when testing returning cost %d for Embargo.\n", getCost(embargo));
	
	if(getCost(outpost) == 5)
		printf("getCost(): PASS when testing returning cost %d for Outpost.\n", getCost(outpost));
	else
		printf("getCost(): FAIL when testing returning cost %d for Outpost.\n", getCost(outpost));
	
	if(getCost(salvager) == 4)
		printf("getCost(): PASS when testing returning cost %d for Salvager.\n", getCost(salvager));
	else
		printf("getCost(): FAIL when testing returning cost %d for Salvager.\n", getCost(salvager));
	
	if(getCost(sea_hag) == 4)
		printf("getCost(): PASS when testing returning cost %d for Sea Hag.\n", getCost(sea_hag));
	else
		printf("getCost(): FAIL when testing returning cost %d for Sea Hag.\n", getCost(sea_hag));
	
	if(getCost(treasure_map) == 4)
		printf("getCost(): PASS when testing returning cost %d for Treasure Map.\n", getCost(treasure_map));
	else
		printf("getCost(): FAIL when testing returning cost %d for Treasure Map.\n", getCost(treasure_map));
	
	if(getCost(30) == -1)
		printf("getCost(): PASS when testing returning cost %d for wrong card name.\n", getCost(30));
	else
		printf("getCost(): FAIL when testing returning cost %d for wrong card name.\n", getCost(30));

	printf("\n----------End Testing getCost()----------\n");

}
int main(int argc, char *argv[])
{
    testGetCost();
    return 0;
}