#pragma once
#include "GameUnit.h"
#include "Player.h"

class Player;

class PassiveUnit :
	public GameUnit
{
public:
	PassiveUnit(std::string,int,short);

	virtual void receiveDamage(OffensiveUnit&) = 0;
	virtual void throwLoot(Player&) = 0;

	~PassiveUnit();
};

