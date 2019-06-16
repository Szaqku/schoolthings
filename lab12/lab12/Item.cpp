#include "Item.h"


unsigned Item::nextUniqueID = 0;

Item::Item() : Item("Item "+nextUniqueID){}
Item::Item(std::string name) : Item(name,"World"){}
Item::Item(std::string name, std::string whereToFind){
	this->name = name;
	this->id = nextUniqueID++;
	this->placeWhereCanBeFound = whereToFind;
}

const int& Item::getID()
{
	return id;
}

const std::string& Item::getName()
{
	return name;
}

Item::~Item(){}

std::ostream& operator<<(std::ostream& os, Item& item)
{
	return os << "ID: "<<item.id << ", name: " << item.name <<", location where can be found: "<< item.placeWhereCanBeFound << "\n" << item.getInfo();
}
