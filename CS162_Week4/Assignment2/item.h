#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item{
   private:
      std::string name;
      std::string unitType;
      double quantity;
      double price;
   public:
      Item(): name(""), unitType(""), quantity(0.0), price(0.0){} 
      void setName(std::string n){this->name = n;}
      void setUnitType(std::string uT) {this->unitType = uT;}
      void setQuantity(double q) {this->quantity = q;}
      void setPrice(double p) {this->price = p;}
      std::string getName() {return this->name;}
      std::string getUnitType() {return this->unitType;}
      double getQuantity() {return this->quantity;}
      double getPrice() {return this->price;}
      double getSubtotal() {return this->quantity*this->price;}

};

#endif
