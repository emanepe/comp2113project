#ifndef GAMEFUNC_H
#define GAMEFUNC_H

//function to measure current user accuracy
void accuracy() {
	int c_word;
	int inc_word = 0;
	if (c_word != g_word)
		++inc_word;

	accuracy = g_word - inc_word; //incorrect word 
	accuracy = accuracy / g_wordTotal; //전체 게임출제단어 array 크기구해서 나누기
	accuracy = accuracy * 100;

}

//function to measure user typing speed
void typingspeed() {
	using Clock = chrono::high_resolution_clock;
	cout << "Type: ";
	cin >> string answer;
	auto start = Clock::now();
	cin >> answer;
	auto end = Clock::now();
	auto s = chrono::duration_cast<chrono::seconds>(end - start).count();

	cout << "You took " << s << " seconds" << endl;  //print user input time for the previous chance
}
}

//help() is to show the instructions of the game
void help() {
	system("cls");
	cout << "This is a game designed to improve your typing speed." << endl;
	cout << "User can select appropriate difficulties with different time limits." << endl;
	cout << "User can also choose numbers of word to challenge. (20, 30, 40 words)" << endl;
	cout << "User has to type a given word within time limit, maintaining certain level of accuracy." << endl;
	cout << "User can also view their highest record, and this can be reset if the user want." << endl;
	cout << "Please enjoy and type any key to exit: ";
	getche();
}

//saverecord() can display user's highest score, acculmulative average accuracy, average typing speed.
void savedrecord() {
	FILE *fp2 = NULL;
	double s;
	int cnt;
	system("cls");
	printf("[ 점수 ]\n\n\n");
	fp2 = fopen("score.txt", "r");
	if (fp2 == NULL) // 파일 열기 오류
		printf("한번도 게임을 하신적이 없거나,\n점수 파일을 불러오는데 문제가 있습니다.\n");
	else
	{
		cnt = 1;
		while (EOF != fscanf(fp2, "%lf", &s))
		{
			printf("%d. %.2lf초\n", cnt, s);
			cnt++;
		}
	}
	printf("\n\n아무키나 누르면 메인메뉴로 이동합니다.");
	getch();
}

void deletesave() {
	//tranche
}

void game() {
	int timelimit;
	int word = 30;

	//Difficulty setting (adjusting time limit for each word)
	system("cls");
	cout << "Select difficulty of the game:" << endl;
	cout << "1 Easy" << endl;
	cout << "2 Intermediate" << endl;
	cout << "3 Hard" << endl;
	cout << "4 Extremely Hard" << endl;
	cout << "Select Number: "
	char difficulty = getche();
	switch (difficulty)
	{
	case '1':timelimit = 1; break;
	case '2':timelimit = 2; break;
	case '3':timelimit = 3; break;
	case '4':timelimit = 4; break;
	default:game();
	}

	//Word number setting (default: 30 words, can be varied to 20 or 40)
	system("cls");
	cout << "Select numbers of words you want to challenge:" << endl;
	cout << "1 20 words" << endl;
	cout << "2 30 words" << endl;
	cout << "3 40 words" << endl;
	cout << "Select Number: "
	char userword = getche();
	switch (userword)
	{
	case '1':word = 20; break;
	case '2':word = 40; break;
	default:break;
	}

	//File input of the word lists - 520 words(20 words for each alphabet) - use of dynamic array
	ifstream fin("input.txt");
	vector<string> wordlist;
	string word;
	while (getline(fin, word))
		wordlist.push_back(word);

	//Initialize user progress variables
	int totalword = 0;
	int correctword = 0;
	float totaltime = 0;
	float starttime, endtime;

	//boolean variable to determine whether it is game over or stage success from the user
	bool success = false;

	//Actual game function
	do{
		system(:"cls");
		starttime = clock(); //record starting time
		int randindex = rand() % wordlist.size(); //randomly select index to choose a word to test
		string testingt = wordlist(randindex);

		cout << testingt << endl;
		string userinput;
		do {
			float point = clock() / CLOCKS_PER_SEC;
			if ((point - starttime) >= timelimit)
				break;
		} while (input 받을때까지); //apply time limit while user input (다시 돌아와서 구현)
		if () {
			
		}
		else {
			
		}


		endtime = clock() - starttime;
		delay(1sec);
	} while (); //termination condition ()

	system("cls");
	cout << "Game Over" << endl;
	fp = fopen("score.txt", "a"); // 점수 저장 파일 열기
	if (fp == NULL) // 파일 열기 오류
		printf("점수 기록 파일 작성 실패!\n\n");
	else
	{
		fprintf(fp, "%.2lf\n", sec); // 점수 기록
		fclose(fp);
	}
	printf("아무키나 누르면 메인메뉴로 이동합니다.\n");
	printf("메인메뉴가 나타나지 않으면 한번 더 입력해주세요.");
	getch();
}

#endif
