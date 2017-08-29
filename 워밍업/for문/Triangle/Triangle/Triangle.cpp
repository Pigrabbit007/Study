#include <stdio.h>

void main()
{
	int line, i, j, k;

	scanf("%d", &line);

	for (i = 0; i < line+1; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for (i = line + 1; i > 0; i--)
	{
		for (j = 1; j < i; j++)
			printf("*");
		printf("\n");
	}

	for (i = 0; i<line; i++)
	{
		for (k = i; k < line; k++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
	printf("\n");
	}

}