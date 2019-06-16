#pragma once
#include <list>
#include "Item.h"
class Treasures
{
	std::list<Item*> treasures;
public:
	Treasures();

	Item* findNextTreasure(Item*) noexcept(false);
	void addTreasure(Item*);
	void deleteTreasure(Item*) noexcept(false);
	void printListOfTreasures();

	~Treasures();
};

