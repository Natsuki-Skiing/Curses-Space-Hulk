#include "draw.h"

void draw(WINDOW* window, tile Tile, int x, int y) {
	if (Tile.getColourPair() == -1) {
		mvwaddch(window, y, x, Tile.getChar());
	}
	else {
		wattron(window, COLOR_PAIR(Tile.getColourPair()));
		mvwaddch(window, y, x, Tile.getChar());
		wattroff(window, COLOR_PAIR(Tile.getColourPair()));
	}
	
}

void draw(WINDOW* window, tile * Tile, int x, int y) {
	if (Tile->getColourPair() == -1) {
		mvwaddch(window, y, x, Tile->getChar());
	}
	else {
		
		wattron(window, COLOR_PAIR(Tile->getColourPair()));
		mvwaddch(window, y, x, Tile->getChar());
		wattroff(window, COLOR_PAIR(Tile->getColourPair()));
	}
	
}

