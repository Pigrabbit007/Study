#include <stdio.h>

void main()
{

	for (int i = 6; i > 0; i -= 2)
	{
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}