#include <stdio.h>
#include <iostream>

using namespace std;

#define INF 100

void optsearchtree(int, float *, float &, int **);
float minimum(int, float *, int *);
float sum(int, int, float *);

void main()
{
	int i, num, **r;
	char **key;
	float avg, *p;

	printf("키 갯수 입력 : ");
	scanf("%d", &num);

	p = new float[num + 1];

	key = new char *[num + 1];
	for (i = 0; i < num + 1; i++)
		key[i] = new char[10];

	r = new int *[num + 2];
	for (i = 0; i < num + 2; i++)
		r[i] = new int[num + 1];

	printf("키 값 입력 : ");
	for (i = 1; i <= num; i++)
		cin >> key[i];

	printf("키 값 검색 빈도 입력 : ");
	for (i = 1; i <= num; i++)
	{
		scanf("%f", &p[i]);
	}

	optsearchtree(num, p, avg, r);

	printf("\n\nR\n");
	for (i = 1; i < num + 2; i++)
	{
		for (int j = 1; j < num + 1; j++)
			if (i>j) printf("        ");
			else printf("%8d", r[i][j]);
			printf("\n");
	}

	printf("평균 검색시간 : %f\n", avg);
	cout << "최상위 노드 : " << key[r[1][num]] << "\n";

}

void optsearchtree(int n, float *p, float &minavg, int **R)
{
	int i, j, k, diag;
	float **A, *temp;

	temp = new float[n];

	A = new float *[n + 2];
	for (i = 0; i < n + 2; i++)
		A[i] = new float[n + 1];

	for (i = 1; i <= n; i++)
	{
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
		temp[i] = INF;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;

	for (diag = 1; diag <= n - 1; diag++)
		for (i = 1; i <= n - diag; i++)
		{
		j = i + diag;
		for (k = i; k <= j; k++)
			temp[k] = A[i][k - 1] + A[k + 1][j];
		k = 1;
		A[i][j] = minimum(n, temp, &k) + sum(i, j, p);
		R[i][j] = k;
		}

	printf("\n\n             A\n");
	for (i = 1; i<n + 2; i++)
	{
		for (int j = 1; j<n + 1; j++)
			if (i > j) printf("    ");
			else  printf("%.2lf    ", A[i][j]);
			printf("\n    ");
	}

	minavg = A[1][n];
}

float minimum(int n, float *temp, int *k)
{
	float min;
	min = temp[1];
	for (int i = 2; i <= n; i++)
		if (min > temp[i])
		{
		min = temp[i];
		*k = i;
		}
	for (int i = 0; i <= n; i++)
		temp[i] = INF;

	return min;
}

float sum(int i, int j, float *p)
{
	float total = 0;

	for (int a = i; a <= j; a++)
		total += p[a];

	return  total;
}