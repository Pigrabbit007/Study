#include <stdio.h>

void main()
{
	char a[27];
	int i, j, k;

	a[0] = 'A';
	//�迭 ����
	for (i = 0; i < 26; i++)
	{
		a[i] = a[0]+i;
		printf("%c", a[i]);
	}

	printf("\n");
	//���
	for (i = 0; i < 26; i++)
	{
		for (j = i; j < 26; j++)	//�պκ� ���
			printf("%c", a[j]);
		for (k = i-1; k >= 0; --k)		//�޺κ� ���
			printf("%c", a[k]);
		printf("\n");
	}

}