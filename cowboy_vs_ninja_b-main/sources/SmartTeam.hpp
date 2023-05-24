#include <iostream>
#include "Team.hpp"
#include <string>
using namespace std;
#ifndef SMARTTEAM_H
#define SMARTTEAM_H
namespace ariel
{
    class SmartTeam : public Team{
        private:

        public:

            // constructor
            SmartTeam(Character *leaderT):  Team(leaderT){}

            // Attack in a different way when a check is made on the other team for the positions of their forces and their status as well as taking into account the state of the attacking team to maximize damage.
            void attack(Team* enemy);

            // Change the order of the attacking group so that those who can hurt him attack the victim first.
            Character** RearrangeTeam(Character** team1, Character* victim, int index);
            
            // Choosing a victim by checking who is the victim that as many team members can hit him and with the most hit points, so if he doesn't stay alive after this hit, you can move on to the next victim with a maximum of team members who didn't attack.
            Character*  ChoosingVictim(Character** team1, Character** teamVictim, int index) ;
    };
}
#endif



