#include <iostream>
using namespace std;
#include "Ninja.hpp"
#ifndef OLDNINJA_H
#define OLDNINJA_H
constexpr int HITPOINTOLD = 150;
constexpr int SPEEDOLD = 8;
namespace ariel
{
	class OldNinja: public Ninja {
		public:
		// constructor, OldNinja inherits from Ninja and gets all the parameters of Ninja and is set to 8 speed and 150 hit points.
			OldNinja(std::string nameC,Point placeC): Ninja(placeC, HITPOINTOLD, nameC,SPEEDOLD){ }
	};
}
#endif





