#include "Goblin.h"
#include "Game.h"

Goblin::Goblin() : Goblin(""){}

Goblin::Goblin(std::string name) : OffensiveUnit("Goblin "+name,200,1,10){}
Goblin::Goblin(std::string name,short level) : OffensiveUnit("Goblin "+name,200+10*level,level,10+level*3.7){}

void Goblin::receiveDamage(OffensiveUnit& enemy){
	hp = hp - enemy.getDamage();
}

void Goblin::dealDamage(PassiveUnit&){}

void Goblin::dealDamage(OffensiveUnit& enemy){
	enemy.receiveDamage(*this);
}

int Goblin::getDamage()
{
	return damage;
}

Goblin::~Goblin(){}
