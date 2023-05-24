#include <iostream>
using namespace std;
#include "Character.hpp"
#ifndef COWBAY_H
#define COWBAY_H
namespace ariel
{
	class Cowboy: public Character {
		private:
			int amountBalls;

		public:
			// Constructor with all the parameters of a character and also "amount of bullets" (whole number) Booker is always created with six bullets and 110 hit points.
			Cowboy(std::string nameC, Point  placeC): Character(placeC, 110, nameC), amountBalls(6){ }
			
			operator string() const {             
					return std::to_string(amountBalls) + "," + string(getLocation()) + "," + std::to_string(getHitPoint()) + "," + getName();
			}

			// return the amount balls of the cowboy.
			int getAmountBalls() const {
				return amountBalls;
			}

			// Returns the type of the character when cowboy is "C"
			std::string getType() const  override{
				return "C";
			}

			// set the amount balls of the cowboy.
			void setAmountBalls(int amountBalls2);

			// shoot gets a pointer to the enemy. If the morning is not dead and has bullets left, the morning shoots the enemy, subtracting 10 hit points from the enemy - and losing 1 bullet. Otherwise, no damage will be done to the enemy.
			void shoot(Character *enemy) override;
			
			// hasboolets() returns a Boolean that indicates whether there are any bullets left in this morning's gun.
			bool hasboolets()const override;

			// reload() loads the gun with six new bullets.
			void reload()override;

			
	};
}
#endif




