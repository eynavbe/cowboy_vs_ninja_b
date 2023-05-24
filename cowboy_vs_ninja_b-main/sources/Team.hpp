#include <iostream>
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
using namespace std;
#ifndef TEAM_H
#define TEAM_H
namespace ariel
{
class Team {
    private:
        Character* characters[10];
        Character * leader;
    public:

    // constructor, a group of up to ten warriors, where a warrior can be a ninja or a warrior. When a group is created, it gets a leader pointer.
        Team(Character* leaderT) : leader(nullptr) { 
            if (leaderT != nullptr && leaderT->getTeam() != nullptr) {
                throw std::runtime_error("Appointing the same captain to different teams");
            }
            this->leader = leaderT;
            charactersCreate(leaderT);
            if (leader != nullptr) {
                leader->setTeam(this);
            }
        }

        // Each group is assigned a leader who is one of the Character.
        void charactersCreate(Character* leader) {
            for (int i = 0; i < 10; i++) {
                characters[i] = nullptr;
            }
            characters[0] = leader;
        }

        // return the leader of the team
        Character * getLeader() const {
            return leader;
        }

        // return the list of the Characters in team
        Character** getCharacters(){
            return characters;
        }

        // set the leader of the team
        void setLeader(Character * leader2){
            leader = leader2;
        }

        // print() goes through all the characters in the group and prints their details.
        virtual void print() {
            std::string printTeam = "";
            for (int i = 0; i < 10; i++) {
                if (characters[i] != nullptr) {
                    printTeam +=  characters[i]->print() + " , ";
                }
            }
            std::cout << printTeam << std::endl;
        }

        // If the leader of the group dies, a new leader must be chosen, who is the closest living character (in terms of location) to the dead leader.
        void choosingNewLeader();

        // A victim will be selected from the enemy group. The victim is the living enemy group member who is closest to the leader of the attacking group.
        virtual Character*  CharacterClosest(Character** team1, Character* character1) ;
        
        // stillAlive() returns an integer number of group members remaining alive.
        int stillAlive()const;

        // add() takes a pointer to a morning or ninja, and adds it to the group
        virtual void add(Character* character1);

        // attack() accepts a pointer to an enemy group. And the team attacks the enemy team. By several parameters the attack could be carried out.
        virtual void attack(Team* enemy);

        // Frees the memory allocated to all characters in the group.
        ~Team(){
            for(int i=0; i<10;i++){
            delete characters[i];
            }
        }
    };
}

#endif


