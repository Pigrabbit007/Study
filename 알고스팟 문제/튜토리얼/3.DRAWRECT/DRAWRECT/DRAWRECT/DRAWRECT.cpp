#include <stdio.h>

void rect_other(int Case_Num);

int main()
{
	int Case_Num;
	scanf("%d", &Case_Num);

	rect_other(Case_Num);

	return 0;
}

void rect_other(int Case_Num)
{
	int vertex_left[3] = { 0 }, vertex_right[3] = { 0 };

	while (Case_Num--)
	{

		scanf("%d %d", &vertex_left[0], &vertex_right[0]);
		scanf("%d %d", &vertex_left[1], &vertex_right[1]);
		scanf("%d %d", &vertex_left[2], &vertex_right[2]);

		int left = vertex_left[0], right = vertex_right[0];

		if (left == vertex_left[1]) left = vertex_left[2];
		else if (left == vertex_left[2]) left = vertex_left[1];

		if (right == vertex_right[1]) right = vertex_right[2];
		else if (right == vertex_right[2]) right = vertex_right[1];

		printf("%d %d\n", left, right);
	}
}