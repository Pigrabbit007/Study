#include <stdio.h>
#include <malloc.h>

int minmult(int n, int d[], int *P[]);
void order(int i, int j, int *P[]);

void main()
{
	int *d, **P = (int **)malloc(0), num;

	printf("input number of array ");
	scanf("%d", &num);

	d = (int *)malloc(sizeof(int)*num);

	for (int i = 0; i <= num; i++)
	{
		printf("d[%d] = ", i);
		scanf("%d", &d[i]);
	}

	for (int i = 0; i < num; i++)
	{
		P[i] = (int *)malloc(sizeof(int)*num);
	}

	int result = minmult(num, d, P);
	printf("\n\n");
	order(1, num, P);   // 행렬 곱셈 최적 순서 출력
	printf("\n\n");

	for (int i = 0; i < num; i++)
	{
		free(P[i]);
	}
	free(d);
}

int minmult(int n, int d[], int *P[])
{
	int i, j, k, diagnonal, min_k = 0;
	int **M = (int **)malloc(0), temp = 0;

	for (int i = 0; i < n+1; i++)
	{
		M[i] = (int *)malloc(sizeof(int)*n+1);
	}

	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
		{
			M[i][j] = 0;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= n; j++)
		{
			P[i][j] = 0;
		}

	for (diagnonal = 1; diagnonal <= n - 1; diagnonal++)  
		for (i = 1; i <= n - diagnonal; i++) {          
		j = i + diagnonal;                         
		
		for (k = i; k <= j - 1; k++) {
			M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
			if (i == k) {
				temp = M[i][j];
				min_k = k;
			}
			else if (M[i][j] > temp) {
				M[i][j] = temp;
			}
			else
				min_k = k;
		}
		P[i][j] = min_k;    // 최소값을 주는 k의 값
		}

	for (i = 1; i < n; i++)
	{
		printf("\n");
		for (j = 1; j <= n; j++)
		{
				printf("%d ", M[i][j]);
		}

	}

	printf("\n");

	for (i = 1; i < n; i++)
	{
		printf("\n");
		for (j = 1; j <= n; j++)
			printf("%d ", P[i][j]);
	}

	return M[1][n];    // 최소 곱셈 값 리턴
}

void order(int i, int j, int *P[])
{
	int k;
	if (i == j)
		printf("A%d", i);
	else {
		k = P[i][j];
		printf("(");
		order(i, k, P);
		order(k + 1, j, P);
		printf(")");
	}
}