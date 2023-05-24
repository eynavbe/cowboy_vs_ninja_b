#include <iostream>
#include "Point.hpp"
using namespace std;
#ifndef CHARACTER_H
#define CHARACTER_H
namespace ariel
{
	class Team; 
	class Character {
		private:
			Point  location;
			int hitPoint;
			std::string name;
			Team* team; 
		public:

			// A constructor that receives a location (of type Point), hit points (represented by an integer) and a name represented by a character string.
			Character(Point  placeC, int hitPointC, std::string nameC): location(placeC), hitPoint(hitPointC) , name(nameC),team(nullptr) { }
			
			// To return the team address to which the character belongs, this is to make sure that the same character is not in the same team.
			Team* getTeam() const {
				return team;
			}

			// set the team address that the character belongs to.
			void setTeam(Team* team) {
				this->team = team;
			}

			// getLocation() returns the location of the character.
			Point getLocation() const {
				return location;
			}

			// set the location of the character.
			void setLocation(Point location2){
				location = location2;
			}

			// return the hit point of the character.
			int getHitPoint() const {
				return hitPoint;
			}

			// set the hit point of the character.
			void setHitPoint(int hitPoint2) {
				hitPoint = hitPoint2;
			}

			// getName() returns the name of the character
			std::string getName() const {
				return name;
			}
			operator string() const {             
				return string(location)+","+std::to_string(hitPoint)+","+(name);
			}

			// print() prints the name of the character, the number of its hit points, and the point where the character is. If the character dies a number of - - hit points will not be printed, and the character's name will appear in parentheses. Before the name will appear a letter indicating the type of character: N for ninja and C for morning.
			virtual  std::string print() {  
				if(!isAlive()) {
					return getType()+ " "+"("+(name)+"),"+string(location);
				}     
				return getType()+" "+(name)+","+std::to_string(hitPoint)+","+string(location);
			}

			// IsAlive() returns a boolean value of whether the character is alive (that is, it has more than zero hit points)
			bool isAlive()const;

			// distance receives a pointer to another character and returns the distance between the characters
			virtual double distance (Character * character2) const;

			// hit gets an integer. Subtracts the appropriate amount of hit points from the character.
			void hit(int num);

			// return type of character: N for ninja and C for morning.
			virtual std::string getType() const {
				return "C";
			}

			// A function found only in cowboys, who inherit from a character.
			virtual void shoot(Character *enemy);

			// A function found only in cowboys, who inherit from a character.
			virtual bool hasboolets()const;

			// A function found only in cowboys, who inherit from a character.
			virtual  void reload();

			// A function found only in Ninja, which inherits from a character.
			virtual void move(Character *enemy);

			// A function found only in Ninja, which inherits from a character.	
			virtual void slash(Character *enemy)const;

			// A function found only in Ninja, which inherits from a character.
			virtual bool close(Character *enemy)const;
	};
}

#endif


