#include <iostream>
#include "gamefunc.h"

using namespace std;

int main() {
	bool run = true;
	do {
		system("clear");
		cout << "############# Typing Game #############" << endl;
		cout << "---------------------------------------" << endl;
		cout << "produced by Jong Seung Lee & Min Jae Jo" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Menu" << endl;
		cout << "1 Start Game" << endl;
		cout << "2 Instructions" << endl;
		cout << "3 Saved Record" << endl;
		cout << "4 Delete Saved" << endl;
		cout << "5 End game" << endl;
		cout << "Select Number:" << endl; //user selecting options, input number 1, 2, 3, 4, 5
		char option = getchar();

		switch (option)
		{
			case '1':game(); break; //load game function
			case '2':help(); break; //load instruction functon
			case '3':savedrecord(); break; //load saved record function
			case '4':deletesave(); break; //load deleting save record function
			case '5':run=false; break; //terminate while loop
			default: break; //ignore the rest
		}
	} while (run); //termination condition: until user select option 5 End game

	return 0;
}
