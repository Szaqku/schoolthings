#pragma once

#include "Spear.h"
#include "Sword.h"
#include "Chestplate.h"
#include <time.h>
#include <cstdlib>

class ItemGenerator
{
public:
	const static int NUMBER_OF_ITEMS = 3;
	static int getRandomNumber();
	static ItemObject* generateRandomItem();
};

