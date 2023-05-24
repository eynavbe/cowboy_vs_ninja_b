#include <iostream>
using namespace std;
#include "Character.hpp"
#ifndef NINJA_H
#define NINJA_H
namespace ariel
{
	class Ninja: public Character {
		private:
			int speed;
		public:

			// Constructor with all character parameters and speed (integer)
			Ninja(Point  placeC, int hitPointC, std::string nameC, int speedC): Character(placeC, hitPointC, nameC), speed(speedC){ }	
			
			operator string() const {             
					return std::to_string(speed) + "," + string(getLocation()) + "," + std::to_string(getHitPoint()) + "," + getName();
			}

			// return the speed of the Ninja.
			int getSpeed() const {
				return speed;
			}

			// Returns the type of the character when Ninja is "N"
			std::string getType() const  {
				return "N";
			}

			// move receives a pointer to the enemy and moves towards the enemy. The ninja advances a distance equal to its speed.
			void move(Character *enemy);

			// Returns a boolean if the ninja is less than 1 meter away from the enemy
			bool close(Character *enemy)const;

			// slash() receives a pointer to the enemy. If the ninja is alive and the enemy is less than 1 meter away, the ninja will deal 40 damage to the enemy. Otherwise, no damage will be done to the enemy.
			void slash(Character *enemy)const;
			
	};
}
#endif






