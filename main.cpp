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


#define DELAY 5000 // 바꿔야됨  


using namespace std;

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
		x = 조건; 단어 입력 똑같아야됨;    // 
		old_time = clock();    // 시작 시간 
        	use_inp = 1;         // 키입력 초기값 
 
        	printf(x,y);
 
        do{ 
            new_time = clock();    // 현재 시간 
            if (difftime(later_time, first_time) > DELAY) {    // 시간 초과 검사, 딜레이로 시간 바꿔야됨
                ans = 0;        // 답이 없음 
                use_inp = 0;        // 키입력이 없음 
                break;
            }
        } while (!kbhit());        // 키가 안 눌린 동안 
 
 
        if (use_inp == 1) scanf("%d", &answer);    // 답을 받음 
    
        if(sum == answer){
            printf("Correct");
        }
        else{
            printf("Incorrect, \n total correct is \n", sum, yes);
            return 0;
        } 
        yes++;    // 정답수 
}
