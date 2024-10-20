#include "draw.h"

void draw(WINDOW* window, tile Tile, int x, int y) {
	
	wattron(window,COLOR_PAIR(Tile.getColourPair()));
	mvwaddch(window,y, x, Tile.getChar());
	wattroff(window, COLOR_PAIR(Tile.getColourPair()));
}

