#pragma once
#include <string>
#include "weapon.h"
#include "weapons_global.h"
#include "tile.h"
#include "globalCommandPoints.h"
class terminator {
	protected:
		int x;
		int y;
		std::string name;
		int AP;
		weapon Weapon;
		tile Char{ 'T', 1 };

	public:
		terminator(int x, int y, std::string name, int AP, weapon Weapon);
		int getX();
		int getY();
		std::string getName();
		int getAp();

		weapon* getWeapon();

		void setWeapon(weapon newWep);
		void setAp(int AP);
		void setX(int x);
		void setY(int y);
		void setName(std::string name);

		tile getTile();
		// Checks the ap cost of an action, if can be made subtracts the cost 
		bool apCheck(int cost);
	




};
	
