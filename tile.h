#pragma once
#include <string>
#include "tile.h"

class tile {
	protected:
		
		char character;
		std::string colour;
		int colourPair;
	public:
		std::string getColour();
		char getChar();
		int getColourPair();
		tile(char character, std::string colour);
		tile(char character, int colPair);

};