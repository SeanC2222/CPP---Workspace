/* Author: SeanC
 * Date: Nov 25, 2014
 *
 * geom.cpp
 * 
 * File purpose: This file is used to create and store points and line segments
 * through user input. It creates a class called "Point" used to store the
 * location of individual point objects. There is a second class created called
 * "LineSegment" that contains two point objects and using basic geometry
 * holds the information for it's slope and it's length.
 * 
 * Inputs:	Point pn		- The user must enter point information for each
 * 								point n.
 * 			LineSegment lsn - The user must enter point information for each
 * 								line segment n.
 * Outputs: pn.distanceTo(pm)	- outputs distance between pn and pm
 * 			lsn.length()		- outputs lsn's length using distanceTo()
 * 			lsn.slope()			- outputs lsn's slope, if vertical states line
 * 									is vertical
 */                                                                          //

#include <iostream>
#include <cmath>

using namespace std;

class Point {
	private:
		double x, y;

	public:
		Point ();
		Point (double userX, double userY): x(userX), y(userY) {}
		double getX() {return x;}
		void setX(double userX) {x = userX;}
		double getY() {return y;}
		void setY(double userY) {y = userY;}
		double distanceTo(Point);

};

Point::Point() {
	x = 0;
	y = 0;
}

double Point::distanceTo(Point pn){
	double distance;
	distance = sqrt(pow(pn.getX() - x,2) + pow(pn.getY() - y,2));
	return distance;
}

class LineSegment {
	private:
		Point p1, p2;
		double slope, length;
		static int lineSegmentCount; //Want to keep a count of created Line Segments
	public:
		LineSegment();
		LineSegment(Point userP1, Point userP2);
		Point getP1() {return p1;}
		Point getP2() {return p2;}
		double getSlope() {return slope;}
		double getLength() {return length;}
};

LineSegment::LineSegment(Point userP1, Point userP2){
	p1 = userP1;
	p2 = userP2;
	slope = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	length = p1.distanceTo(p2);
}

Point createPoint();
LineSegment createLineSegment();
void displayLength(LineSegment&);
void displaySlope(LineSegment&);

int main() {

	cout << "This program can create line segments and tell you basic information "
		 <<	"about them. When you create a line\nsegment, you can see the"
	     << " slope, and the line segment length and the two points that"
	     << " make up the ends." << endl;
	cout << "Press enter to continue...";
	cin.get();

	char choice;

	do{
		cout << endl;
		LineSegment ls = createLineSegment();
		displayLength(ls);
		displaySlope(ls);
		cout << "Would you like to check another line? (\'y\'/\'n\') ";
		cin >> choice;
		choice = tolower(choice);
		if (cin.peek() != '\n')
			cin.ignore(100,'\n');
		cin.get();
	} while (choice == 'y');
	return 0;
}

Point createPoint (){
	double tempX, tempY;
	cout << "What are your point's coordinates?\n"
		 << "X: ";
	cin >> tempX;
	cout << "Y: ";
	cin >> tempY;
	cout << endl;
	Point pn(tempX,tempY);
	return pn;
}

LineSegment createLineSegment(){
	Point p1, p2;
	p1 = createPoint();
	p2 = createPoint();
	LineSegment lsn(p1,p2);
	return lsn;
}

void displayLength(LineSegment &ls){
	cout << "The length of your line is: ";
	cout << ls.getLength() << endl;
	return;
}

void displaySlope(LineSegment &ls){
	if (isinf(ls.getSlope())){
		cout << "Your line is vertical." << endl;
	} else if (ls.getSlope() != ls.getSlope()){
		cout << "The two points are the same." << endl;
	} else {
		cout << "The slope  of your line is: "<< ls.getSlope() << endl;
	}
	return;
}
