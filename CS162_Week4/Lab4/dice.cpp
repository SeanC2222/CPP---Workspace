#include <cstdlib>
#include <ctime>
class Dice
{
   public:
      Dice();
      Dice(int numSides);
      virtual int rollDice() const;
   protected:
      int numSides;
};

class LoadedDice : public Dice{
   public:
      LoadedDice();
      LoadedDice(int numSides);
      virtual int rollDice() const;
};
	

Dice::Dice()
{
   this->numSides = 6;
   srand(time(NULL));// Seeds random number generator 
}

Dice::Dice(int numSides)
{
   this->numSides = numSides;
   srand(time(NULL));// Seeds random number generator 
}

int Dice::rollDice() const
{
   return (rand() % numSides) + 1;
}

// Take two dice objects,
// roll them, and return the sum 
int rollTwoDice(const Dice& die1, const Dice& die2)
{
   return die1.rollDice() + die2.rollDice();
}

LoadedDice:: LoadedDice()
{
   this->numSides = 6;
   srand(time(NULL));// Seeds random number generator 
}

LoadedDice::LoadedDice(int numSides)
{
   this->numSides = numSides;
   srand(time(NULL));// Seeds random number generator 
}

int LoadedDice::rollDice() const
{
   int temp = rand() % 10;
   if (temp >= 5){
      return this->numSides;
   } else {
      if (this->numSides == 1){
	 return this->numSides;
      } else {
	 return (rand() % (this->numSides-1)) + 1;
      }
   }
}
