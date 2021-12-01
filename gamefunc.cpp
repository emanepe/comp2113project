#ifndef GAMEFUNC_H
#define GAMEFUNC_H

//function to calculate current user score
void score(){

}

//function to measure current user accuracy
void accuracy(){
	int c_word;
	int inc_word = 0;
	if (c_word != g_word)
		++inc_word;
	
	double accuracy;
	accuracy=0;
	
	accuracy=g_size-inc_word;
	accuracy=accuracy/g_word;
	accuracy=accuracy*100;
	
}

//function to measure user typing speed
void typingspeed(){
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
void help(){
  system("cls");
  cout << "This is a game designed to improve your typing speed." << endl;
  cout << "User can select appropriate difficulties with different time limits." << endl;
  cout << "User can also choose numbers of word "<< endl;
  cout << "User has to type a given word within time limit, maintaining certain level of accuracy." << endl;
  cout << "User can also view their highest record, and this can be reset if the user want." << endl;
  cout << "Please enjoy and type any key to exit: ";
  getche();
}

//saverecord() can display user's highest score, acculmulative average accuracy, average typing speed.
void savedrecord(){
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

//sets time limit for playing game
void set_time() {
	int ch;
	system("cls");
	pos;
	printf("Set the difficulty(time):");
	pos;
	ln
	pos;
	pos;
	printf("press 1 for Easy") ;pos;
	printf("press 2 for Intermediate"); pos;
	printf("press 3 for Hard");pos;
	printf("press 4 for Extremely Hard");pos;
	scanf("%d",&ch);
	switch(ch){
		case 1:t=30;break;
		case 2:t=20;break;
		case 3:t=10;break;
		case 4:t=5;break;
		default:set_time();
	}
}

void deletesave(){

}

void game(){
  int level, diff, accuracy=0, score=0, count=0;
  clock_t begin;
  int time_spent, speed;
  system("cls");
  cout << "Select Difficulty of the game:" << endl;
  cout << "1 Easy" << endl;
  cout << "2 Intermediate" << endl;
  cout << "3 Hard" << endl;
  cout << "4 Extremely Hard" << endl;
  cout << "Select Number: "
  char difficulty = getche();
  switch(difficulty)
  {
    case '1':diff=1;break;
    case '2':diff=2;break;
    case '3':diff=3;break;
    case '4':diff=4;break;
    default:game();
  }
  system("cls");
  cout << "Select numbers of words you want to challenge:" << endl;
  while(){
		//Actual game
	}
	
	system("cls");
	cout<<"Game Over"<<endl;
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
