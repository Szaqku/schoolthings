#pragma once
#include "ItemObject.h"
class Sword :
	public ItemObject
{
public:
	Sword();
	Sword(std::string name, int damage);
	int getDamage();
	int getArmor();
	int getHp();
	~Sword();
};

