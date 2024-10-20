#pragma once
#include <string>

class weapon {
	// Basic weapon class for the terminators
	protected:
		std::string name;
		int range;
		// Ap cost for fireing the gun
		int fireCost;
		//ap cose for using the gun in overwatch 
		int overWatchCost;
		bool jammed;
		int killOn;
		int noDice;
	public:
		weapon(std::string name, int fireCost, int overWatchCost, int range, int killOn, int noDice);
		weapon();
		std::string getName();
		int getRange();
		int getFireCost();
		int getOverWatchCost();
		// Returns true if jammed, false if not
		bool isJammed();
		void setJammed(bool);
		int getNoDice();
		int getKillOn();
};

