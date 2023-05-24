#ifndef YOUNGNINJA_H
#define YOUNGNINJA_H
#include "Ninja.hpp"
constexpr int HITPOINTYOUNG = 100;
constexpr int SPEEDYOUNG = 14;
namespace ariel {
    class YoungNinja : public Ninja {
    public:

        // constructor, YoungNinja inherits from Ninja and gets all the parameters of Ninja and is set to 14 speed and 100 hit points.
        YoungNinja(std::string nameC, Point placeC) : Ninja(placeC, HITPOINTYOUNG, std::move(nameC), SPEEDYOUNG) {}
    };
}
#endif
