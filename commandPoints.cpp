#include "commandPoints.h"


int commandPoints::getCommandPoints() {
	return(this->commandPoints);
}

void commandPoints::reset() {
	std::srand(std::time(nullptr));
	this->commandPoints = std::rand() % 7 ;

}

bool commandPoints::subCommandPoints(int amount) {
	if (commandPoints - amount >= 0) {
		this->commandPoints - amount;
		return(true);
	}
	else {
		return(false);
	}
}
