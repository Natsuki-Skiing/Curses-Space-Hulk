#include "tile.h"

tile::tile(char character,std::string colour) {
	this->character = character;
	this->colour = "COLOR_"+colour;
}

tile::tile(char character, int colPair) {
	this->character = character;
	this->colourPair = colPair;
}
char tile::getChar() {
	return(this->character);
}

std::string tile::getColour() {
	return(this->colour);
}

int tile::getColourPair() {
	return(this->colourPair);
}