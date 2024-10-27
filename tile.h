#pragma once
#include <string>
#include "tile.h"

class tile {
	protected:
		
		char character;

		int colourPair;
		bool walkable;
	public:
		tile();
		char getChar();
		int getColourPair();
		tile(char character, int colPair, bool walkable);
		tile(char character, int colPair);
		bool isWalkable();
		void setWalkable(bool value);
		
};