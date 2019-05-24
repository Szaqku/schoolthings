#pragma once
#include "OffensiveUnit.h"
#include "PassiveUnit.h"
#include "Chest.h"
#include "Chest.cpp"
#include "ItemGenerator.h"


class Player : public OffensiveUnit{
	friend std::ostream& operator<<(std::ostream&, Player&);

	Chest<ItemObject*>* backpack;

public:
	Player(std::string);

	void receiveDamage(OffensiveUnit&);
	void dealDamage(PassiveUnit&);
	void dealDamage(OffensiveUnit&);
	void getNewItem(ItemObject&);

	int getDamage();

	Chest<ItemObject*>* getBackpack();

	const int getHP();
	const int getArmor();

	void levelUp();

	~Player();
};

