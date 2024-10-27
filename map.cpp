#include "map.h"


map::map(std::string mapFile, int x, int y) {
	this->x = x;
	this->y = y;


	// Creating the tiles for the map 
	Tiles.emplace('_', tile('_', -1, false));
	Tiles.emplace( ';', tile(';', 3, true) );
	Tiles.emplace( '|', tile('|', -1, false) );
	Tiles.emplace( '+', tile('+', -1, false) );
	Tiles.emplace( ':', tile(':', 1, false) );
	Tiles.emplace('#', tile('#', 1, false));
	Tiles.emplace('.', tile(':', 4, true));
	

	// Blank tile
	Tiles.emplace( 'B',tile('B',-1,false));
	

	//Just some junk for file access
	std::string fileName = mapFile + ".txt";
	std::string line;
	std::ifstream infile(fileName);
	

	//populating the map vvector with tile objects 
	while (std::getline(infile, line)) {
		std::vector<tile> row;
		for (char& c : line) {
			if (c == 32) {
				//blank tile
				row.push_back(Tiles['B']);
			}
			else {
				//Getting the corrisponding tile form the unordered tile map 
				row.push_back(Tiles[c]);

			}
			

		}
		//adding to map 
		this->Map.push_back(row);
	}
}


void map::displayMap(WINDOW* win) {
	for (int x = 0; x < Map.size(); ++x) { // Iterate over rows
		for (int y = 0; y < Map[x].size(); ++y) { // Iterate over columns
			if (Map[x][y].getChar() == 'B') {
				continue;
			}
			tile *  temp = &Map[x][y];
			draw(win, temp, y, x); // Accessing element at row i, column j
		}
	}
}


tile* map::getTile(int x, int y) {
	return(&this->Map[x][y]);
}

int map::setTileXY(int x ,int y, tile NewTile) {
	this->Map[x][y] = NewTile;
}