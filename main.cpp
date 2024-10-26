#include <string>
#include "Terminator.h"
#include "weapon.h"
#include "weapons_global.h"
#include <curses.h>
#include <vector>
#include "mainMenu.h"
#include <iostream>
#include "terminatorController.h"
#include "draw.h"

#include "mouseManager.h"

#include "globalCommandPoints.h"
#include "button.h"
#pragma warning(suppress : 6387)

commandPoints CP;

int main() {

	terminatorController TC;

	std::vector<terminator> terminators;
	terminators.emplace_back(20, 20, "Test Terminator", 4, StormBolter);
	terminator TestTerm(10, 10, "Test Terminator", 4, StormBolter);
	TC.addTerminator(terminators[0]);
	//mainMenu();
	initscr();
	noecho();
	cbreak();
	start_color();
	// Allows for special keys, mainly using it for mouse input 
	keypad(stdscr, TRUE);
	/*mousemask(ALL_MOUSE_EVENTS, NULL);*/
	mouse_set(ALL_MOUSE_EVENTS);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	           // Move to the specified coordinates

	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	

	
	
	refresh();
	//I want a nice big terminal for the game 
	resize_term(100, 150);
	/*this is the main window where the graphics of the game will be drawn and the user will intereact with the terminators/ genestealers*/
	WINDOW* winMain = newwin(50, 100, 0, 0);
	wrefresh(winMain);
	//This is how the player controls the terminator
	WINDOW* winButton = newwin(10, 100, 51, 0);
	// Will show the terminators stats, such  as ap 
	WINDOW* winInfo = newwin(50, 30, 0, 101);
	box(winButton, 0, 0);
	box(winMain, 0, 0);
	box(winInfo, 0, 0);
	draw(winMain, TestTerm.getTile(), TestTerm.getX(), TestTerm.getY());
	wrefresh(winMain);
	wrefresh(winButton);
	wrefresh(winInfo);

	mvwaddch(winMain,20,20,'|');
	mvwaddch(winMain, 19, 21, '_');
	mvwaddch(winMain, 19, 22, '_');
	mvwaddch(winMain, 19, 23, '_');
	mvwaddch(winMain, 22, 21, '_');
	mvwaddch(winMain, 22, 22, '_');
	mvwaddch(winMain, 22, 23, '_'); 
	mvwaddch(winMain, 21, 20, '|');
	mvwaddch(winMain, 22, 20, '|');
	wrefresh(winMain);


	mouseManager MouseM;
	draw(winMain, TestTerm.getTile(), TC.getTerm(0)->getX(), TC.getTerm(0)->getY());
	wrefresh(winMain);

	button BtnForward("Forward", 5, 5,winButton);

	mvwprintw(winButton, BtnForward.getY(), BtnForward.getX(), BtnForward.getText());
	
	wrefresh(winButton);
	while (1) {
		
		
		if (MouseM.clickUpdate()&& MouseM.overWindow(winButton)) {
			int x, y;
			wmouse_position(winButton, &x, &y);
			if (BtnForward.isClicked(x,y)) {
				BtnForward.clicked();
				if (TC.moveTerm(winMain, 2, 0)) {
					
					draw(winMain, TC.getCurrentTerm()->getTile(), TC.getCurrentTerm()->getX(), TC.getCurrentTerm()->getY());
					wrefresh(winMain);
				}
			}
			wrefresh(winButton);
		}


		if (MouseM.clickUpdate() && TC.isTermHere(MouseM.getX(), MouseM.getY())) {
			TC.setCurrentTerm(TC.getTerm(MouseM.getX(), MouseM.getY())) ;			
		}
		
		
	};
	/*while (true) {
		c = getch();
		if (c == KEY_MOUSE) {
			request_mouse_pos();
			if (Mouse_status.x = 20 && Mouse_status.y == 20) {
				mvaddch(20, 20, ' ');
				refresh();
			}
			
			
			
			
		}
	}*/

	endwin();
	return(0);
}