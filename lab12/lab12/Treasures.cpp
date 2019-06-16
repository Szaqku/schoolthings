#include "Treasures.h"
#include <algorithm>
#include <stdexcept>


Treasures::Treasures()
{
	treasures = std::list<Item*>();
}

Item* Treasures::findNextTreasure(Item* t)
{
	auto element = find(treasures.begin(), treasures.end(), t);
	if (element == treasures.end() || *element == *treasures.rbegin())
		throw std::exception("Treasure not found.");
	return *(++element);
}

void Treasures::addTreasure(Item* t)
{
	treasures.push_back(t);
}

void Treasures::deleteTreasure(Item* t)
{
	int size = treasures.size();
	treasures.remove(t);
	if (size == treasures.size())
		throw std::exception("Can't find given treasure.");
}

void Treasures::printListOfTreasures()
{
	for (auto t : treasures)
		std::cout << *t << std::endl;
}


Treasures::~Treasures()
{
	for (auto t : treasures)
		delete t;
}
