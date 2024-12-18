#include "terminatorController.h"

void terminatorController::addTerminator(terminator newTerm) {
	this->Terminators.push_back(newTerm);
	this->termMap.clear();
	for (int index = 0; index < Terminators.size(); index++) {
		this->termMap.insert({ toIndex(Terminators[index].getX(), Terminators[index].getY()), &this->Terminators[index]});
	}
	
	if (Terminators.size() == 1) {
		this->CurrentTerm = &Terminators[0];
	}
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

bool terminatorController::moveTerm(WINDOW * window,int x, int y, map * Map) {
	//i like having one exit functions when i can be bothered to do so, this is for that 
	//For now this is allways true because i havent made the map yet 
	bool canMove = true; 
	if ((Map->getTile(x + CurrentTerm->getX(), y + CurrentTerm->getY())->isWalkable())&&(isTermHere(x + CurrentTerm->getX(), y + CurrentTerm->getY()))) {
		canMove = false;
	}
	else if(canMove) {
		
		//int xDiff = std::abs(x - CurrentTerm->getX());
		//int yDiff = std::abs(y - CurrentTerm->getY());
		if (canMove) {
			// checking to see if theres enough ap to make the desired move
			if (CurrentTerm->apCheck((x + y))) {
				// Updating the unordered map 
				auto it = termMap.find(toIndex(CurrentTerm->getX(), CurrentTerm->getY()));
				terminator* tempPointer = it->second;

				termMap.erase(it);

				termMap[toIndex(x+ CurrentTerm->getX(), y+ CurrentTerm->getY())] = tempPointer;
				
				
				// reDrawing the previous map tile
				draw(window, CurrentTerm->getPreviousTile(), CurrentTerm->getX(), CurrentTerm->getY());

				//setting new previous tile
				this->CurrentTerm->setPreviousTile(Map->getTile(x + CurrentTerm->getX(), y + CurrentTerm->getY()));
				x += CurrentTerm->getX();
				y += CurrentTerm->getY();

				CurrentTerm->setX(x);
				CurrentTerm->setY(y);
				canMove = true;
			}
			else {
				canMove = false;
			}
		}
	}
	
	
	


	return(canMove);

}

void terminatorController::setCurrentTerm(terminator* Term) {
	this->CurrentTerm = Term; 
}

terminator* terminatorController::getCurrentTerm() {
	return(this->CurrentTerm);
}