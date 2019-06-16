#pragma once
#include "Item.h"
#include <string>

class Note :
	public Item
{
	std::string information;
public:
	Note();
	Note(std::string name, std::string information);
	Note(std::string name, std::string information, std::string whereToFind);
	virtual std::string getInfo();
	virtual ~Note();
};

