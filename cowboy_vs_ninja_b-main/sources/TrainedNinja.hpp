#include <iostream>
using namespace std;
#include "Ninja.hpp"
#ifndef TRANIEDNINJA_H
#define TRANIEDNINJA_H
constexpr int HITPOINTTRAINED = 120;
constexpr int SPEEDTRAINED = 12;
namespace ariel
{
	class TrainedNinja: public Ninja {
		public:
			// constructor, YoungNinja inherits from Ninja and gets all the parameters of Ninja and is set to 12 speed and 120 hit points.
			TrainedNinja(std::string nameC,Point placeC): Ninja(placeC, HITPOINTTRAINED, nameC,SPEEDTRAINED){ }
	};
}
#endif