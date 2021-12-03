//list of headers needed for our games
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>
#include "gamefunc.h"

using namespace std;

//help() shows the instructions of the game
void help() {
	system("clear");
	cout << "Instructions" << endl;
	cout << "------------" << endl;
	cout << "This is a game designed to improve your typing speed." << endl;
	cout << "User can select appropriate difficulties with different time limits." << endl;
	cout << "User can also choose numbers of word to challenge. (10, 20, 30 words)" << endl;
	cout << "User has to type a given word maintaining at least 70% accuracy." << endl;
	cout << "All inputs Are case sensitive." << endl;
	cout << "User can also view their cumulative record. (can be reset)" << endl;
	cout << "Please enjoy and type 'e' and enter key to exit" << endl;
	char x;
	do{
		cin >> x;
	}while(x != 'e'); //if user type e and enter then go back to main menu
}

//saverecord() can display acculmulative average accuracy, average typing speed.
void savedrecord() {
	system("clear");
	ifstream fin("output.txt"); //load file containing user record
	if (fin.peek() == EOF) { //if the file is empty - which means user haven't played the gaem to produce record
		cout << "No Previous Record" << endl;
		cout << endl;
	}
	else{
		int storedtotal, storedcorrect, storedtime;
		fin >> storedtotal >> storedcorrect >> storedtime;
		int accuracy = storedcorrect * 100 / storedtotal; //accuracy calculation
		int typingspeed = storedtotal * 60 / storedtime; //approx typing speed in characters per minute

		cout << "User Cumulative Performance" << endl;
		cout << "---------------------------" << endl;
		cout << "Cumulative average accuracy of the session: " << accuracy << " percent" << endl;
		cout << "Average typing speed of the session: " << typingspeed << " characters per minute (cpm)" << endl;
		cout << endl;
	}
	fin.close();
	cout << "Type 'e' and enter key to exit" << endl;
	char x;
	do{
		cin >> x;
	}while(x != 'e'); //if user type e and enter then go back to main menu
}

//deletesave() can reset user record of accumulative average accuracy and average typing speed
void deletesave() {
	system("clear");
	cout << "Are you sure? (Please reply with y or n): " << endl;
	char yn;
	cin >> yn;
	if (yn == 'y'){ //only if user typed y
		ofstream fout("output.txt", std::ios::out | std::ios::trunc); //empty the file by truncation
		fout.close();
		cout << endl;
		cout << "Success!"<<endl;
	}
	else {
		cout << "Go back to main menu" << endl;
	}

	cout << "Type 'e' and enter key to exit" << endl;
	char x;
	do{
		cin >> x;
	}while(x != 'e'); //if user type e and enter then go back to main menu
}

//game() is an actual game function for user to play
void game() {
	int wordnum = 20;
	//Word number setting (default: 20 words, can be varied to 10 or 30)
	system("clear");
	cout << "Select numbers of words you want to challenge:" << endl;
	cout << "1 10 words" << endl;
	cout << "2 20 words" << endl;
	cout << "3 30 words" << endl;
	cout << "Select Number: ";
	char userword;
	cin >> userword;
	switch (userword)
	{
	case '1':wordnum = 10; break;
	case '2':wordnum = 30; break;
	default:break;
	}

	//File input of the word lists - we now have 520 words (20 words for each alphabet)
	//We used vector for dynamic memory structure to store all words
	ifstream fin("input.txt");
	vector<string> wordlist;
	string word;
	while (getline(fin, word)){
		wordlist.push_back(word);
	}

	//Initialize user progress variables
	int totalword = 0;
	int correctword = 0;
	float totaltime = 0;
	int accuracy, typingspeed;
	time_t starttime, endtime;

	//counter variable to determine whether it is game over or stage clear from the user
	int counter = 0;

	//Actual game function
	do{
		time(&starttime); //record starting time
		system("clear");
		srand(time(0)); //random seed value setting
		int randindex = rand() % wordlist.size(); //randomly select index to choose a word to test
		string testingt = wordlist[randindex];

		cout << testingt << endl;
		string userinput;
		cin >> userinput;
		time(&endtime); //record ending time
		int testlength = testingt.length() - 1; //exclude whitespace
		if (testlength == userinput.length()) { //if the user input is same length with word to test
			totalword += testlength;
			for (int i = 0; i <= testlength; i++) {
				if(testingt[i] == userinput[i]){
					correctword++; //compare character to find
				}
			}
		}
		else if (testlength > userinput.length()) { //if the user input is shorter than word to test
			totalword += testlength;
			for (int i = 0; i < testlength; i++) {
				if (testingt[i] == userinput[i] && i < userinput.length()){
					correctword++; //compare character til length of user input and the rest of testing word is marked incorrect
				}
			}
		}
		else { //if the user input is longer than word to test //ajik
			totalword += userinput.length();
			for (int i = 0; i < testlength; i++) {
				if (testingt[i] == userinput[i]){
					correctword++;
				}
			}
		}
		counter++;

		totaltime += difftime(endtime, starttime); //total time in seconds
		accuracy = correctword * 100 / totalword; //accuracy in percentage
		typingspeed = totalword * 60 / totaltime; //approx characters per minute

		cout << endl;
		cout << "Cumulative average accuracy of the session: " << accuracy << " percent" << endl;
		cout << "Average typing speed of the session: " << typingspeed << " characters per minute (cpm)" << endl;
		cout << "Time taken for this word: " << difftime(endtime, starttime) << " seconds" << endl;

		chrono::milliseconds duration(1500);
		this_thread::sleep_for(duration);
	} while (accuracy > 70 && counter < wordnum); //termination condition - if accuracy falls below 70% or user finish all set of words

	system("clear");
	if (counter < wordnum) { //if-else statement determinining game over by accuracy or stage clear finishing whole set of words
		cout << "Game Over" << endl;
		cout << "Your accuracy below 70 percent!" << endl; //accuracy below 70% then game over
	}
	else {
		cout << "Stage Clear" << endl; //else it would be stage clear
	}
	cout << endl;
	cout << "Result of this session" << endl;
	cout << "----------------------" << endl;
	cout << "Cumulative average accuracy of the session: " << accuracy << " percent" << endl;
	cout << "Average typing speed of the session: " << typingspeed << " characters per minute (cpm)" << endl;
	cout << "Time taken for whole session: " << totaltime << " seconds" << endl;

	ifstream finn("output.txt");
	if (finn.peek() == EOF) { //if the file is empty then just store current game session record
		ofstream fout("output.txt");
		fout << totalword << " " << correctword << " " << totaltime;
		fout.close();
	}
	else { //else load saved accumulative record value and accumulate the current game session record
		ifstream finnn("output.txt");
		int storedtotal, storedcorrect, storedtime;
		finnn >> storedtotal >> storedcorrect >> storedtime;
		finnn.close();
		ofstream foutt("output.txt", ios::out | ios::trunc); //empty the file first
		storedtotal += totalword;
		storedcorrect += correctword;
		storedtime += totaltime;
		foutt << storedtotal << " " << storedcorrect << " " << storedtime;
		foutt.close();
	}

	cout << "Press 'e' and enter key to go back to main menu: " << endl;
	char x;
	do{
		cin >> x;
	}while(x != 'e');
}
