#include <iostream>
#include <iomanip>
#include <stdio.h>
#define  MAX  100

using namespace std;



void s_tree(int, double *, double &, int **);
double mini(int, double *, int *);
double sum(int, int, double *);


void s_tree(int n, double *P, double &minavg, int **R)
{
	int i, j, k, diag;
	double  *temp, **A;

	temp = new double[n];       // 1차 배열의 동적 할당

	A = new double *[n + 2];       // 2차 배열의 동적 할당
	for (i = 0; i < n + 2; i++)
		A[i] = new double[n + 1];

	for (i = 1; i <= n; i++)   // 배열  A , R  초기화(대각 요소)
	{
		A[i][i - 1] = 0;
		A[i][i] = P[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
		temp[i] = MAX;        // 배열  temp 초기화(무한대 값으로...)
	}

	//	temp[0] = MAX;
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;

	for (diag = 1; diag <= n - 1; diag++)
		for (i = 1; i <= n - diag; i++)
		{
		j = i + diag;
		for (k = i; k <= j; k++)
			temp[k] = A[i][k - 1] + A[k + 1][j];
		k = 1;
		A[i][j] = mini(n, temp, &k) + sum(i, j, P);
		R[i][j] = k;
		}
	cout << "\n\n  ======================================\n";
	cout << "                  < 행렬  A >           ";
	cout << "\n  ======================================\n    ";
	for (i = 1; i<n + 2; i++)       // 배열  A 출력
	{
		for (int j = 1; j<n + 1; j++)
			if (i > j) printf("         ");
			else  printf("%.3lf    ", A[i][j]);
			cout << "\n    ";
	}

	minavg = A[1][n];
}

double mini(int n, double *t, int *k)
{
	double small;
	small = t[1];
	for (int i = 2; i <= n; i++)
		if (small > t[i])   {
		small = t[i];
		*k = i;            // 최소 곱셈횟수를 보장하는 k 결정
		}
	for (int i = 0; i <= n; i++)                          // 배열 t[]를 다시 초기화
		t[i] = MAX;

	return small;
}

double sum(int i, int j, double *P)
{
	double hap = 0;

	for (int x = i; x <= j; x++)
		hap += P[x];

	return  hap;
}




void main()
{
	int i, n, **R;
	char **key;
	double mavg, *P;

	cout << "\n\n    입력할 키값의 수는? ";
	cin >> n;

	P = new double[n + 1];         // 각 키들의 검색 확률이 저장된 배열  P 의 동적할당

	key = new char *[n + 1];       // 각 키들을 저장하는 문자열 배열  key의 동적할당
	for (i = 0; i < n + 1; i++)
		key[i] = new char[30];

	R = new int *[n + 2];          // 부모 노드가 될 키를 결정해주는 배열  R 의 동적할당
	for (i = 0; i < n + 2; i++)
		R[i] = new int[n + 1];

	cout << "\n\n    입력 키들을 차례대로 입력하시오 : ";
	for (i = 1; i <= n; i++)
		cin >> key[i];

	cout << "\n\n    입력 키의 검색확률을 입력하시오 : ";  // 예제 3.9 : 0.375 0.375 0.125 0.125
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &P[i]);
	}

	s_tree(n, P, mavg, R);  // 최적 이진 검색트리의 평균 검색시간 계산, 트리를 구축할 배열 R 구성

	cout << "\n   최적 이진 검색트리의 평균 검색시간 : " << setprecision(4) << mavg << " 번";
	cout << "\n\n   이때 루트는 누가 차지하고 있을까?  " << key[R[1][n]];

	cout << "\n\n  ====================================\n";
	cout << "             < 행렬  R >            ";
	cout << "\n  ====================================\n";
	for (i = 1; i<n + 2; i++)       // 배열  R 출력
	{
		for (int j = 1; j<n + 1; j++)
			if (i > j) printf("        ");
			else  printf("%8d", R[i][j]);
			cout << "\n";
	}


	for (i = 0; i < n + 2; i++)    // 동적 할당의 해제
		delete[] R[i];
	delete[] key;
	delete[] P;
}