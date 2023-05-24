#include "Team.hpp"
#include <cmath>
using namespace std;
namespace ariel {
    int Team::stillAlive()const{
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (characters[i] != nullptr) {
                if(characters[i]->isAlive()){
                    count+=1;
                }
            }
        }
        return count;
    }
    void Team::add(Character* character1){
        if (character1 != nullptr && character1->getTeam() != nullptr) {
            throw std::runtime_error("Adding the same character to different teams");
        }
        character1->setTeam(this);
        if(character1->getType() == "C"){   
            for (int i = 0; i < 10; i++) {             
                if (characters[i] == nullptr) {
                    characters[i] = character1;
                    return;
                }
            }
        }
        if(character1->getType() == "N"){            
            for (int i = 9; i >= 0; i--) {    
                if (characters[i] == nullptr) {
                    characters[i] = character1;
                    return;
                }
            }
        }
        throw std::runtime_error("team can have at most 10 teammates");
    }

    Character*  Team::CharacterClosest(Character** team1, Character* character1) {
        Character * characterClose = nullptr;
        double distanceMin =  std::numeric_limits<int>::max();
        for (int i = 0; i < 10; i++) {
            if (team1[i] != nullptr) {
                if(team1[i]->isAlive()){
                double distancecheck = team1[i]->getLocation().distance(character1->getLocation());
                    if(distancecheck < distanceMin){
                        distanceMin = distancecheck;
                        characterClose = team1[i];
                    }
                }
            }
        }
        return characterClose;
    }

    void Team::attack(Team* enemy){
        if(enemy == nullptr){
            throw std::invalid_argument("Attacking a nullptr character");
        }
        if(enemy->stillAlive() == 0 || stillAlive() == 0){
            throw std::runtime_error("Attacking a dead team ");
        }
        if(!(getLeader()->isAlive())){
            Character*  leaderNew =  CharacterClosest(getCharacters(),getLeader());
            if(leaderNew == nullptr){
                return;
            }
            setLeader(leaderNew);
        }
        Character*  enemyVictim =  CharacterClosest(enemy->getCharacters(),getLeader());
        for (int i = 0; i < 10; i++) {
            if (characters[i] != nullptr) {
                if(characters[i]->isAlive()){
                    if(!(enemyVictim->isAlive())){
                        enemyVictim =  CharacterClosest(enemy->getCharacters(),getLeader());
                        if(enemyVictim == nullptr){
                            return;
                        }
                    }
                    if(characters[i]->getType() == "C"){
                        if(characters[i]->hasboolets()){
                            characters[i]->shoot(enemyVictim);
                        }else{
                            characters[i]->reload();
                        }
                    }
                    if(characters[i]->getType() == "N"){
                        if(characters[i]->close(enemyVictim)){
                            characters[i]->slash(enemyVictim);
                        }else{

                            characters[i]->move(enemyVictim);
                        }
                    }
                }
            }
        }
    }
}