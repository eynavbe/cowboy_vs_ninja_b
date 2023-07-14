#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp" 
using namespace std;
using namespace ariel;

TEST_CASE("distance Point")
{
    Point a(32.3,44),b(1.3,3.5);
    CHECK(a.distance(b) == 51.0);
    Point c(32,1),d(2,3.1);
    CHECK(c.distance(d) == 30.07);
    Point f(0,0);
    CHECK(c.distance(f) == 32.01);

}
    


TEST_CASE("Character ")
{
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *Or = new Cowboy("Or", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *Lior = new TrainedNinja("Lior", Point(64,57));
    YoungNinja *Yogi = new YoungNinja("Yogi", Point(64,57));

    CHECK(tom->getName()== "Tom");
    CHECK(sushi->getName()=="sushi");
    CHECK(Yogi->getName()== "Yogi");
    CHECK(Lior->getName()== "Lior");
    CHECK(Or->getName()== "Or");

    CHECK(tom->hasboolets()== true);
    CHECK(Or->hasboolets()== true);
    CHECK(Or->isAlive()== true);

    CHECK(Lior->isAlive()== true);
    CHECK(tom->isAlive()== true);
    CHECK(sushi->isAlive()== true);
    CHECK(Yogi->isAlive()== true);

    CHECK(tom->getAmountBalls()== 6);
    CHECK(tom->getHitPoint()== 110);
    CHECK(sushi->getSpeed()== 100 );
    CHECK(sushi->getHitPoint()== 14);
    CHECK(Lior->getSpeed()== 120);
    CHECK(Lior->getHitPoint()== 12);
    CHECK(Yogi->getSpeed()== 14);
    CHECK(Yogi->getHitPoint()== 100);

    for(int i =1; i<4;i++){
        Yogi->slash(Lior);
        CHECK(Lior->getHitPoint()== 120-40*i);

    }
    CHECK(Lior->isAlive()== false);

    for(int i =1; i<7;i++){
        Or->shoot (tom);
        CHECK(Or->hasboolets()== 6-i);
    }
    CHECK(tom->isAlive()== false);
    CHECK(Or->hasboolets()== 0);
    Or->reload();
    CHECK(Or->hasboolets()== 6);
}


