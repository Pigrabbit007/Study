//�̻걸�� - ���ͽ�Ʈ�� �˰��� ����, ��ǻ���а� 20120540 ������

#include <stdio.h>
#define INF 1000
#define MV 5

int F[MV];
int D[MV];

int weight[MV][MV] = {
		{0,10,INF,30,100},
		{INF,0,50,INF,INF},
		{INF,INF,0,INF, 10},
		{INF,INF,20,0,60},
		{INF,INF,INF,INF,0}
};

int choose(int D[], int n, int F[])
{
	int i, min, minpos;
	min = INF;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (D[i] < min && !F[i]){
		min = D[i];
		minpos = i;
		}
	return minpos;
}

void dijkstra(int start, int n)
{
	int i, u, w;

	for (i = 0; i <= n; i++)
	{
		D[i] = weight[start][i];
		F[i] = 0;
	}
	F[start] = start+1;
	D[start] = 0;
	for (i = 0; i < n; i++){
		if (D[i] == 0)
			printf("���� %d���� ���� %d���� �ִܰ�� : ��ΰ� ���ų� �ڽ��� ���� ����Ű�� �ֽ��ϴ�.\n", start+1, i+1);
		else
		printf("���� %d���� ���� %d���� �ִܰ�� : %d\n", start+1, i+1, D[i]);
		u = choose(D, n, F);
		F[u] = 1;
		for (w = 0; w < n; w++)
			if (!F[w])
				if (D[u] + weight[u][w] < D[w])
					D[w] = D[u] + weight[u][w];
	}
}

void main()
{
	printf("�̻걸�� - ���ͽ�Ʈ�� �˰��� ����, ��ǻ���а� 20120540 ������\n\n");
	dijkstra(0, MV);
	printf("\n");
	dijkstra(1, MV);
	printf("\n");
	dijkstra(2, MV);
	printf("\n");
	dijkstra(3, MV);
	printf("\n");
	dijkstra(4, MV);
	printf("\n");
}

