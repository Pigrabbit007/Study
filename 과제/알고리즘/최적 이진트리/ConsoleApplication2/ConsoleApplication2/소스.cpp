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

	temp = new double[n];       // 1�� �迭�� ���� �Ҵ�

	A = new double *[n + 2];       // 2�� �迭�� ���� �Ҵ�
	for (i = 0; i < n + 2; i++)
		A[i] = new double[n + 1];

	for (i = 1; i <= n; i++)   // �迭  A , R  �ʱ�ȭ(�밢 ���)
	{
		A[i][i - 1] = 0;
		A[i][i] = P[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
		temp[i] = MAX;        // �迭  temp �ʱ�ȭ(���Ѵ� ������...)
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
	cout << "                  < ���  A >           ";
	cout << "\n  ======================================\n    ";
	for (i = 1; i<n + 2; i++)       // �迭  A ���
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
		*k = i;            // �ּ� ����Ƚ���� �����ϴ� k ����
		}
	for (int i = 0; i <= n; i++)                          // �迭 t[]�� �ٽ� �ʱ�ȭ
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

	cout << "\n\n    �Է��� Ű���� ����? ";
	cin >> n;

	P = new double[n + 1];         // �� Ű���� �˻� Ȯ���� ����� �迭  P �� �����Ҵ�

	key = new char *[n + 1];       // �� Ű���� �����ϴ� ���ڿ� �迭  key�� �����Ҵ�
	for (i = 0; i < n + 1; i++)
		key[i] = new char[30];

	R = new int *[n + 2];          // �θ� ��尡 �� Ű�� �������ִ� �迭  R �� �����Ҵ�
	for (i = 0; i < n + 2; i++)
		R[i] = new int[n + 1];

	cout << "\n\n    �Է� Ű���� ���ʴ�� �Է��Ͻÿ� : ";
	for (i = 1; i <= n; i++)
		cin >> key[i];

	cout << "\n\n    �Է� Ű�� �˻�Ȯ���� �Է��Ͻÿ� : ";  // ���� 3.9 : 0.375 0.375 0.125 0.125
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &P[i]);
	}

	s_tree(n, P, mavg, R);  // ���� ���� �˻�Ʈ���� ��� �˻��ð� ���, Ʈ���� ������ �迭 R ����

	cout << "\n   ���� ���� �˻�Ʈ���� ��� �˻��ð� : " << setprecision(4) << mavg << " ��";
	cout << "\n\n   �̶� ��Ʈ�� ���� �����ϰ� ������?  " << key[R[1][n]];

	cout << "\n\n  ====================================\n";
	cout << "             < ���  R >            ";
	cout << "\n  ====================================\n";
	for (i = 1; i<n + 2; i++)       // �迭  R ���
	{
		for (int j = 1; j<n + 1; j++)
			if (i > j) printf("        ");
			else  printf("%8d", R[i][j]);
			cout << "\n";
	}


	for (i = 0; i < n + 2; i++)    // ���� �Ҵ��� ����
		delete[] R[i];
	delete[] key;
	delete[] P;
}