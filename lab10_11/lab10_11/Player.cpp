#include "Player.h"


Player::Player(std::string name) : OffensiveUnit(name,500,1,25), backpack(new Chest<ItemObject*>(3)){}

void Player::receiveDamage(OffensiveUnit& enemy){
	int damageDone = ((1-(getArmor() / 300)) * enemy.getDamage());
	this->hp -= damageDone;
}

void Player::dealDamage(PassiveUnit& enemy)
{
	enemy.receiveDamage(*this);
}

void Player::dealDamage(OffensiveUnit& enemy)
{
	enemy.receiveDamage(*this);
}

void Player::getNewItem(ItemObject& item)
{
	bool wantToPickUpItem = 0;
	std::cout << "You've found new item: " << item << "\nWould you like to pick it up ? [Choose between 0 or 1]" << std::endl;
	std::cin >> wantToPickUpItem;
	if (wantToPickUpItem != 0) {
		if (!backpack->isFull()) {
			backpack->addItem(&item);
			this->hp += item.getHp();
		}
		else {
			std::cout << "Choose item to throw away: (by choosing number ofc.)" << std::endl;
			for (int i = 0; i < backpack->getNumberOfItems(); i++)
				std::cout << i << ". " << *backpack->getItem(i) << std::endl;
			int indexOfItem;
			std::cin >> indexOfItem;
			try {
				ItemObject* io = backpack->getItem(indexOfItem);
				backpack->throwAwayItem(indexOfItem);
				this->hp -= (hp > io->getHp()) ? io->getHp() : 0.4*io->getHp();
				backpack->addItem(&item);
				this->hp += item.getHp();
			}
			catch (...) {
				//std::cout << ex.what() << std::endl;
				std::cout << "Wrong number, nvm." << std::endl;
			}
		}
	}
}

int Player::getDamage()
{
	int damage = this->damage;
	for (auto item : backpack->getListOfItems())
		damage += item->getDamage();

	return damage;
}

Chest<ItemObject*>* Player::getBackpack()
{
	return backpack;
}

const int Player::getHP() {
	return hp;
}

const int Player::getArmor()
{
	int armor = 0;
	for (auto& item : backpack->getListOfItems())
		armor += item->getArmor();

	return armor;
}

void Player::levelUp()
{
	OffensiveUnit::levelUp();
	this->hp += getLevel()*20;
	this->damage += 15;
}

Player::~Player() {
	delete backpack;
}

std::ostream& operator<<(std::ostream& os, Player& unit)
{
		os << "Name:  " << unit.getObjectName() << " | "
			<< "Lv. " << unit.getLevel() << " | "
			<< "HP: " << unit.getHP() << " | "
			<< "Armor: " << unit.getArmor() << " | "
			<< "Damage: " << unit.getDamage() << std::endl;
		return os;
}
