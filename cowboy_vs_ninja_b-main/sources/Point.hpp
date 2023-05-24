#include <iostream>
using namespace std;
#ifndef POINT_H
#define POINT_H
namespace ariel
{
	class Point {
		private:
			double  x;
			double  y;
		public:
		// constructor accepts both coordinates of the double type that keep the position of the unit along the x and y axes accordingly
			Point(double  x1, double y2): x(x1), y(y2) { }
			
			// Default constructor
			Point(): x(0.0), y(0.0) { } 

			// Returns x at the point
			double getX() const {
				return x;
			}

			// Returns y at the point
			double getY() const {
				return y;
			}

			operator string() const {             
				return "(" +std::to_string(x)+","+std::to_string(y)+")" ;
			}

			// Prints the two coordinates in parentheses.
			virtual void print ()const {             
				cout << "(" +std::to_string(x)+","+std::to_string(y)+")" <<endl;
			}

			// distance receives a point and calculates the distance between the two points 
			virtual double distance (Point Point2) const;

			// moveTowards accepts a source point, a destination point and a distance. The function returns the closest point to the destination point, which is at most the given distance from the source point
			static  Point moveTowards(Point startingPoint, Point destinationPoint, double distance1) ;
	};
}
#endif



