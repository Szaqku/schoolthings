#include "Spear.h"

Spear::Spear() : Spear("Willy"){}

Spear::Spear(std::string name) : ItemObject(name+"'s spear",0,70,10){}

int Spear::getArmor()
{
	return armor;
}

int Spear::getHp()
{
	return hp;
}

int Spear::getDamage()
{
	return 1.15*damage;
}


Spear::~Spear()
{
}
