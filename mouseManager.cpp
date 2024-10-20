#include "mouseManager.h"


int mouseManager::getX() {
	return(Mouse_status.x);
}

int mouseManager::getY() {
	return(Mouse_status.y);
}

bool mouseManager::update() {
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
