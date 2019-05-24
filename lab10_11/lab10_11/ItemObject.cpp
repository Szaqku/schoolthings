#include "ItemObject.h"

ItemObject::ItemObject(std::string name) :  ItemObject(name,0,0,0){}

ItemObject::ItemObject(std::string name, int armor, int damage, int hp) : name(name), armor(armor), damage(damage), hp(hp){}

const std::string& ItemObject::getName()
{
	return this->name;
}

ItemObject::~ItemObject()
{
	std::cout << "Item: " + this->name + " destroyed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, ItemObject& item)
{
	os << "Name: " << item.getName()<<" ";
	if (item.getArmor() != 0)
		os << "| ARMOR: " << item.getArmor();
	if (item.getDamage() != 0)
		os << "| DMG: " << item.getDamage();
	if (item.getHp() != 0)
		os << "| HP: " << item.getHp();
	return os;
}
