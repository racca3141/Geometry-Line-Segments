// Emerson Racca
// 11/15/2021
// Lab 10a - Geometry Line Segments

/*
Design and implement a Point class which models points in the Cartesian coordinate system.

Design and implement a Segment class using the idea that 2 points determine a line segment.

Be sure to include the following methods:
1. A constructor with defaults.
2. Accessor, Get and Set methods.
3. Appropriate useful utility methods.

Write a main driver program (no user input) that demonstrates the usage of your class designs.


*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


class Point {
private:
	double x, y;

public:
	//constructors
	Point(void);                     //Default constructor
	Point(double xArg, double yArg); //Default values not allowed since the default constructor takes care of that. 
	//accessors
	void setX(double xArg);
	void setY(double yArg);
	double getX(void);
	double getY(void);
	//methods
	void display(void);
};

class Segment {
private:
	Point p1, p2;

public:
	//constructors
	Segment(void);
	Segment(Point argP1, Point argP2);
	//accessors
	void setP1(Point argP1);
	void setP2(Point argP2);
	Point getP1(void);
	Point getP2(void);
	//methods
	void display(void);
	double length(void);
};

int main(void) {
	srand((unsigned int) time(0));

	cout << "Geometry Line Segments\n\n";
	
	cout << "Point class:" << endl;
	cout << "-----------------------------------------------------" << endl;

	Point pt1(-3,-3), pt2;

	cout << "Using accessors:" << endl;

	pt2.setX(-7);
	pt2.setY(-6);

	cout << "Point 1: x = " << pt1.getX() << ",  y = " << pt1.getY() << endl;
	cout << "Point 2: x = " << pt2.getX() << ",  y = " << pt2.getY() << endl << endl;

	cout << "Using methods:" << endl;
	cout << "Point 1: ";
	pt1.display();
	cout << "Point 2: ";
	pt2.display();



	cout << "\n\nSegment class with the points above: " << endl;
	cout << "-----------------------------------------------------" << endl;

	Segment s1(pt1, pt2);

	cout << "Using accessors:" << endl;
	cout << "Point 1: ";
	s1.getP1().display();
	cout << "Point 2: ";
	s1.getP2().display();

	cout << "\nUsing methods:" << endl;

	s1.display();
	
	cout << "Length of the segment: " << s1.length();

	cout << "\n\nLine segment changed using set accessors with new points: " << endl;

	pt1.setX(-1);
	pt1.setY(-1);
	pt2.setX(0);
	pt2.setY(0);

	s1.setP1(pt1);
	s1.setP2(pt2);

	s1.display();

	cout << "Length of the segment: " << s1.length() << endl << endl;

	cout << "\nRandom line segments:" << endl;
	cout << "-------------------------------------------------------\n";

	double x1, y1, x2, y2;
	for (int i = 0; i < 20; i++) {
		x1 = (rand() % 30 + 1.0 * rand() / RAND_MAX) - 15; //-15 to 15
		y1 = (rand() % 30 + 1.0 * rand() / RAND_MAX) - 15;
		x2 = (rand() % 30 + 1.0 * rand() / RAND_MAX) - 15;
		y2 = (rand() % 30 + 1.0 * rand() / RAND_MAX) - 15;

		pt1.setX(x1);
		pt1.setY(y1);
		pt2.setX(x2);
		pt2.setY(y2);

		s1.setP1(pt1);
		s1.setP2(pt2);

		s1.display();

		cout << "Length of the segment: " << s1.length() << endl << endl;


	}
	
	return 0;
}


// Point:
// -------------------------------------
// constructors
Point::Point(void) {
	setX(0);
	setY(0);
}
Point::Point(double xArg, double yArg) {
	setX(xArg);
	setY(yArg);
}
// accessors
void Point::setX(double xArg) {
	x = xArg;
}
void Point::setY(double yArg) {
	y = yArg;
}
double Point::getX(void) {
	return x;
}
double Point::getY(void) {
	return y;
}
// methods
void Point::display(void) {
	cout << "x = " << getX() << " , y = " << getY() << endl;
}

// Segment:
// -------------------------------------
// constructors
Segment::Segment(void) {
	p1.setX(0);
	p1.setY(0);
	p2.setX(0);
	p2.setY(0);
}
Segment::Segment(Point argP1, Point argP2){
	p1.setX(argP1.getX());
	p1.setY(argP1.getY());
	p2.setX(argP2.getX());
	p2.setY(argP2.getY());

}
// accessors
void Segment::setP1(Point argP1) {
	p1 = argP1;
}
void Segment::setP2(Point argP2) {
	p2 = argP2;
}
Point Segment::getP1(void) {
	return p1;
}
Point Segment::getP2(void) {
	return p2;
}
// methods
void Segment::display(void) {
	cout << "Point 1: ";
	getP1().display();
	cout << "Point 2: ";
	getP2().display();
}
double Segment::length(void) {
	double lx = getP2().getX() - getP1().getX();
	double ly = getP2().getY() - getP1().getY();
	return (sqrt(pow(lx, 2) + pow(ly, 2)));
}