#pragma once
#include "OffensiveUnit.h"
#include "MagicRock.h"
#include "Goblin.h"
#include <time.h>
#include <cstdlib>

class UnitsGenerator{
	short level;
	time_t timeForRandomGeneratingNumbers;

	static const int NUMBER_OF_OFFENSIVE_TYPES = 1;
	static const int NUMBER_OF_PASSIVE_TYPES = 1;
		
public:
	static int getRandomNumber(int min, int max);

	UnitsGenerator(short);
	UnitsGenerator(short,time_t);

	OffensiveUnit* generateOffensiveUnit();
	OffensiveUnit* generateOffensiveUnit(int);

	PassiveUnit* generatePassiveUnit();
	PassiveUnit* generatePassiveUnit(int);

	const int getLevel();
	void setLevel(short);
	void levelUp();

	UnitsGenerator& operator++();

	~UnitsGenerator();
};
