#include "Ninja.hpp"
#include <cmath>
using namespace std;
namespace ariel {
    void Ninja::move(Character *enemy){
        Point point1 = Point::moveTowards(getLocation(),enemy->getLocation(),getSpeed());
        setLocation(point1);
    }
    bool Ninja::close(Character *enemy)const{
        if(getLocation().distance(enemy->getLocation()) <= 1){
            return true;
        }
        return false;
    }
    void Ninja::slash(Character *enemy)const{
        if(this == enemy){
        throw std::runtime_error("self harm");
    }
        if(isAlive() && enemy->isAlive()){
            if(close(enemy)){
                enemy->setHitPoint(enemy->getHitPoint() - 40);
            }
        }else{
            throw std::runtime_error("Attacking a dead character");

        }
    }
}