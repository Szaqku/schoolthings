#pragma once
#include "ItemObject.h"
class Spear :
	public ItemObject
{
public:
	Spear();
	Spear(std::string);

	virtual int getArmor();
	virtual int getHp();
	virtual int getDamage();

	~Spear();
};

