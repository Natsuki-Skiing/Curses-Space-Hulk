#include "weapon.h"

weapon::weapon(std::string name, int fireCost, int overWatchCost, int range, int killOn  , int noDice ) {
	/*@param string name, int fire cost , int overWatchCost , int range
	*/

	this->name = name;
	this->fireCost = fireCost;
	this->overWatchCost = overWatchCost;
	this->range = range;
	this->jammed = false;
	this->killOn = killOn;
	this->noDice = noDice;
}
weapon::weapon() {

}
int weapon::getKillOn() {
	return(this->killOn);
}

int weapon::getNoDice() {
	return(this->noDice);
}

std::string weapon::getName() {
	return(this->name);
}

int weapon::getRange() {
	return(this->range);
}

int weapon::getFireCost() {
	return(this->fireCost);
}

int weapon::getOverWatchCost() {
	return(this->overWatchCost);
}

bool weapon::isJammed() {
	return(this->jammed);
}

void weapon::setJammed(bool value) {
	this->jammed = value;
}