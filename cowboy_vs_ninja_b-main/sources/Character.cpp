#include "Character.hpp"
#include <cmath>
using namespace std;

namespace ariel {
    bool Character::isAlive()const{
        if(getHitPoint() > 0){
            return true;
        }
        return false;
    }
    double Character::distance (Character * character2) const{
        return getLocation().distance(character2->getLocation());
    }
    void Character::hit(int num){
        if(num < 0){
            throw std::invalid_argument("Sending negative value to hit");
        }
        setHitPoint(getHitPoint()-num);
    }
    void Character::move(Character *enemy){}
    void Character::shoot(Character *enemy){}
    bool Character::hasboolets()const{return false;}
    void Character::reload(){}
    void Character::slash(Character *enemy)const{}
    bool Character::close(Character *enemy)const{return false;}
}