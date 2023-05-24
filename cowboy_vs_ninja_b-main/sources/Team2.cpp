#include "Team2.hpp"
#include <cmath>
using namespace std;
namespace ariel {
    void Team2::add(Character* character1){
        if (character1 != nullptr && character1->getTeam() != nullptr) {
            throw std::runtime_error("Adding the same character to different teams");
        }
        character1->setTeam(this);
        for (int i = 0; i < 10; i++) {
            if (getCharacters()[i] == nullptr) {
                getCharacters()[i] = character1;
                return;
            }
        }
        throw std::runtime_error("team can have at most 10 teammates");

    }
}