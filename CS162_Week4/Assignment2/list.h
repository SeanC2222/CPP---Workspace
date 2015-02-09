#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>
#include "item.h"

class List {

   private:
      std::vector< Item > itemList;
      std::string listName;
   public:
      List();
      List(Item);
      void setListName(std::string);
      void addItem(Item);
      std::vector< Item >& getList();
      Item* getItem(int);
      int getListSize();
      std::string getListName();
};

#endif

