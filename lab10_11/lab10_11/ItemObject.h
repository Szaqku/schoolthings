#pragma once
#include <string>
#include <iostream>

namespace Item{
	enum ATTRIBUTES { DAMAGE, HP, ARMOR };
}
class ItemObject{
	friend std::ostream& operator<<(std::ostream&, ItemObject&);

	std::string name;

protected:
	int damage;
	int hp;
	int armor;

public:
	ItemObject(std::string);
	ItemObject(std::string,int,int,int);

	const std::string& getName();

	virtual int getArmor() = 0;
	virtual int getHp() = 0;
	virtual int getDamage() = 0;

	virtual ~ItemObject();
};

