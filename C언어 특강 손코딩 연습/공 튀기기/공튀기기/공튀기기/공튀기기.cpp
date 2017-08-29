#include <stdio.h>
#define MIN_X 0
#define MAX_X 5
#define MIN_Y 0
#define MAX_Y 6


int main()
{
	int x = 3, y = 3;
	int i = 0;
	int dx = 1;
	int dy = 1;

	for (i = 0; i<20; i++)
	{
		printf("%d, %d\n", x, y);
		x += dx;
		y += dy;

		if (x >= MAX_X || x <= MIN_X) { dx *= -1; }
		if (y >= MAX_Y || y <= MIN_Y) { dy *= -1; }


	}
}