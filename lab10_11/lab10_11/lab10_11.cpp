#include <iostream>
#include "Game.h"
#include <string>

using namespace std;

int main(){
	Game* game = new Game(new Player("NickName"));

	game->startGame();
	delete game;
}
