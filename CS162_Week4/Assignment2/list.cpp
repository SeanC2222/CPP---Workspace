#include <vector>
#include <string>
#include "item.h"
#include "list.h"

List::List(){
   std::vector<Item> itemList;
   std::string listName = "";
}

List::List(Item I){
   std::vector<Item> itemList;
   itemList.push_back(I);
   std::string listName = "";
}

void List::addItem(Item I){
   itemList.push_back(I);
   return;
}

std::vector< Item >& List::getList(){
   return itemList;
}

Item* List::getItem(int loc){
   return &itemList[loc];
}

int List::getListSize(){
   return itemList.size();
}

std::string List::getListName(){
   return listName;
}

void List::setListName(std::string s){
   listName = s;
   return;
}
