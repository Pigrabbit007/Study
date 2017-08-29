#include <stdio.h>
#define YESTERDAY day[3]
#define TODAY day[4]
#define TOMORROW day[5]

void main()
{
	int day[7] = { 1, 2, 3, 4, 5, 6, 7 };

	if (YESTERDAY == TOMORROW)
		TODAY = 5;

	printf("%d", TODAY);



}