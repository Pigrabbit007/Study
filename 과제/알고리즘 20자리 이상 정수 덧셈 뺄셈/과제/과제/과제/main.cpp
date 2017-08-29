#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Calculate(char[], char[], int, int);

void main()
{
	char *num1 = (char *)malloc(sizeof(char)*255);
	char *num2 = (char *)malloc(sizeof(char)*255);
	int num1_l, num2_l;

	printf("20120540_임태현_20자리_이상의_정수_가감산_알고리즘\n\n");

	while (1)
	{
		printf("입력 1 : "); gets(num1);
		printf("입력 2 : "); gets(num2);

		num1_l = strlen(num1); num2_l = strlen(num2); // strlen 함수를 이용 각 문자열의 길이를 알아낸 뒤 저장.
		if (num2_l>num1_l || strcmp(num1, num2)<0 && num1_l == num2_l) // 두 문자열을 비교하여 값이 큰 문자열을 찾아낸다.
		{
			Calculate(num2, num1, num2_l, num1_l);
		}
		else{ Calculate(num1, num2, num1_l, num2_l); }
	}

}