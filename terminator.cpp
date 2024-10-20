#include "Terminator.h"

terminator::terminator(int x, int y, std::string name, int AP, weapon Weapon) {
	this->x = x;
	this->y = y;
	this->name = name;
	this->AP = AP;
	this->Weapon = Weapon;
}

int terminator::getX() {
	return(this->x);
}

int terminator::getY() {
	return(this->y);
}
std::string terminator::getName() {
	return(this->name);
}

int terminator::getAp() {
	return(this->AP);
}

weapon* terminator::getWeapon() {
	return(&Weapon);
}

void terminator::setWeapon(weapon newWep) {
	this->Weapon = newWep;
}

void terminator::setAp(int AP) {
	this->AP = AP;
}

void terminator::setX(int x) {
	this->x = x;
}

void terminator::setY(int y) {
	this->y = y;
}

void terminator::setName(std::string name) {
	this->name = name;
}

tile terminator::getTile() {
	return(this->Char);
}

bool terminator::apCheck(int amount) {
	if (AP - amount >= 0) {
		this->AP -= amount;
		return(true);
	}
	else if (CP.subCommandPoints(amount - AP)){
		return(true);

	}
	else {
		return(false);
	}
}