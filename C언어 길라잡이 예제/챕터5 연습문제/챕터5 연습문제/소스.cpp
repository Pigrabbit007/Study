#include <stdio.h>

void main()
{
	int i, j;
	int select=2;

	do
	{
		printf("** ���� �޴� ���� **\n");
		printf("1. �����\n2. «��\n3. ������\n");
		scanf("%d", &select);
	} while (select > 3 || select < 1);

	for (i = 1; i < 10; i++)
	{
		j = 0;
		while (j++ < 9)
		{
			printf("%d * %d = %d\n", i, j, i*j);
		}
	}
}