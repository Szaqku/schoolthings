#pragma once
#include "ItemObject.h"
class Chestplate :
	public ItemObject
{
public:
	Chestplate(std::string name);

	virtual int getArmor();
	virtual int getHp();
	virtual int getDamage();

	~Chestplate();
};

