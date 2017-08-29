#include <stdio.h>

void main()
{
	int x[3], h[3], y[5], hi[3];

	for (int i = 0; i < 3; i++)
	{
		printf("x의 %d번째 항을 입력하시오 : ", i + 1);
		scanf("%d", &x[i]);
	}

	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("h의 %d번째 항을 입력하시오 : ", i + 1);
		scanf("%d", &h[i]);
	}

	printf("\n");
	printf("x = ");

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", x[i]);
	}

	printf("\n");

	printf("h = ");

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", h[i]);
	}

	printf("\n\n");

	int j;
	for (int i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			hi[j] = h[i - j];

			if (hi[j] < 0)
			{
				hi[j] = 0;
				printf("%d ", hi[j]);
			}
			else
				printf("%d ", hi[j]);
		}

		y[i] = x[0] * hi[0] + x[1] * hi[1] + x[2] * hi[2];

		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", y[i]);
	}

	printf("\n\n");
}