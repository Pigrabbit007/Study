#define MAX_SIZE 3
#define CMD_QUIT 2
#define CMD_START 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int guesswhat[MAX_SIZE] = { 0 };
int usrhit[MAX_SIZE] = { 0 };
int trials = 0;
int get_strike(int * answer, int * user);
int get_ball(int * answer, int * user);
int create_num();
int create_game();
int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		int cmd;
		printf("ㅡㅡㅡㅡㅡㅡㅡGame start !ㅡㅡㅡㅡㅡㅡㅡ\n");
		printf("            1. start game !\n");
		printf("            2. quit game !\n");
		printf("            select menu! : ");
		scanf_s("%d", &cmd);
		if (cmd == CMD_QUIT)
		{
			printf("ㅡㅡㅡㅡㅡㅡㅡHave a nice day!ㅡㅡㅡㅡㅡ\n");
			break;
		}
		create_game();
		if (cmd == CMD_START)
		{
			while (1)
			{
				int strikes;
				int balls;
				int i;
				printf("\nGuess what? Input %d digit number!\n", MAX_SIZE);
				for (i = 0; i < MAX_SIZE; i++)
				{
					scanf_s("%d", &usrhit[i]);
				}
				trials++;
				balls = get_ball(guesswhat, usrhit);
				strikes = get_strike(guesswhat, usrhit);
				if (strikes == 0 && balls == 0)
					printf("out! \n");
				else if (strikes == 3)
				{
					printf("you win! \n");
					printf("The final number of trials is %d\n", trials);
					break;
				}
				else
					printf("%d s - %d b\n", strikes, balls);
				printf("The number of trials is %d", trials);
			}
		}
	}
	return 0;
}
int get_strike(int * answer, int * user)
{
	int i;
	int cnt = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (answer[i] == user[i])
			cnt++;
	}
	return cnt;
}
int get_ball(int * answer, int * user)
{
	int i, j;
	int cnt = 0;
	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++)
		{
			if (i != j && answer[i] == user[j])
				cnt++;
		}
	}
	return cnt;
}
int create_num()
{
	int rand_num;
	int i;
	int already_exist;

	//srand(0);
	while (1)
	{
		already_exist = 0;
		rand_num = rand() % 9 + 1;
		for (i = 0; i < MAX_SIZE; i++)
		{
			if (guesswhat[i] == rand_num)
				already_exist = 1;
		}
		if (already_exist != 1)
		{
			return rand_num;
		}
	}

	//사용 가능
}

int create_game()
{
	int i;
	int rand_num;
	for (i = 0; i < MAX_SIZE; i++)
	{
		guesswhat[i] = create_num();
	}
	trials = 0;

	return trials;
}