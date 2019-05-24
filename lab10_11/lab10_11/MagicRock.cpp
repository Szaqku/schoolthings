#include "MagicRock.h"
#include "Spear.h"
#include "ItemGenerator.h"
#include "UnitsGenerator.h"

MagicRock::MagicRock(short level) : PassiveUnit("Magic Rock", 1200+49*level, level){}

void MagicRock::receiveDamage(OffensiveUnit& enemy){
	this->hp -= enemy.getDamage();
	if (this->hp <= 0) {
		if(Player* p = dynamic_cast<Player*>(&enemy))
			throwLoot(*p);
	}
}

void MagicRock::throwLoot(Player& player){
	ItemObject* io = ItemGenerator::generateRandomItem();
	if(UnitsGenerator::getRandomNumber(0,100) > 20)
		player.getNewItem(*io);
}

MagicRock::~MagicRock()
{
}
