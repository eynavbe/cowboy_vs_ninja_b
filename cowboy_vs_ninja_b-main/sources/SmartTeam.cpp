#include "SmartTeam.hpp"
#include <cmath>
using namespace std;
namespace ariel {
    Character*  SmartTeam::ChoosingVictim(Character** team1, Character** teamVictim, int index) {
        int countCh = 0;
        Character * characterClose = nullptr;
        int countMax = 0;
        Character * characterCloseAlive = nullptr;
        for (int j = 0; j < 10; j++) {
            if (teamVictim[j] != nullptr) {
                if(teamVictim[j]->isAlive()){
                    characterCloseAlive = teamVictim[j];
                    countCh = 0;
                    for (int i = index; i < 10; i++) {
                        if (team1[i] != nullptr) {
                            if(team1[i]->isAlive()){
                                if(team1[i]->getType() == "N"){  
                                    if(team1[i]->close(teamVictim[j])){
                                        countCh += 40;
                                    }
                                }else{
                                    if(team1[i]->hasboolets()){
                                        countCh += 10;
                                    }
                                }
                            }
                        }
                    }
                    if(countCh > countMax){
                        countMax = countCh;
                        characterClose = teamVictim[j];
                    }
                }
            }
        }
        if(characterClose == nullptr){
            characterClose = characterCloseAlive;
        }
        return characterClose;
    }
    Character** SmartTeam::RearrangeTeam(Character** team1, Character* victim, int index){
        Character** smart = new Character*[10];
        for (int i = 0; i < 10; i++) {
            smart[i] = nullptr;
        }
        int j = 0;
        for (int i = 0; i < index; i++) {
            if (team1[i] != nullptr) {
                smart[j] = team1[i];
                j +=1;
            }
        }
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (team1[i] != nullptr) {
                if(team1[i]->isAlive()){
                    count+=1;
                }
            }
        }
        count = count - j;
        for (int i = index; i < 10; i++) {
            if (team1[i] != nullptr) {
                if(team1[i]->isAlive()){
                    if(team1[i]->getType() == "N"){
                        if(team1[i]->close(victim)){
                            smart[j] = team1[i];
                            j +=1;
                        }else{
                            smart[count] = team1[i];
                            count-=1;
                        }
                    }
                }else{
                    smart[count] = team1[i];
                    count-=1;
                }
                for (int i = index; i < 10; i++) {
                    if (team1[i] != nullptr) {
                        if(team1[i]->isAlive()){
                            if(team1[i]->getType() == "C"){ 
                                if(team1[i]->hasboolets()){
                                        smart[j] = team1[i];
                                        j +=1;
                                }else{
                                    smart[count] = team1[i];
                                    count-=1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return smart;
    }

    void SmartTeam::attack(Team* enemy){
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
        Character*  enemyVictim =  ChoosingVictim(getCharacters(),enemy->getCharacters(),0);
        Character**  teamAttack  = RearrangeTeam(getCharacters(), enemyVictim, 0);
        for (int i = 0; i < 10; i++) {
            if (teamAttack[i] != nullptr) {
                if(teamAttack[i]->isAlive()){
                    if(!(enemyVictim->isAlive())){
                        enemyVictim =  ChoosingVictim(teamAttack,enemy->getCharacters(),i);
                        teamAttack  = RearrangeTeam(teamAttack, enemyVictim, i);
                        if(enemyVictim == nullptr){
                            return;
                        }
                    }
                    if(teamAttack[i]->getType() == "C"){
                        if(teamAttack[i]->hasboolets()){
                            teamAttack[i]->shoot(enemyVictim);
                        }else{
                            teamAttack[i]->reload();
                        }
                    }
                    if(teamAttack[i]->getType() == "N"){
                        if(teamAttack[i]->close(enemyVictim)){
                            teamAttack[i]->slash(enemyVictim);
                        }else{
                            teamAttack[i]->move(enemyVictim);
                        }
                    }
                }
            }
        }
    }
}
