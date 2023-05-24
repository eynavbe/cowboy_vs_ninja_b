#include <iostream>
#include "Team.hpp"
#include <string>
using namespace std;
#ifndef TEAM2_H
#define TEAM2_H
namespace ariel
{
    class Team2 : public Team{
        private:

        public:
            // constructor
            Team2(Character *leaderT):  Team(leaderT){}

            // The same as the team, but the addition of the characters will be without the distinction of cowboys or ninjas
            virtual void add(Character* character1);
    };
}

#endif



