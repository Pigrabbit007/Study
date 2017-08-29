//이산구조 - 다익스트라 알고리즘 과제, 컴퓨터학과 20120540 임태현

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
			printf("정점 %d에서 정점 %d로의 최단경로 : 경로가 없거나 자신의 값을 가리키고 있습니다.\n", start+1, i+1);
		else
		printf("정점 %d에서 정점 %d로의 최단경로 : %d\n", start+1, i+1, D[i]);
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
	printf("이산구조 - 다익스트라 알고리즘 과제, 컴퓨터학과 20120540 임태현\n\n");
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

