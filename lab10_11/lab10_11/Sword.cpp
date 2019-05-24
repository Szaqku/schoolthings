#include "Sword.h"

Sword::Sword() : ItemObject("Sword", 0, 15, 0){}
Sword::Sword(std::string name, int damage) : ItemObject("Sword of "+name, 0, damage, 0){}

int Sword::getDamage()
{
	return 1.3*damage;
}

int Sword::getArmor()
{
	return 0;
}

int Sword::getHp()
{
	return 0;
}

Sword::~Sword()
{
}
