/* Author: SeanC
 * Date: Nov 25, 2014
 *
 * carLot2.cpp
 * 
 * File purpose: 
 * 
 * Inputs:
 *
 * Outputs: 
 */                                                                          //

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;
/****************************************************************************/
//  Holds day, month, and year information									//
//  Private:	int day, month, year	holds relevant data					//
// 				bool checkDate()		returns true if day value makes    	//
//										sense for the month value			//
//	Public:		Date()				default constructor day = 1, month = 0,	//
//									year = 0								//
//				Date(int,int,int)	Constructor to assign user values to new//
//									object									//
//				int getDay()		returns day								//
//				int getMonth()		returns month							//
//				int getYear()		returns year							//
/****************************************************************************/
class Date{
	private:
		int day;
		int month;
		int year;
		bool checkDate(int,int,int);

	public:
		Date(): day(1), month(0), year(0){}
			//Day initialized to 1 for use in checkDate (day > 0)
		Date(int,int,int);
		int getDay() {return day;}
		int getMonth() {return month;}
		int getYear() {return year;}
};

bool Date::checkDate(int d, int m, int y){
	int dinm;	//int days in month (dinm)
	//m = february
	if (m == 2){
		dinm = 28;
	//m = september, april, june, november
	} else if (m == 9 || m == 4 || m == 6 || m == 11){
		dinm = 30;
	//m = all other months
	} else {
		dinm = 31;
	}
	//day of date object must be <=dinm and day > 0 to return true
	if (d <= dinm && d > 0){
		return true;	//date is valid
	} else {
		return false;	//date is not valid
	}
}

Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
	//Throws invalid_argument exception if date information is false
	if (!this->checkDate(d,m,y)){
		throw std::invalid_argument("ERROR: The given month and day are not a valid date");
	}
}
/****************************************************************************/
//  Holds all the relevant car information, and can return the profit on	//
//	a car.																	//
//  Private:	string make			car make (i.e. ford, chevrolet, etc.)	//
// 				string model		car model (i.e. mustang, corvette, etc.)//
//				int year			car production year						//
//				Date datePurchased	date the car was purchased				//
//				double purchasePricepurchase price of the vehicle			//
//				bool isSold			true if sold, false if still in stock	//
//				Date dateSold		date that the car was sold, default 	//
//									of day = 1, month = 0, year = 0			//
//				double salePrice	sale price of the vehicle if sold		//
//	Public:		Car(string,string,int,Date,double,bool)						//
//					constructor used for a car that's in stock				//
//				Car(string,string,int,Date,double,bool,Date,double)			//
//					constructor used for a car that's sold					//
//				string getMake()	returns make							//
//				string getModel()	returns model							//
//				int getYear()		returns year							//
//				Date getDatePurch() returns Date object of when purchased	//
//				double getPurchPrice()	returns purchase price				//
//				bool getIsSold()	returns isSold							//
//				Date getDateSold()	returns Date object of when sold		//
//				double getSalePrice() 	returns sale price					//
//				double getProfit()	if isSold, 								//
//									return salePrice - purchasePrice 		//
//									else return NAN							//
/****************************************************************************/
class Car{
	private:
		string make;
		string model;
		int year;
		Date datePurchased;
		double purchasePrice;
		bool isSold;
		Date dateSold;
		double salePrice;
	public:
		Car(string,string,int,Date,double,bool);
		Car(string,string,int,Date,double,bool,Date,double);
		string getMake() {return make;}
		string getModel() {return model;}
		int getYear() {return year;}
		Date getDatePurch() {return datePurchased;}
		double getPurchPrice() {return purchasePrice;}
		bool getIsSold() {return isSold;}
		Date getDateSold() {return dateSold;}
		double getSalePrice() {return salePrice;}
		double getProfit();

};

Car::Car(string umake, string umodel, int uyear, Date udatePurchased, double upurchasePrice, bool uisSold){
	make = umake;
	model = umodel;
	year = uyear;
	datePurchased = udatePurchased;
	purchasePrice = upurchasePrice;
	isSold = uisSold;
	Date tempDate(1,0,0);
	dateSold = tempDate;
	salePrice = 0.0;

}

Car::Car(string umake, string umodel, int uyear, Date udatePurchased, double upurchasePrice, bool uisSold, Date udateSold, double usalePrice){
	make = umake;
	model = umodel;
	year = uyear;
	datePurchased = udatePurchased;
	purchasePrice = upurchasePrice;
	isSold = uisSold;
	dateSold = udateSold;
	salePrice = usalePrice;
}

double Car::getProfit(){
	//if the car has been sold, return the profit else return not a number
	if (isSold){
		return (salePrice - purchasePrice);
	} else {
		return NAN;
	}
}
/****************************************************************************/
//  Holds a vector representing a carlot									//
//  Private:	vector<Car>	lot		holds all input car objects				//
//	Public:		void addCar(Car)	adds a car to lot						//
//				void listCurrentInv()	lists all members of lot and their	//
//									information								//
//				double getMonthProfit(int,int)								//
//					returns the total profit for a month					//
/****************************************************************************/
class CarLot{
	private:
		vector<Car> lot;
	public:
		CarLot() {}
		vector<Car> getLot() {return lot;}
		void addCar(Car);
		void listCurrentInv();
		double getMonthProfit(int,int);
};

void CarLot::addCar(Car uCar){
	//adds new car to the end of lot
	lot.push_back(uCar);
	return;
}

void CarLot::listCurrentInv(){
	int carCount = 0;
	//Lists current inventory
	cout << "Current inventory: \n" << endl;
	for (unsigned i = 0; i < lot.size(); i++){
		if (!lot[i].getIsSold()){
		cout << lot[i].getYear() << " " << lot[i].getMake() << " " << lot[i].getModel() << "\n"
			 << "Date Purchased: " << lot[i].getDatePurch().getMonth() << "/"
			 	 	 	 	 	   << lot[i].getDatePurch().getDay() << "/"
			 	 	 	 	 	   << lot[i].getDatePurch().getYear() << " "
			 << "Purchase Price: $" << lot[i].getPurchPrice() << "\n";
		carCount++;
		}
		//If the car is sold, list sale information
		/*if (lot[i].getIsSold()){
			cout << "Date Sold: " << lot[i].getDateSold().getMonth() << "/"
	 	 	 	 	   	   	      << lot[i].getDateSold().getDay() << "/"
	 	 	 	 	   	   	      << lot[i].getDateSold().getYear() << " "
	 	 	 	 << "Selling Price: $" << lot[i].getSalePrice() << endl;
		}*/
		cout << endl;
	}
	cout << "Total Cars: " << carCount << endl;
	return;
}

double CarLot::getMonthProfit(int month, int year){
	double monthProfit = 0;		//running sum for month's profits
	//Checks all cars for to see if month & year match sold values
	for (unsigned i = 0; i < lot.size(); i++){
		if (lot[i].getDateSold().getYear() == year
			&& lot[i].getDateSold().getMonth() == month){
			//Adds profit from sale to running sum
			monthProfit += lot[i].getProfit();
		}
	}
	return monthProfit;
}

void displayMenu();
int getChoice();
Car getCarInfo();
int getCarYear();
Date getDate();
double getPrice();
bool getIsSold();
void getMonthYear(int&,int&);

int main(){
	CarLot userLot;	//empty car lot
	int choice, m = -1, y = -1;

	do{
		displayMenu();
		choice = getChoice();
		switch (choice){
			case 1:
				userLot.addCar(getCarInfo());
				break;
			case 2:
				userLot.listCurrentInv();
				cin.get();
				break;
			case 3:
				m = -1;
				y = -1;
				getMonthYear(m,y);
				cout << m << "/" << y << " profits: $" << userLot.getMonthProfit(m,y) << endl;
				cin.get();
				break;
		}
	}while (choice >=1 && choice <=3);

	return 0;
}
/****************************************************************************/
//  Displays the user menu choices											//
//	User inputs: None														//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
void displayMenu(){
	for(int i = 0; i < 100; i++){
		cout << endl;
	}
	cout << "What would you like to do?\n"
		 << "1) Add a car\n"
		 << "2) List current inventory\n"
		 << "3) Profit for a month\n"
		 << "4) Quit\n" << endl;
	return;
}
/****************************************************************************/
//  Gets user choice for menu usage. Validates choice.						//
//	User inputs: int userChoice		integer value 1 to 4					//
//  Function Call Arguments: None											//
//  Returns: userChoice								    					//
/****************************************************************************/
int getChoice(){
	int userChoice = -1;	//User's menu pick
	do{
		cin >> userChoice;
		//Input must not fail, and must not have leftovers
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			continue;
		} else {
			//Clears buffer
			cin.ignore(100,'\n');
			return userChoice;
		}
	} while (userChoice < 0 && userChoice > 4);
	return 4;	//If a failure happens return quit
}
/****************************************************************************/
//  Gets all the car info to create and return a car object.				//
//	User inputs: All the values for a car object							//
//  Function Call Arguments: None											//
//  Returns: Car object								    					//
/****************************************************************************/
Car getCarInfo(){

	string make, model;
	int year;
	Date datePurchased(1,0,0), dateSold(1,0,0);
	double purchasePrice, salePrice;
	bool isSold;

	cout << "Make: ";
	getline(cin, make);
	cout << "Model: ";
	getline(cin, model);
	year = getCarYear();
	cout << "Please enter the date purchased (enter month as number 1-12): " << endl;
	datePurchased = getDate();
	cout << "Purchase ";
	purchasePrice = getPrice();
	isSold = getIsSold();

	if (isSold){
		cout << "Sale ";
		salePrice = getPrice();
		cout << "Please enter the date sold (enter month as number 1-12): " << endl;
		dateSold = getDate();
		return Car(make,model,year, datePurchased, purchasePrice, isSold, dateSold, salePrice);
	}

	return Car(make,model,year, datePurchased, purchasePrice, isSold);
}
/****************************************************************************/
// 	Gets and returns car production year									//
//	User inputs: int year	car production year								//
//  Function Call Arguments: None											//
//  Returns: year									    					//
/****************************************************************************/
int getCarYear(){
	int year;
	do{
		cout << "Car Year: ";
		cin >> year;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			year = -1;
			continue;
		} else {
			cin.ignore(100, '\n');
		}
	}while (year < 0);
	return year;
}
/****************************************************************************/
// 	Gets and returns a valid price.											//
//	User inputs: double price	Price of purchase/Price of sale				//
//  Function Call Arguments: None											//
//  Returns: price									    					//
/****************************************************************************/
double getPrice(){
	double price;
	do{
		cout << "Price: $";
		cin >> price;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			price = -1;
			continue;
		} else {
			cin.ignore(100, '\n');
		}
	}while (price == -1);
	return price;
}
/****************************************************************************/
// 	Gets input if car is sold ('y' or 'n')									//
//	User inputs: char yn	yes or no										//
//  Function Call Arguments: None											//
//  Returns: true	if yn == 'y'					    					//
//			 false	if yn == 'n'											//
/****************************************************************************/
bool getIsSold(){
	char yn;
	bool isSold;

	do{
		cout << "Has this car been sold? (\'y\'/\'n\') ";
		cin >> yn;
		if (yn == 'y'){
			isSold = true;
		} else {
			isSold = false;
		}
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			yn = 0;
			continue;
		} else {
			cin.ignore(100, '\n');
		}
	}while (yn == 0);
	return isSold;
}
/****************************************************************************/
// 	Modifies referred values of m (month) and y (year)						//
//	User inputs: int& m		month value 1 through 12						//
//				 int& y		year value										//
//  Function Call Arguments: None											//
//  Returns: None									    					//
/****************************************************************************/
void getMonthYear(int& m, int& y){
	do{
		cout << "Which month? ";
		cin >> m;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100, '\n');
			m = -1;
		} else {
			cin.ignore(100,'\n');
		}
	}while (m < 1 || m > 12);
	do{
		cout << "Which year? ";
		cin >> y;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100, '\n');
			y = -1;
		} else {
			cin.ignore(100,'\n');
		}
	}while(y == -1);
	return;
}
/****************************************************************************/
// 	Gets values for, creates, and returns Date object. Calls getMonthYear()	//
//	User inputs: int d														//
//  Function Call Arguments: None											//
//  Returns: tempDate								    					//
/****************************************************************************/
Date getDate(){
	int d, m, y;
	do{
		cout << "Which day? ";
		cin >> d;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100, '\n');
			d = -1;
		} else {
			cin.ignore(100,'\n');
		}
	}while (d < 1);
	getMonthYear(m,y);
	Date tempDate(d,m,y);
	return tempDate;
}
