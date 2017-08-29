#include <stdio.h>

void main()
{
	int i, j, k;
	int line;
	
	scanf_s("%d", &line);

	for (i = 1; i<line+1; i++)
	{
		for (j = 0; j < line-i; j++)
		{
			printf(" ");
		}

		for (k = 0; k < i * 2 - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}