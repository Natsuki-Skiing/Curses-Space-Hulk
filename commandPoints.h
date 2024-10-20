#pragma once
#include <random>
#include <time.h>
class commandPoints {
	private:
		int commandPoints;
	public:
		void reset();
		int getCommandPoints();
		bool subCommandPoints(int amount);
};