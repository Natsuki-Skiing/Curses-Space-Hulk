#pragma once
#include "tile.h"
#include <vector>
#include <curses.h>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "draw.h"
class map {
	private:
		std::vector<std::vector<tile>> Map;
		//Stores all the tiles of the map
		std::unordered_map<char, tile> Tiles;
		int x; 
		int y;

	public:
		map(std::string mapFile, int x, int y);
		tile* getTile(int x, int y);
		int setTileXY(int x, int y, tile newTile);
		void displayMap(WINDOW* winToDraw);

};