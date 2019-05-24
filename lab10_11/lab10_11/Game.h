#pragma once
#include "UnitsGenerator.h"
#include <queue>
#include <time.h>

class Game
{
	Player* player;
	UnitsGenerator* unitsGenerator;
	std::queue<GameUnit*>* nextGameUnits;
	int numberOfKilledMonsters;
	int level;

	int getRandomNumber();
public:
	Game();
	Game(Player*);

	void generateNewMonster();
	void generateNewLevel();

	void welcomeEvent();
	void startGame();
	void gameOverEvent();

	void destroyUnit(GameUnit&);

	Player* getPlayer();

	~Game();
};

