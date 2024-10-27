#include "tile.h"



tile::tile(char character, int colPair) {
	this->character = character;
	this->colourPair = colPair;
	this->walkable = false;
}



tile::tile(char character, int colPair , bool walkable) {
	this->character = character;
	this->colourPair = colPair;
	this->walkable = walkable;
}
char tile::getChar() {
	return(this->character);
}

tile::tile(){}

int tile::getColourPair() {
	return(this->colourPair);
}

bool tile::isWalkable() {
	return(this->walkable);
}

void tile::setWalkable(bool value){
	this->walkable = value;
}