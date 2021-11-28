#ifndef GAMEFUNC_H
#define GAMEFUNC_H

//function to calculate current user score
void score(){

}

//function to measure current user accuracy
void accuracy(){

}

//function to measure user typing speed
void typingspeed(){

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
  while()
}

#endif
