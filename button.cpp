#include "button.h"


button::button(std::string text,int x,int y,WINDOW * win) {
	this->textLength = text.length() ;
	std::strcpy(this->text , text.c_str());
	this->x = x;
	this->y = y;
	this->win = win;
}


char* button::getText() {
	return(this->text);
}

bool button::isClicked(int x, int y) {
	return(x >= this->x && x <= this->x + this->textLength && y >= this->y && y <= this->y + 3);
}

int button::getX() {
	return(this->x);
}


int button::getY() {
	return(this->y);
}


void button::showButton() {
	mvwprintw(win, y, x, text);
}

void button::clicked() {
	std::thread AniThread(&button::clickAnimation,this);
	AniThread.join();
}
void button::clickAnimation() {
	wattron(win, A_REVERSE);
	showButton();
	wattroff(win, A_REVERSE);
	wrefresh(win);

	//This is temporary just so the button shows as clicked during testing 
	for (int i = 0; i < 99999999; i++);//Might just keep it who cares 

	showButton();
	wrefresh(win);
}