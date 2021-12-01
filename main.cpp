#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "gamefunc.h"

using namespace std;

int main() {

	do {
		system("cls");
		cout << "Typing Game" << endl;
		cout << "---------------------------------------" << endl;
		cout << "produced by Jong Seung Lee & Min Jae Jo" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Menu" << endl;
		cout << "1 Start Game" << endl;
		cout << "2 Instructions" << endl;
		cout << "3 Saved Record" << endl;
		cout << "4 Delete Saved" << endl;
		cout << "5 End game" << endl;
		cout << "Select Number: ";
		char option = getche();

		switch (option)
		{
		case '1':game(); main(); break;
		case '2':help(); main(); break;
		case '3':savedrecord(); main(); break;
		case '4':deletesave(); main(); break;
		case '5':return 0; break;
		default:main();
		}
	} while (1);
}
