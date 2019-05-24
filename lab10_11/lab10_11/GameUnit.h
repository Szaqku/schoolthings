#pragma once

#include <iostream>
#include <string>

class GameUnit
{
	friend std::ostream& operator<<(std::ostream&, GameUnit&);

	std::string objectName;
	short level;

protected:
	int hp;

public:
	GameUnit(std::string,int,short);

	virtual const int getHP();
	const std::string getObjectName();
	const short getLevel();
	virtual void levelUp();

	virtual ~GameUnit();
};

