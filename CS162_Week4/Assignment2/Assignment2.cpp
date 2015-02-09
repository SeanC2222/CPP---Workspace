/* Program Filename: Assignment2.cpp
 * Author: Sean C. Mulholland
 * Date: 1/30/15
 * Description: This program allows the user to create a number of grocery lists
 *   and save them for viewing later. It also allows the user to modify lists
 *   and delete saved lists that are no longer desired.
 *
 * Input: User input to fill in fields
 *        Requires a file "lists.txt" to be present in local directory
 *
 * Output: Outputs information to console
 *	   Outputs saved "***.txt" files to local directory
 *
 * ***************************************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
#include <fstream>

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "item.h"
#include "list.h"

void clearScreen(){for(int i = 0; i < 100; i++) {cout << endl;}}
void displayMenu();
string getChoice();

void startProg(string);

void createNewList();
Item createItem();
void saveList(List&);

void viewLists();
void displayList(List&);

void removeList();
void modifyList(List&);
string getListName();
List readListFromFile(string);

/* Function: Main
 * Description: houses the main menu and calls method for starting program 
 * Parameters: none
 * Pre-Conditions: "lists.txt" file in local directory
 * Post-Conditions: none
 */
int main(){

   string choice;
   //Runs the Main Program
   do{
      clearScreen();
      displayMenu();
      choice = getChoice();
      startProg(choice);
   } while (choice != "quit" && choice != "5");

   return 0;

}

/* Function: displayMenu()
 * Description: Displays starting menu to user
 * Parameters: None
 * Pre-Condition: None
 * Post-Condition: None
 */
void displayMenu(){

   cout << "Main Menu\n"
        << "\n"
        << "1) Create a new Shopping List\n"
        << "2) View a saved Shopping List\n"
        << "3) Remove a List\n"
        << "4) Modify a Saved List\n"
        << "5) Quit\n" << endl;
   cout << "What would you like to do?";
   return;
}

/* Function: getChoice()
 * Description: gets user choice, removes spaces, and sets characters to 
 *	        to lowercase to meet a common format.
 * Parameters: None
 * Pre-Conditions: User must be explained their choice options
 * Post-Conditions: Returns a formatted string to calling function
 */
string getChoice(){

   string choice;
   getline(cin, choice);

   for (unsigned i = 0; i < choice.length(); i++){
      choice.at(i) = tolower(choice.at(i));
      if (choice.at(i) == ' '){
	 choice.erase(i,1);
	 i--;
      }
   }
   return choice;
}

/* Function: startProg(string)
 * Description: Executes functions based on menu choices
 * Parameters: string choice - Used for picking which function to run
 * Pre-Condition: A string of any length is being passed
 * Post-Condition: The function described by string choice is run or
 *		   the function outputs that the choice was bad.
 */
void startProg(string choice){

   if (choice == "1" || choice == "create"){
      createNewList();

   } else if (choice == "2" || choice == "view"){
      string listName = getListName();
      List viewList = readListFromFile(listName);
      if (listName == "quit")
	 return;
      displayList(viewList);

      cout << "\nPress enter to return to menu." << endl;
      cin.ignore(100,'\n');

   } else if (choice == "3" || choice == "remove"){
      removeList();

   } else if (choice == "4" || choice == "modify"){
     string temp = getListName();
     if (temp == "quit")
	 return;
      List modList = readListFromFile(temp);
      modifyList(modList);

   } else if (choice == "5" || choice == "quit"){
      return;

   } else {
      cout << "Not a valid choice. Press enter to try again.";
      cin.ignore(100,'\n');
   }

   return;
}

/* Function: createNewList()
 * Description: Creates a new "List" to store item information in
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A list is generated and saved to a .txt file
 */
void createNewList(){

   //New List object
   List newItemList;

   //user choice variable
   string choice;

   //Gets list name
   cout << "What would you like to name this list?";
   getline(cin, choice);

   //Sets name in object
   newItemList.setListName(choice + ".txt");
   
   //Modifies list object until user is satisfied
   do{
      modifyList(newItemList);
      clearScreen();
      displayList(newItemList);
      cout << "Add another item to your list?";
      choice = getChoice();
   }while (choice != "quit" && choice != "no" && choice != "n");

   //Saves list to .txt file
   saveList(newItemList);
   return;
}

/* Function: createItem()
 * Description: Creates an item object and populates it's data elements
 * Parameters: None
 * Pre-Condition: Function call must be set to assign to an item
 * Post-Condition: Function returns Item object with user defined elements
 */
Item createItem(){
   //New Item
   Item newItem;

   //used for various string functions
   string temp;

   //Gets item name or creates blank object and returns blank
   cout << "What is the item's name?";
   getline(cin, temp);
   if (temp == "quit"){
      Item blank;
      return blank;
   }
   //Sets item name in object
   newItem.setName(temp);

   //Gets item unit of measure or creates blank object and returns blank
   cout << "What units are used to measure the item? (lbs., oz., cans, etc.)";
   getline(cin, temp);
   if (temp == "quit"){
      Item blank;
      return blank;
   }
   //Sets item unit type
   newItem.setUnitType(temp);
   
   //Gets item quantity and ensures that it is valid
   do{
      cout << "How many units of the item do you need?";
      getline(cin, temp);
      //Creates blank item and returns blank item
      if (temp == "quit"){
	 Item blank;
	 return blank;
      }
      //If the string can be converted, sets Item Quantity
      if (atof(temp.c_str())){
	 newItem.setQuantity(atof(temp.c_str()));
      }
   } while (!atof(temp.c_str()));

   //Gets item price per unit and ensurs that it is valid
   do{
      cout << "What is the price per unit?";
      getline(cin, temp);
      //Creates blank item and returns blank item
      if (temp == "quit"){
	 Item blank;
	 return blank;
      }
      //If the string can be converted, sets Item Price
      if (atof(temp.c_str())){
	 newItem.setPrice(atof(temp.c_str()));
      }
   } while (!atof(temp.c_str()));
   //returns newItem to function call
   return newItem;
}

/* Function: displayList(List&)
 * Description: Takes a list by reference, and displays the item contents
 * Parameters: List& l - A list object passed by reference
 * Pre-Conditions: None
 * Post-Conditions: List is output to console
 */
void displayList(List& l){

   //Running list total
   double subTotal = 0.0;

   //Sets Format for Table listing
   cout << std::setw(16) << std::right << "Name|"
        << std::setw(12) << std::right << "Quantity|"
        << std::setw(13) << std::right << "Unit Type|"
        << std::setw(11) << std::right << "Price|"
        << std::setw(9) << std::right << "Subtotal" << endl;

   //Sets precision values for floats
   cout << std::setprecision(2) << std::fixed << std::showpoint;

   //Outputs list item information in a table
   for (int i = 0; i < l.getListSize(); i++){
      cout << std::setw(3) << std::left << i+1;
      cout << std::setw(12) << std::right 
	   << l.getItem(i)->getName() << "|"
	   << std::setw(11) << std::right 
	   << l.getItem(i)->getQuantity() << "|"
	   << std::setw(12) << std::right 
	   << l.getItem(i)->getUnitType() << "|"
	   << std::setw(10) << std::right 
	   << l.getItem(i)->getPrice() << "|"
	   << std::setw(9) << std::right 
	   << l.getItem(i)->getQuantity() * l.getItem(i)->getPrice()
	   << endl;
      subTotal += l.getItem(i)->getSubtotal();
   }
   cout << std::setw(53) << std::right << "Subtotal: " 
        << std::setw(8) << std::right << subTotal << endl;
   return;
}

/* Function: saveList(List&)
 * Description: Saves a user list to a .txt file
 * Parameters: List& itemList - Reference to a list object
 * Pre-Conditions: List must be ready to be saved
 *		   "lists.txt" must be in local directory
 * Post-Conditions: List contents are saved to a .txt file in readable format
 */
void saveList(List& itemList){
   
   //Opens ifstream of "lists.txt"
   std::ifstream ifs("lists.txt");
   vector<string> lists;
   string temp;
   //Stores list names in vector lists
   while (getline(ifs,temp)){
      lists.push_back(temp);
   }
   //Closes ifstream
   ifs.close();

   //Opens ofstream to lists.txt
   std::ofstream ofs("lists.txt");
   bool checkIfSaved = false;
   //Adds content back to lists.txt
   for (unsigned i = 0; i < lists.size(); i++){
      ofs << lists[i] << "\n";
      //If list name already exists, set bool trigger
      if (lists[i] == itemList.getListName() && !checkIfSaved){
	 checkIfSaved = true;
      }
   }

   //If List name is new, save the new list title to lists.txt
   if (!checkIfSaved)
      ofs << itemList.getListName() << "\n";

   //close ofstream to lists.txt
   ofs.close();

   //Open ofstream to ***.txt where *** is save list name
   ofs.open(itemList.getListName());

   //Outputs table header
   ofs << std::setw(13) << std::right << "Name|"
        << std::setw(12) << std::right << "Quantity|"
        << std::setw(13) << std::right << "Unit Type|"
        << std::setw(11) << std::right << "Price" << endl;
   //Sets output precision and format for floats
   ofs << std::setprecision(2) << std::fixed << std::showpoint;
   //Outputs list information to ***.txt
   for (int i = 0; i < itemList.getListSize(); i++){
      ofs  << std::setw(12) << std::right 
	   << itemList.getItem(i)->getName() << "|"
	   << std::setw(11) << std::right 
	   << itemList.getItem(i)->getQuantity() << "|"
	   << std::setw(12) << std::right 
	   << itemList.getItem(i)->getUnitType() << "|"
	   << std::setw(10) << std::right 
	   << itemList.getItem(i)->getPrice() << endl;
   }
   return;
}

/* Function: viewLists()
 * Description: Displays which lists are saved
 * Parameters: None
 * Pre-Conditions: "lists.txt" should be in local directory
 * Post-Conditions: None
 */
void viewLists(){

   std::string temp;
   int counter = 1;

   std::ifstream ifs("lists.txt");

   while (getline(ifs,temp)){
      cout << counter << ") " << temp << endl;
      counter++;
   }
      
   ifs.close();
   return;
}

/* Function: removeList()
 * Description: Removes saved list from "lists.txt" and erases the ***.txt file
 * Parameters: None
 * Pre-Conditions: "lists.txt" should be in local directory
 * Post-Conditions: "lists.txt" is updated to remove ***.txt listing
 *		    ***.txt file is removed from system
 */
void removeList(){

   //For user choices and temporary storage
   string choice, temp;

   //Gets lists from "lists.txt" and store in vector "lists"
   std::vector<string> lists;
   std::ifstream ifs("lists.txt");
   int counter = 1;
   while (getline(ifs,temp)){
      lists.push_back(temp);
      counter++;
   }
   ifs.close();

   do{
      //Gets valid list name for removal
      temp = getListName();
      //Allows user to quit
      if (temp == "quit")
	 return;
      //Validates user wants to remove ***.txt
      cout << "Are you sure you want to remove " << temp << "?" << endl;
      choice = getChoice();
      //If user picks "yes" or "y"
      if (choice == "yes" || choice == "y"){
	 //If there is an error removing the list notifies user
	 if(remove(temp.c_str())){
	    cout << "Error deleting list." << endl;
	    cout << "Press enter to continue." << endl;
	 //Else deletes ***.txt
	 } else {
	    cout << temp << " deleted." << endl;
	    std::ofstream ofs("lists.txt");
	    //Outputs remaining lists to "lists.txt" and removes ***.txt
	    for (unsigned i = 0; i < lists.size(); i++){
	       //If not a match, output list name to "lists.txt"
	       if (lists[i].compare(temp)){
		  ofs << lists[i] << endl;
	       //If it is a match, remove from vector lists
	       } else {
		  lists.erase(lists.begin()+i);
		  i--;
	       }
	    }
	    cout << "Press enter to return to main menu." << endl;
	    cin.ignore(100,'\n');
	    return;
	 }
      }
   } while (choice != "quit");

   return;
}
/* Function: modifyList(List&)
 * Description: Modifies list reference that is passed to it by adding
 *	        or removing items.
 * Parameter: List& modList - list to be modified
 * Pre-Conditions: valid list object to be modified
 * Post-Conditions: Saves updated list to local directory
 */
void modifyList(List& modList){
   //Clears screen
   clearScreen();
   //Displays current list contents
   displayList(modList);
   //Prompts user on what to do
   cout << "\nWhat would you like to do?\n\n"
        << "1) Add an Item.\n"
        << "2) Remove an Item\n"
        << "3) Return to main menu\n" << endl;
   //Gets user choice and stores it
   string temp = getChoice();
   //Chooses appropriate function call from user choice
   //If "1" or "add" add an item to list
   if (temp == "1" || temp == "add"){
      modList.addItem(createItem());
   //Else if "2" or "remove" remove an item from the list
   } else if (temp == "2" || temp == "remove"){
      clearScreen();
      displayList(modList);
      cout << "Which item should be removed?";
      temp = getChoice();

      if (temp == "quit"){
	 return;
      }
      //Converts string input to integer and removes item
      if (atoi(temp.c_str())){
	 int removeIndex = atoi(temp.c_str())-1;
	 modList.getList().erase(modList.getList().begin()+removeIndex);
      } else {
	 for (unsigned i = 0; i < modList.getList().size(); i++){
	    if (temp == modList.getItem(i)->getName()){
	       modList.getList().erase(modList.getList().begin()+i);
	    }
	 }
      }
   //Else if "3" or "return" or "quit" returns to functino call
   } else if (temp == "3" || temp == "return" || temp == "quit"){
      return;

   } else {
      cout << "Invalid entry. Try again." << endl;
      cout << "Press enter to continue.";
      cin.ignore(100,'\n');
   }
   saveList(modList);
}

/* Function: getListName()
 * Description: gets list name from the user and validates existence
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: Returns a valid list name in a string
 */
string getListName(){
   string temp;
   //Populates vector lists with list names from "list.txt"
   std::ifstream listFS;
   std::vector<string> lists;
   std::ifstream ifs("lists.txt");
   int counter = 1;
   while (getline(ifs,temp)){
      lists.push_back(temp);
      counter++;
   }
   ifs.close();
   //If there are no lists in "lists.txt" return "quit"
   if (lists.size() == 0){
      cout << "There are no lists currently." << endl;
      cout << "Press enter to return to the menu." << endl;
      cin.ignore(100,'\n');
      return "quit";
   }
   //If there are lists in "lists.txt" get choice of list
   do{
      clearScreen();
      cout << "Which list would you like to select?"<< endl;
      cout << "Type \"quit\" to return to the main menu.\n" << endl;

      viewLists();

      getline(cin, temp);
      //If user wants to quit, returns quit
      if (temp == "quit")
	 return "quit";
      //Converts integers to valid string names      
      if (atoi(temp.c_str()) && unsigned(atoi(temp.c_str())) <= lists.size()){
	 temp = lists[atoi(temp.c_str())-1];
      }
      //Validates that string name opens a file
      listFS.open(temp);
   } while (listFS.fail());
   //Closes file
   listFS.close();
   return temp;
}

/* Function: readListFromFile(string)
 * Description: Reads a file of information, builds separate Item Objects
 *	        and builds a list object of the items.
 * Parameters: string fileName - The file you want to generate a list from
 * Pre-Conditions: Valid format of file to read from.
 * Post-Conditions: Returns list object to function call
 */
List readListFromFile(string fileName){
   //Creates list object
   List modList;
   //Sets list name
   modList.setListName(fileName);
   //Opens ifstream to ***.txt file
   std::ifstream listFS(fileName);
   //100 character c-string
   char* str;
   str = new char[100];
   //Clears header from ifstream
   listFS.get(str,100,'\n');
   listFS.get();
   //While not the end of file, build temp Items and populate a list object
   while (listFS.peek() != -1){
      Item tempItem;
       
      for (int i = 0; i < 100; i++){
	 *(str+1) = '\0';
      }
      //Gets/Sets Name
      listFS.get(str, 100,'|');
      listFS.get();
      tempItem.setName(str);
      //Gets/Sets Quantity
      listFS.get(str, 100,'|');
      listFS.get();
      tempItem.setQuantity(atof(str));
      //Gets/Sets Unit type
      listFS.get(str, 100,'|');
      listFS.get();
      tempItem.setUnitType(str);
      //Gets/Sets Price
      listFS.get(str, 100,'\n');
      listFS.get();
      tempItem.setPrice(atof(str));
      //Add tempItem to list object
      modList.addItem(tempItem);
   }
   //Close stream and set str to NULL
   listFS.close();
   str = NULL;   
   //Return list object
   return modList;
}
