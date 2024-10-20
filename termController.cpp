#include "terminatorController.h"

void terminatorController::addTerminator(terminator newTerm) {
	this->Terminators.push_back(newTerm);
	this->termMap.insert({ toIndex(newTerm.getX(), newTerm.getY()), &this->Terminators.back()});
}


bool terminatorController::isTermHere(int x, int y) {
	if (this->termMap.find(toIndex(x, y)) == termMap.end()) {
		return(false);
	}else {
		return(true);
	}
}

terminator* terminatorController::getTerm(int index) {
	return(&this->Terminators[index]);
}

terminator* terminatorController::getTerm(int x, int y) {
	return(this->termMap.at(toIndex(x, y)));
}


void terminatorController::removeTerm(int index) {
	
	this->termMap.erase((toIndex(this->Terminators[index].getX(), this->Terminators[index].getY())));
	this->Terminators.erase(std::next(this->Terminators.begin(), index));
	
}

int terminatorController::toIndex(int x, int y) {
	// I think this is really slow but eh one line solution
	return(std::stoi((std::to_string(x) + std::to_string(y))));
}

bool terminatorController::moveTerm(WINDOW * window,int x, int y) {
	//i like having one exit functions when i can be bothered to do so, this is for that 
	//For now this is allways true because i havent made the map yet 
	bool canMove = true; 
	

	int xDiff = std::abs(x - CurrentTerm->getX());
	int yDiff =-std::abs(y - CurrentTerm->getY());
	if (canMove) {
		// checking to see if theres enough ap to make the desired move
		if (CurrentTerm->apCheck((xDiff + yDiff))) {
			// Updating the unordered map 
			auto it = termMap.find(toIndex(CurrentTerm->getX(), CurrentTerm->getY()));
			terminator * tempPointer = it->second;

			termMap.erase(it);

			termMap[toIndex(x, y)] = tempPointer;
			canMove = true;
		}
		else {
			canMove = false;
		}
	}
	


	return(canMove);

}