#pragma once
#include "Terminator.h"
#include <unordered_map>
#include <vector>
#include<string>
#include <curses.h>
#include <cstdlib>
#include "map.h"
class terminatorController {
	private:
		std::vector<terminator>  Terminators;
		//Used to check if a terminator has been clicked
		std::unordered_map<int, terminator*> termMap;
		//Convet postion of a terminator to a key for the terminator map 
		int toIndex(int, int);
		terminator* CurrentTerm;
	public:
		void addTerminator(terminator);
		terminator* getTerm(int x, int y);
		bool isTermHere(int x, int y);
		void removeTerm(int index);// Not sure if this is the way i want to do this
		terminator* getTerm(int index);// Getiing the terminator streight from the vector without using the map 
		//Move a terminator, checks to see if blocked 
		bool moveTerm(WINDOW *,int x, int y,map * Map);
		terminator* getCurrentTerm();
		void setCurrentTerm(terminator *);
		
};