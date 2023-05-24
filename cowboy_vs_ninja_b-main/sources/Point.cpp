#include "Point.hpp"
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
namespace ariel {
    // https://www.geeksforgeeks.org/program-calculate-distance-two-points/
    double Point::distance (Point Point2) const{
        return sqrt(pow(Point2.getX() - getX(), 2) + pow(Point2.getY() - getY(), 2) * 1.0);    
    }
    Point Point::moveTowards(Point startingPoint, Point destinationPoint, double distance1) {  
        if(distance1 < 0){
            throw std::invalid_argument("negative distance");
        } 
        double dx = destinationPoint.getX() - startingPoint.getX();
        double dy = destinationPoint.getY() - startingPoint.getY();
        double pointDistance = startingPoint.distance(destinationPoint);
        if (pointDistance <= distance1) {
            return destinationPoint;
        }
        double ratio = distance1 / pointDistance;
        double newX = startingPoint.getX() + (dx * ratio);
        double newY = startingPoint.getY() + (dy * ratio);
        return Point(newX, newY);
    }
}