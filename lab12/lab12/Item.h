#pragma once
#include <string>
#include <iostream>

class Item
{
	friend std::ostream& operator<<(std::ostream&, Item&);

	std::string name;
	int id;
	std::string placeWhereCanBeFound;

	static unsigned nextUniqueID;
public:

	Item();
	Item(std::string);
	Item(std::string, std::string);

	const int& getID();
	const std::string& getName();
	virtual std::string getInfo() = 0;

	virtual ~Item();
};

