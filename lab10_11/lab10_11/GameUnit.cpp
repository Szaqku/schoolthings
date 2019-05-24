#include "GameUnit.h"

GameUnit::GameUnit(std::string name, int hp, short level) : objectName(name), level(level), hp(hp){}

const int GameUnit::getHP()
{
	return hp;
}

const std::string GameUnit::getObjectName()
{
	return objectName;
}

const short GameUnit::getLevel()
{
	return level;
}

void GameUnit::levelUp()
{
	level++;
}

GameUnit::~GameUnit()
{
	std::cout << this->getObjectName() << " has been slain." << std::endl;
}

std::ostream& operator<<(std::ostream& os, GameUnit& object)
{
	return os << object.getObjectName() <<" | lv. "<< object.getLevel() << " | HP: " << object.getHP() << std::endl;
}
