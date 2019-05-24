#include "Chestplate.h"

Chestplate::Chestplate(std::string name) : ItemObject(name+" Chestplate",50,0,100){}

int Chestplate::getArmor()
{
	return 1.8*armor;
}

int Chestplate::getHp()
{
	return hp*1.1;
}

int Chestplate::getDamage()
{
	return damage;
}


Chestplate::~Chestplate()
{
}
