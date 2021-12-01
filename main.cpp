#include <iostream>
#include <conio.h> // 못씀 아마
#include <dos.h>
#include <windows.h> //얘도 못씀 아마 
#include <time.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>  
#include <chrono>
#include "gamefunc.h"


using namespace std;


int * ReturnRandomWords(){ //단어추출 바꿔야됨
    string current;
    vector<std::string> WordsFromFile
    ifstream words("word_db.txt");
    do{
        getline(words,current);
        WordsFromFile.push(current);
    }while(!words.eof());
    words.close();
    string v1 = WordsFromFile.at( rand() % WordsFromFile.size());  //if user == line, again 불러오기
    string arr [3] = {v1, v2, v3};
    return arr;
}



int main(){
	int x, y, sum, answer;
	int yes;
	int use_inp;
	time_t later_time, first_time;   
	
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
