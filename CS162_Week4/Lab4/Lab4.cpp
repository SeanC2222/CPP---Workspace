#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cstdlib>
#include <fstream>
#include "dice.cpp"

int main()
{

   std::ofstream ofs ("results.txt");

   int die1Sides, die2Sides;
   cout << "How many sides on your first die?";
   cin >> die1Sides;
   LoadedDice d1(die1Sides);
   cout << "How many sides on your second die?";
   cin >> die2Sides;
   LoadedDice d2(die2Sides);

   int counter = 100000;

   int* numbers;
   numbers = new int[die1Sides + die2Sides];

   char answer;

   do {

      // cout << "Roll number " << ++counter << ": ";
      int diceRoll = rollTwoDice(d1, d2);
      numbers[diceRoll-1]++;
      //cout << diceRoll << endl;
      // cout << "Again?" << endl;
      // answer = cin.get();
		// cin.ignore(100, '\n');
      counter--;
   } while (counter > 0);// tolower(answer) != 'n');

   cout << "Total throws: 100,000" << endl;

   for (int i = 0; i < die1Sides + die2Sides; i++)	{
      cout << "Percent " << i+1 << "\'s: " 
	   << 100.0 * static_cast <double>(numbers[i]) / 100000.0 << endl;
      ofs << 100.0 * static_cast <double>(numbers[i]) / 100000.0 << "\r\n";
   }

   numbers = NULL;
   ofs.close();

   return 0;
}
