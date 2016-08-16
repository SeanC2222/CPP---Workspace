/* Author: SeanC
 * Date: Nov 25, 2014
 *
 * shopCart2.cpp
 * 
 * File purpose: 
 * 
 * Inputs:
 *
 * Outputs: 
 */                                                                          //

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
/****************************************************************************/
//  Holds name, price, and quantity of items to be purchased				//
//  Private:	string name			Item name							   	//
//				double price		Item price								//
//				int quantity		Item quantity							//
//	Public:		Item()				default constructor (null values)		//
//				Item(string,double,int)	Constructor to assign user values 	//
//									to new object							//
//				string getName()	returns name							//
//				double getPrice()	returns price							//
//				int getQuantity()	returns quantity						//
//				void incQuantity(int)	modifies quanity by addQuantity		//
/****************************************************************************/
class Item{
	private:
		string name;
		double price;
		int quantity;
	public:
		Item();
		Item(string,double,int);
		string getName() {return name;}
		double getPrice() {return price;}
		int getQuantity() {return quantity;}
		void incQuantity(int addQuantity) {quantity+=addQuantity;}
};

Item::Item(){
	name = "";
	price = 0.0;
	quantity = 0;
}

Item::Item(string n, double p, int q){
	name = n;
	price = p;
	quantity = q;
}
/****************************************************************************/
//  Holds vector of user Items as they are input							//
//  Private:	vector<Item> basket	user input Items					   	//
//				double totalPrice	total price of all items in cart		//
//				int quantity		Item quantity							//
//	Public:		ShoppingCart()		default constructor (null values)		//
//				double getTotal()	returns totalPrice						//
//				vector<Item> getBasket()	returns basket					//
//				void listContents()	lists all contents of basket and their	//
//									information								//
//				void addItem(Item)	Adds Item to basket						//
/****************************************************************************/
class ShoppingCart{
	private:
		vector<Item> basket;
		double totalPrice;
	public:
		ShoppingCart();
		double getTotal() {return totalPrice;}
		vector<Item> getBasket() {return basket;}
		void listContents();
		void addItem(Item);
};

ShoppingCart::ShoppingCart(){
	totalPrice = 0;
}

void ShoppingCart::listContents(){
	cout << setw(13) << right << "Item|"
				 << setw(9) << right << "Price($)|"
				 << setw(4) << right << "Quantity"
				 << endl;
	for (unsigned i = 0; i < basket.size(); i++){
		cout << setw(12) << right << basket[i].getName() << "|"
			 << setw(8) << right << basket[i].getPrice() << "|"
			 << setw(4) << right << basket[i].getQuantity()
			 << endl;
	}
	return;
}

void ShoppingCart::addItem(Item userItem){
	if (!basket.size()){
		basket.push_back(userItem);
		totalPrice += userItem.getPrice() * userItem.getQuantity();
	} else {
		for (unsigned i = 0; i < basket.size(); i++){
			if (basket[i].getName() == userItem.getName()){
				basket[i].incQuantity(userItem.getQuantity());
				totalPrice += basket[i].getPrice() * userItem.getQuantity();
				break;
			} else if (i == basket.size()-1
					   && basket[i].getName() != userItem.getName()){
				basket.push_back(userItem);
				totalPrice += userItem.getPrice() * userItem.getQuantity();
				break;
			}
		}
	}
	return;
}

int displayMenu();
int getChoice();
Item getUserItem();
double getUserPrice();
int getUserQuantity();

int main() {

	cout << "Welcome to the shopping shopCart2. This program will create a grocery"
		 << " list of user input items." << endl;
	cout << "Press enter to continue..." << endl;
	cin.get();

	int userChoice;
	Item userItem;
	ShoppingCart userCart;

	do{
		userChoice = displayMenu();
		switch(userChoice){
			case(1): //addItems
				userItem = getUserItem();
				userCart.addItem(userItem);
				cout << userItem.getName() << " successfully added!" << endl;
				cin.get();
				cin.get();
				break;
			case(2): //listContents
				userCart.listContents();
				cin.get();
				break;
			case(3): //listTotalPrice
				cout << "Total so far = $" << setprecision(2)
					 << fixed << userCart.getTotal() << endl;
				cin.get();
				break;
			default:
				break;
		}
	} while (userChoice >= 1 && userChoice <= 3);

	cout << endl;
	userCart.listContents();
	cout << endl;
	cout << "Final Total: $" << setprecision(2)
		 << fixed << userCart.getTotal() << endl;

	return 0;
}
/****************************************************************************/
//  Displays the user menu choices											//
//	User inputs: None														//
//  Function Call Arguments: None											//
//  Returns: void															//
/****************************************************************************/
int displayMenu(){
	for(int i = 0; i < 100; i++){
		cout << endl;
	}
	cout << "Menu: \n"
		 << "1) Add Item \n"
		 << "2) List Contents \n"
		 << "3) Total Price \n"
		 << "4) Quit \n\n"
		 << "What would you like to do? ";
	return getChoice();
}
/****************************************************************************/
//  Gets user choice for menu usage. Validates choice.						//
//	User inputs: int userChoice		integer value 1 to 4					//
//  Function Call Arguments: None											//
//  Returns: userChoice								    					//
/****************************************************************************/
int getChoice(){
	int userChoice = -1;
	do{
		cin >> userChoice;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			continue;
		} else {
			cin.ignore(100,'\n');
			return userChoice;
		}
	} while (userChoice < 0 && userChoice > 4);
	return userChoice;
}
/****************************************************************************/
//  Gets user Item information, creates, and returns an Item				//
//	User inputs: string n		Item name									//
//				 double p		Item price									//
//				 int q			Item quantity								//
//  Function Call Arguments: None											//
//  Returns: userItem								    					//
/****************************************************************************/
Item getUserItem () {

	string n;
	double p;
	int q;

	cout << "What is the item name? ";
	getline(cin, n);
	cout << "What is the item price? ";
	p = getUserPrice();
	cout << "How many are you buying? ";
	q = getUserQuantity();

	Item userItem(n,p,q);
	return userItem;
}
/****************************************************************************/
//  Gets valid item price and returns it									//
//	User inputs: double userPrice	Item price								//
//  Function Call Arguments: None											//
//  Returns: userPrice								    					//
/****************************************************************************/
double getUserPrice(){
	double userPrice = -1.0;
	do{
		cin >> userPrice;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			userPrice = -1.0;
			continue;
		} else if (userPrice < 0){
			cout << "Price must be positive!" << endl;
		}else{
			return userPrice;
		}
	}while (userPrice < 0);
	return userPrice;
}
/****************************************************************************/
//  Gets valid item quantity and returns it									//
//	User inputs: int userQuantity	Item quantity							//
//  Function Call Arguments: None											//
//  Returns: userQuantity							    					//
/****************************************************************************/
int getUserQuantity(){
	int userQuantity = -1;
	do{
		cin >> userQuantity;
		if (cin.fail() || cin.peek() != '\n'){
			cin.clear();
			cin.ignore(100,'\n');
			userQuantity = -1;
			continue;
		} else {
			return userQuantity;
		}
	} while (userQuantity < 0);
	return userQuantity;
}
