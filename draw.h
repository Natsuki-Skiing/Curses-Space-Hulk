#pragma once
#include <curses.h>
#include "tile.h"
void draw(WINDOW* window, tile  Tile, int x , int y );
void draw(WINDOW* window, tile* Tile, int x, int y);

