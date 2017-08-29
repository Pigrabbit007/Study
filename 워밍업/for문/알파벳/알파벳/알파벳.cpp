#include <stdio.h>

void main()
{
	char a[27];
	int i, j, k;

	a[0] = 'A';
	//배열 저장
	for (i = 0; i < 26; i++)
	{
		a[i] = a[0]+i;
		printf("%c", a[i]);
	}

	printf("\n");
	//출력
	for (i = 0; i < 26; i++)
	{
		for (j = i; j < 26; j++)	//앞부분 출력
			printf("%c", a[j]);
		for (k = i-1; k >= 0; --k)		//뒷부분 출력
			printf("%c", a[k]);
		printf("\n");
	}

}