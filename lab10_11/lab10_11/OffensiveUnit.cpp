#include "OffensiveUnit.h"
#include "PassiveUnit.h"

OffensiveUnit::OffensiveUnit(std::string name, int hp, short level, int pureDamage) : GameUnit(name,hp,level), damage(pureDamage){}


int OffensiveUnit::getDamage()
{
	return damage;
}

OffensiveUnit::~OffensiveUnit(){}

std::ostream& operator<<(std::ostream& os, OffensiveUnit& unit)
{
	os <<  "Name:  " << unit.getObjectName() << " | "
		<< "Lv. "<< unit.getLevel() <<" | "
		<< "HP: " << unit.getHP() << " | "
		<< "Damage: " << unit.getDamage() << std::endl;
	return os;
}
