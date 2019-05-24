#pragma once
#include "GameUnit.h"
#include <iostream>

class PassiveUnit;

class OffensiveUnit :
	public GameUnit
{
	friend std::ostream& operator<<(std::ostream&, OffensiveUnit&);

protected:
	int damage;
public:
	OffensiveUnit(std::string, int, short, int);

	virtual void receiveDamage(OffensiveUnit&) = 0;
	virtual void dealDamage(PassiveUnit&) = 0;
	virtual void dealDamage(OffensiveUnit&) = 0;
	virtual int getDamage() = 0;

	virtual ~OffensiveUnit();
};

