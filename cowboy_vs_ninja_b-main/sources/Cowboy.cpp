#include "Cowboy.hpp"
#include <cmath>
using namespace std;
namespace ariel {
    void Cowboy::setAmountBalls(int amountBalls2)  {
		amountBalls = amountBalls2;
	}
    void Cowboy::shoot(Character *enemy){
    if(this == enemy){
        throw std::runtime_error("self harm");
    }
    if(isAlive() && enemy->isAlive()){
        if(getAmountBalls() > 0){
            enemy->setHitPoint(enemy->getHitPoint()-10);
            setAmountBalls(getAmountBalls()-1);
        }
    }else{
        throw std::runtime_error("Attacking a dead character");
    }
    }
    bool Cowboy::hasboolets()const{
        if(getAmountBalls() > 0){
            return true;
        }
        return false;
    }
    void Cowboy::reload(){
        if(!isAlive()){
            throw std::runtime_error("Dead cowboy can not reload");
        }
        setAmountBalls(6);
    }
}