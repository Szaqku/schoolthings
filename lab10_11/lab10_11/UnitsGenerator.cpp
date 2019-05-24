#include "UnitsGenerator.h"

int UnitsGenerator::getRandomNumber(int min, int max)
{
	return (rand()%(max+1))+min;
}

UnitsGenerator::UnitsGenerator(short level): UnitsGenerator(level, time(NULL)){}

UnitsGenerator::UnitsGenerator(short level, time_t rdt): level(level), timeForRandomGeneratingNumbers(rdt){
	std::srand(timeForRandomGeneratingNumbers);
}

OffensiveUnit* UnitsGenerator::generateOffensiveUnit()
{
	int i = getRandomNumber(0,10);
	return generateOffensiveUnit(i);
}

OffensiveUnit* UnitsGenerator::generateOffensiveUnit(int i)
{
	i %= NUMBER_OF_OFFENSIVE_TYPES;
	switch (i) {
		default: return new Goblin("",level);
	}
}

PassiveUnit* UnitsGenerator::generatePassiveUnit()
{
	int i = getRandomNumber(0, 10);
	return generatePassiveUnit(i);
}

PassiveUnit* UnitsGenerator::generatePassiveUnit(int i)
{
	i %= NUMBER_OF_PASSIVE_TYPES;
	switch (i) {
		default: return new MagicRock(level);
	}
}

const int UnitsGenerator::getLevel()
{
	return level;
}

void UnitsGenerator::setLevel(short level){
	this->level = level;
}

void UnitsGenerator::levelUp()
{
	level++;
}

UnitsGenerator& UnitsGenerator::operator++()
{
	this->level++;
	return *this;
}

UnitsGenerator::~UnitsGenerator()
{
	
}
