#pragma once
#include <curses.h>
class mouseManager {
	public:
		int x;
		int y;
		int getX();
		int getY();
		bool clickUpdate();

		void update();
		bool overWindow(WINDOW* win);

};