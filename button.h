#pragma once
#include <string>
#pragma warning(disable: 4996)
#include<curses.h>
#include<thread>
class button {
	private:
		int x;
		int y;
		char text[10];
		int textLength;
		
		WINDOW* win;
		void clickAnimation();
	public:
		char* getText();
		bool isClicked(int x, int y);
		button(std::string text, int x, int y,WINDOW *  win);
		int getX();
		int getY();
		void showButton();
		void clicked();
		
};