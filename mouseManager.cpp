#include "mouseManager.h"


int mouseManager::getX() {
	return(Mouse_status.x);
}

int mouseManager::getY() {
	return(Mouse_status.y);
}

bool mouseManager::clickUpdate() {
	// Checking to see if the mouse has been pressed 
	if (getch() == KEY_MOUSE) {
		//Updating the mouse struct included in PD curses 
		request_mouse_pos();
		return(true);
		
	}
	else {
		return(false);
	}
}

void mouseManager::update() {
	
	
	request_mouse_pos();
	x = Mouse_status.x;
	y = Mouse_status.y;

	
	
}

bool mouseManager::overWindow(WINDOW* win) {


	int winX, winY, winH, winW;

	getbegyx(win, winY, winX);
	getmaxyx(win, winH, winW);

	if (Mouse_status.x >= winX && Mouse_status.x < (winX + winW) && Mouse_status.y >= winY && Mouse_status.y < (winY + winH)) {
		return(true);
	}
	else {
		return(false);
	}
		

}