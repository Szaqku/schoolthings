#pragma once
#include "PassiveUnit.h"
#include "Player.h"

class MagicRock :
	public PassiveUnit
{
public:
	MagicRock(short);

	void receiveDamage(OffensiveUnit&);
	void throwLoot(Player&);

	~MagicRock();
};

