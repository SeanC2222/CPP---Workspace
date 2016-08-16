/* Author: Sean C Mulholland
 * Date: 10/8/2014
 *
 * This program will determine if the number of people attending a meeting
 * will exceed fire regulations. It will accept user input of roomSize
 * and meetingAttendees. It will then compare them and output to the console
 * whether the meeting exceeds regulations or abides by them.
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

	int roomSize,			//Gets max number of people
		meetingAttendees;	//Gets number of attendees


	cout << "This program determines if the number of people\n"
		 << "attending an event will meet or exceed fire regulations.\n"
		 << endl;			//Introduction to the program

	cout << "Please enter the maximum capacity of the room: ";
	cin >> roomSize;		//Prompts user for max number of people

	cout << "Please enter the number of attendees: ";
	cin >> meetingAttendees;	//Prompts user for number of attendees

	if (meetingAttendees <= roomSize){	//Checks if meeting is compliant
		cout << "This meeting meets fire regulations and may be held as planned."
			 << endl; 	//Allows meeting
	} else {
		if (meetingAttendees - roomSize > 1){ //Chooses appropriate response.
			cout << "This meeting has too many people. " << meetingAttendees - roomSize
					<< " people must be uninvited." << endl;
		} else {
			cout << "This meeting has one too many people. One person must be uninvited."
				 << endl;
		}
	}

	return 0;
}
