#include "ItemGenerator.h"

int ItemGenerator::getRandomNumber()
{
	std::srand(time(NULL));
	return rand()%NUMBER_OF_ITEMS;
}

ItemObject* ItemGenerator::generateRandomItem()
{
	int i = getRandomNumber();
	switch (i) {
	case 0: return new Chestplate("Silver");
	case 1: return new Spear("Silver"); 
	case 2: return new Sword();
	default: return new Chestplate("Wooden");
	}
}
