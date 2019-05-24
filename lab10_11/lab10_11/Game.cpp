#include "Game.h"

int Game::getRandomNumber()
{
	return unitsGenerator->getRandomNumber(1,10);
}

Game::Game(): Game(new Player("RandomNick")){}

Game::Game(Player* player) {
	this->unitsGenerator = new UnitsGenerator(1);
	this->nextGameUnits = new std::queue<GameUnit*>();
	this->player = player;
	numberOfKilledMonsters = 0;
	level = 1;
}

void Game::generateNewMonster()
{
	int i = getRandomNumber();
	if (i % 2 == 0)
		nextGameUnits->push(unitsGenerator->generateOffensiveUnit());
	else
		nextGameUnits->push(unitsGenerator->generatePassiveUnit());
}

void Game::generateNewLevel(){
	while (nextGameUnits->size())
		nextGameUnits->pop();
	for (int i = getRandomNumber(); i > 0; i--)
		generateNewMonster();
}

void Game::welcomeEvent(){
	std::cout << "Game is about to begin. " << std::endl;
}


void Game::startGame(){
	while (true) {
		generateNewLevel();
		std::cout << "Level: " << level << std::endl;
		while (nextGameUnits->size()) {
			GameUnit* unit = nextGameUnits->front();
			nextGameUnits->pop();
			while (unit->getHP() > 0 && player->getHP() > 0) {
				std::cout << "----------------------------------------------------------" << std::endl;
				std::cout << "Player : "<<*player;
				std::cout << "Enemy  : ";
				if (OffensiveUnit * of = dynamic_cast<OffensiveUnit*>(unit)) {
					of->receiveDamage(*player);
					player->receiveDamage(*of);
					std::cout << *of;
				}
				else if (PassiveUnit * pa = dynamic_cast<PassiveUnit*>(unit)) {
					pa->receiveDamage(*player);
					std::cout << *pa;
				}
				std::cout << "After: " << *player;
				std::cout << "----------------------------------------------------------" << std::endl;
			}
			if (player->getHP() <= 0) {
				this->gameOverEvent();
				return;
			}
			else {
				numberOfKilledMonsters++;
				if (unit != NULL)
					destroyUnit(*unit);
			}
		}
		player->levelUp();
		this->unitsGenerator->levelUp();
		level++;
	}
}

void Game::gameOverEvent(){
	std::cout << "===================================================== " << std::endl
			  << "                       GAME OVER                      " << std::endl
			  << "===================================================== " << std::endl
			  << " Killed Monsters: "      << numberOfKilledMonsters << std::endl
			  << " Level achieved:   "      << level << std::endl
		      << "----------------------------------------------------- " << std::endl
		      << " Equipment collected   " << std::endl;
	for (const auto& item : player->getBackpack()->getListOfItems())
		std::cout <<" "<< *item << std::endl;
	std::cout << "===================================================== " << std::endl;
}

void Game::destroyUnit(GameUnit& unit){
	delete &unit;
}

Player* Game::getPlayer()
{
	return player;
}

Game::~Game(){
	delete player;
	std::cout << "Clearing game data" << std::endl;
	delete unitsGenerator;
	while (nextGameUnits->size()) {
		GameUnit* unit = nextGameUnits->front();
		nextGameUnits->pop();
		delete unit;
	}
}
