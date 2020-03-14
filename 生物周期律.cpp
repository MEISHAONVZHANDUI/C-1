#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define PHY 23

#define MOD 28

#define INTE 33

#define D_P_Y 365

/*-->Function declaration<--*/

void inputBirthday(int *birth);

void selectAction();

void SetPos(int x, int y);

int current_Date();

int specific_Date();

void current_Time();

int  leap_Year(int birth, int cur);

void  judge(int total);

/*-->Global variables<--*/

unsigned  int birth[3];

unsigned  int curT[3];

int Days[12]  = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*-->Program  entrance<--*/

int main()

{

	// int i = 0;

	system("color 0F");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);

	printf("Welcome to the human biocycle query system!\nThis is a procedure for querying the human biological cycle.\nNext you need to follow the prompts to enter the relevant information,\n");

	Sleep(800);

	void inputBirthday(int *birth); 

	selectAction();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE);

	printf("\nthe end\n");

	system("pause");

}

/*-->Function body<--*/

void  inputBirthday(int *birth)

{

	printf("\nPlease enter the year in which you were born\n");

	scanf("%d", &birth[0]);

	Sleep(400);

	printf("Please enter the month in which you were born\n");

	scanf("%d", &birth[1]);

	Sleep(400);

	printf("Please enter the day in which you were born\n");

	scanf("%d", &birth[2]);

	Sleep(400);

}

void selectAction()

{

	int  command, total;

	printf("\nPlease select the action you want to take:\n\t(1)Enquiry of today's biological rhythms.\n\t(2)Query the biological rhythm of a specific date\n");

	scanf("%d", &command);

	switch (command)

	{

	case 1:

	{

		total = current_Date();

		break;

	}

	case 2:

	{

		total = specific_Date();

		break;

	}

	}

	judge(total);

}

int current_Date()

{

	printf("\nYou have selected a biological rhythm to query the current date!\n");

	int  total, count;

	current_Time();

	count = leap_Year(birth[0], curT[0]);

	total = (curT[0] - birth[0]) * D_P_Y + count;

	for (count = 1; count < birth[1]; count++)

	{

		total -= Days[count];

	}

	total = total - birth[2] + curT[2];

}

int specific_Date()

{

	int total, count;

	printf("\nYou have selected a biological rhythm to query a specific date\n");

	printf("\nPlease enter the year you want to query:\n");

	scanf("%d", &curT[0]);

	printf("\nPlease enter the month you want to query:\n");

	scanf("%d", &curT[1]);

	printf("\nPlease enter the day you want to query:\n");

	scanf("%d", &curT[2]);

	count = leap_Year(birth[0], curT[0]);

	total = (curT[0] - birth[0]) * D_P_Y + count;

	for (count = 1; count < birth[1]; count++)

	{

		total -= Days[count];

	}

	for (count = 1; count < curT[1]; count++)

	{

		total += Days[count];
			}

	total = total - birth[2] + curT[2];

}

int leap_Year(int birth, int cur)

{

	int  count = 0;

	while (birth < cur)

	{

		if ((birth % 4 == 0 && birth % 100 != 0) || birth % 400 == 0)

		{

			count++;

		}

		birth++;

	}

	return count;

}

void current_Time()

{

	time_t t;

	struct tm *lt;

	time(&t);

	lt = localtime(&t);

	curT[0] = lt->tm_year + 1900;

	curT[1] = lt->tm_mon;

	curT[2] = lt->tm_yday;

}

void SetPos(int x, int y)

{

	HANDLE winHandle;

	COORD pos = {x, y};

	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(winHandle, pos);

}

void judge(int total)

{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");

	printf("Property\t|Count\t|Status\n");

	printf("------------------------------------------------------\n");

	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);

	switch (total % PHY)

	{

	case 0:

	{

		printf("Physics  \t|0\t|Cycle Day\n");

		break;

	}

	case 1 ... 11:

	{

		printf("Physics  \t|%d\t|On day %2d of the climax day\n", total % PHY, (total % PHY));

		break;

	}

	case 12:

	{

		printf("Physics  \t|12\t|On a critical day\n");

		break;

	}

	default:

	{

		printf("Physics  \t|%d\t|%2d day of low tide\n", total % PHY, total % PHY - 12);

		break;

	}

	}

	printf("------------------------------------------------------\n");

	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);

	switch (total % MOD)

	{

	case 0:

	{

		printf("Emotions\t|0\t|Cycle Day\n");

		break;

	}

	case 1 ... 13:

	{

		printf("Emotions\t|%d\t|On day %2d of the climax day\n", total % MOD, (total % MOD));

		break;

	}

	case 14:

	{

		printf("Emotions\t|14\t|On a critical day\n");

		break;

	}

	default:

	{

		printf("Emotions\t|%d\t|%2d day of low tide\n", total % MOD, total % MOD - 14);

		break;

	}

	}

	printf("------------------------------------------------------\n");

	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);

	switch (total % INTE)

	{

	case 0:

	{

		printf("Intellgence\t|0\t|Cycle Day\n");

		break;

	}

	case 1 ... 16:

	{

		printf("Intellgence\t|%d\t|On day %2d of the climax day\n", total % INTE, (total % INTE));

		break;

	}

	case 17:

	{

		printf("Intellgence\t|12\t|On a critical day\n");

		break;

	}

	default:

	{

		printf("Intellgence\t|%d\t|%2d day of low tide\n", total % INTE, total % INTE - 17);

		break;

	}

	}

}
