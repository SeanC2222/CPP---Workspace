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
#include <vector>

using namespace std;

class Point {
	private:
		double x, y;
		static int pointNumber; //Want to store a count of points as generated.

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

LineSegment::LineSegment() {
	p1.setX(0);
	p1.setY(0);
	p2.setX(0);
	p2.setY(0);
	slope = 0;
	length = 0;
}

LineSegment::LineSegment(Point userP1, Point userP2){
	p1 = userP1;
	p2 = userP2;
	slope = (p2.getY() - p1.getY()) / (p2.getX() - p2.getX());
	length = p1.distanceTo(p2);
}

void displayMenu();
char getChoice();
void createPoint(vector<Point>&);
Point createPoint();
void displayPointData(vector<Point>&);
void showDistance(vector<Point>&, int, int);
void createLineSegment(vector<LineSegment>&);
void displayLineSegmentData(vector<LineSegment>&);
void displayLength(vector<LineSegment>&, int);
void displaySlope(vector<LineSegment>&, int);

int main() {

	cout << "This program can create points and line segments and tell you"
	     << " basic\ninformation about each type. You can find the location"
	     << " get the location of a \ncreated point, or the distance between"
	     << " two points. When you create a line\nsegment, you can see the"
	     << " slope, or the line segment length and the two points that"
	     << "\nmake up the end." << endl;
	cout << "Press enter to continue...";


	char choice;
	int linen, pointn, pointm;
	vector<Point> pStorage;
	vector<LineSegment> lsStorage;

	do{
		cin.get();
		displayMenu();
		choice = getChoice();

		switch(choice){

			case('1'):
				createPoint(pStorage);
				break;
			case('2'):
				displayPointData(pStorage);
				break;
			case('3'):
				cout << "Pick your two point numbers: ";
				cin >> pointn >> pointm;
				cin.get();
				showDistance(pStorage, --pointn, --pointm);
				break;
			case('4'):
				createLineSegment(lsStorage);
				break;
			case('5'):
				displayLineSegmentData(lsStorage);
				break;
			case('6'):
				cout << "Which line would you like the length of? ";
				cin >> linen;
				cin.get();
				displayLength(lsStorage,linen);
				break;
			case('7'):
				cout << "Which line would you like the slope of? ";
				cin >> linen;
				cin.get();
				displaySlope(lsStorage, linen);
				break;
			default:
				choice = 0;
		};
	} while (choice);
	return 0;
}

void displayMenu(){
	for (int i = 0; i < 100; i++){
		cout << "\n";
	}
	cout << "What would you like to do?\n"
		 << "1) Create a point\n"
		 << "2) See what points you have created\n"
		 << "3) Find the distance between two points\n"
		 << "4) Create a line segment\n"
		 << "5) See what line segments you have created\n"
		 << "6) See the length of a line segment\n"
		 << "7) See the slope of a line segment\n"
		 << "Type anything else to quit." << endl;
	return;
}

char getChoice(){
	char choice;
	cout << "Your choice: ";
	choice = cin.get();
	cin.ignore(100,'\n');
	return choice;
}

void createPoint(vector<Point> &pStorage){

	int tempX, tempY;
	cout << "What are your point's coordinates?\n"
		 << "X: ";
	cin >> tempX;
	cout << "Y: ";
	cin >> tempY;
	Point pn(tempX,tempY);
	pStorage.push_back(pn);

	return;
}

Point createPoint (){

	int tempX, tempY;
	cout << "What are your point's coordinates?\n"
		 << "X: ";
	cin >> tempX;
	cout << "Y: ";
	cin >> tempY;
	Point pn(tempX,tempY);

	return pn;
}

void displayPointData(vector<Point> &pStorage){
	cout << "Now in displayPointData!" << endl;
	for (int i = 0; i < pStorage.size(); i++){
		cout << "Point " << i + 1 << " - (" << pStorage[i].getX()
			 << ", " << pStorage[i].getY() << ")" << endl;
	}
	return;
}

void showDistance(vector<Point> &pStorage, int pointn, int pointm){
	if (pointn > pStorage.size() || pointm > pStorage.size()){
		cout << "You haven't made a point ";
		if (pointn > pStorage.size()){
			cout << pointn << " yet." << endl;
		} else {
			cout << pointm << " yet." << endl;
		}
		return;
	} else {
		double distance;

		distance = sqrt(pow(pStorage[pointm].getX()-pStorage[pointn].getX(),2) +
				   pow(pStorage[pointm].getY()-pStorage[pointn].getY(),2));
		cout << "The distance between the two points is: " << distance << endl;
	}
}

void createLineSegment(vector<LineSegment> &lsStorage){
	Point p1, p2;

	p1 = createPoint();
	p2 = createPoint();
	LineSegment lsn(p1,p2);
	lsStorage.push_back(lsn);
}

void displayLineSegmentData(vector<LineSegment> &lsStorage){

	for (int i = 0; i < lsStorage.size(); i++){
		cout << "Line " << i+1 << ":\n"
			 << "Starting Point: (" << lsStorage[i].getP1().getX()
			 << ", " << lsStorage[i].getP1().getY() << ")\n"
			 << "Ending Point: (" << lsStorage[i].getP2().getX()
			 << ", " << lsStorage[i].getP2().getY() << ")"
			 << endl;
	}
	return;
}

void displayLength(vector<LineSegment> &lsStorage, int linen){
	cout << "The length of line " << linen << " is: ";
	cout << lsStorage[linen - 1].getLength() << endl;
	return;
}

void displaySlope(vector<LineSegment> &lsStorage, int linen){
	cout << "The slope of line " << linen << " is: ";
	cout << lsStorage[linen - 1].getSlope() << endl;
	return;
}
