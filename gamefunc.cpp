//all of the functions

//help() is to show the instructions of the game
void help() {
	system("cls");
	cout << "This is a game designed to improve your typing speed." << endl;
	cout << "User can select appropriate difficulties with different time limits." << endl;
	cout << "User can also choose numbers of word to challenge. (20, 30, 40 words)" << endl;
	cout << "User has to type a given word within time limit, maintaining certain level of accuracy." << endl;
	cout << "User can also view their highest record, and this can be reset if the user want." << endl;
	cout << "Please enjoy and type any key to exit: ";
	getchar();
}

//saverecord() can display acculmulative average accuracy, average typing speed.
void savedrecord() {
	ifstream fin("output.txt");
	int storedtotal, storedcorrect;
	float storedtime;
	fin >> storedtotal >> storedcorrect >> storedtime;
	int accuracy = (storedcorrect / storedtotal) * 100;
	int typingspeed = storedtotal / storedtime;

	cout << endl;
	cout << "User Cumulative Performance" << endl;
	cout << "---------------------------" << endl;
	cout << "Cumulative average accuracy of the user: " << accuracy << endl;
	cout << "Average typing speed of the user: " << typingspeed << endl;
	fin.close();
	cout << "Please enjoy and type any key to exit: ";
	getchar();
}

void deletesave() {
	ofstream fout("output.txt", std::ios::out | std::ios::trunc);
	fout.close();
	getchar();
}

void game() {
	
	int word = 30;
	//Word number setting (default: 30 words, can be varied to 20 or 40)
	system("cls");
	cout << "Select numbers of words you want to challenge:" << endl;
	cout << "1 20 words" << endl;
	cout << "2 30 words" << endl;
	cout << "3 40 words" << endl;
	cout << "Select Number: "
	char userword = getchar();
	switch (userword)
	{
	case '1':word = 20; break;
	case '2':word = 40; break;
	default:break;
	}

	//File input of the word lists - 520 words (20 words for each alphabet) - use of dynamic array
	ifstream fin("input.txt");
	vector<string> wordlist;
	string word;
	while (getline(fin, word))
		wordlist.push_back(word);

	//Initialize user progress variables
	int totalword = 0;
	int correctword = 0;
	float totaltime = 0;
	int accuracy, typingspeed;
	float starttime, timediff;

	//counter variable to determine whether it is game over or stage success from the user
	int success = 0;

	//Actual game function
	do{
		system(:"cls");
		starttime = clock(); //record starting time
		int randindex = rand() % wordlist.size(); //randomly select index to choose a word to test
		string testingt = wordlist(randindex);

		cout << testingt << endl;
		string userinput;
		cin >> userinput;
		timediff = clock() - starttime;

		int counter = 0; //counting correct characters
		if (testingt.length() == userinput.length()) { //if the user input is same length with word to test
			totalword += testingt.length();
			for (int i = 0; i < testingt.length(); i++) {
				if(testingt[i] == userinput[i])
					correctword++;
			}
		}
		else if (testingt.length() > userinput.length()) { //if the user input is shorter than word to test
			totalword += testingt.length();
			for (int i = 0; i < testingt.length(); i++) {
				if (testingt[i] == userinput[i] && i < userinput.length())
					correctword++;
			}
		}
		else { //if the user input is longer than word to test
			totalword += userinput.length();
			for (int i = 0; i < testingt.length(); i++) {
				if (testingt[i] == userinput[i])
					correctword++;
			}
		}
		counter++;

		totaltime += timediff;
		accuracy = (correctword / totalword) *100;
		typingspeed = totalword / timediff;

		cout << endl;
		cout << "Cumulative average accuracy of the session: " << accuracy << endl;
		cout << "Average typing speed of the session: " << typingspeed << endl;
		cout << "Time taken for this word: " << timediff << endl;
		delay(1sec); // 여기 다시 보기
	} while (accuracy < 70 || counter < word); //termination condition - if accuracy falls below 70% or user finish all set of words

	system("cls");
	if (counter < word) { //if-else statement determinining game over by accuracy or stage clear finishing whole set of words
		cout << "Game Over" << endl;
	}
	else {
		cout << "Stage Clear" << endl;
	}
	cout << endl;
	cout << "Result of this session" << endl;
	cout << "----------------------" << endl;
	cout << "Cumulative average accuracy of the session: " << accuracy << endl;
	cout << "Average typing speed of the session: " << typingspeed << endl;
	cout << "Time taken for whole session: " << totaltime << endl;

	fstream file("output.txt");
	if (file == NULL) {
		file << totalword << " " << correctword << " " << totaltime;
		file.close();
	}
	else {
		int storedtotal, storedcorrect;
		float storedtime;
		file >> storedtotal >> storedcorrect >> storedtime;
		file.close();
		ofstream fout("output.txt", std::ios::out | std::ios::trunc);
		storedtotal += totalword;
		storedcorrect += correctword;
		storedtime += totaltime;
		fout << storedtotal << " " << storedcorrect << " " << storedtime;
	}

	printf("아무키나 누르면 메인메뉴로 이동합니다.\n");
	printf("메인메뉴가 나타나지 않으면 한번 더 입력해주세요.");
	getchar();
}
