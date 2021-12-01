#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <chrono>
#include "gamefunc.h"

using namespace std;

int main(){
	int i, j, k;
	cin >> i >> j >> k;
	
	do{
		system("cls");
    	cout << "Speedy Type Game" << endl;
    	cout << "1 Start Game" << endl;
		cout << "2 Instructions" << endl;
		cout << "3 Saved Record" << endl;
    	cout << "4 Delete Saved" << endl;
    	cout << "5 End game" << endl;
		cout << "Select Number: ";
		char option = getche();

    	switch(option)
    	{
      		case '1':game();main();break;
      		case '2':help();main();break;
      		case '3':savedrecord();main();break;
      		case '4':deletesave();main();break;
      		case '5':return 0;break;
      		default:main();
    	}
	}while(1);
}
