#pragma once
#include "OffensiveUnit.h"
class Goblin :
	public OffensiveUnit
{
public:
	Goblin();
	Goblin(std::string);

	Goblin(std::string name, short level);

	virtual void receiveDamage(OffensiveUnit& enemy);
	virtual void dealDamage(PassiveUnit&);
	virtual void dealDamage(OffensiveUnit&);
	virtual int getDamage();

	virtual ~Goblin();
};

