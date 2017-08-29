#include <stdio.h>
#include <stdlib.h>

void Calculate(char in1[], char in2[], int in1_l, int in2_l)
{
	
	char *sum = (char *)malloc(sizeof(char) * 255);
	char *sub = (char *)malloc(sizeof(char) * 255);

	int p, m;
	int carrp=0, carrm=0;
	for (int i = 0; i <= in1_l; i++)
	{
		if (in2_l - i > 0 && in1_l - i > 0)
		{
			p = ((int)in1[in1_l - i - 1] - '0') + ((int)in2[in2_l - i - 1] - '0') + carrp;  //덧셈 - 올림수 처리 및 형변환
			m = ((int)in1[in1_l - i - 1] - '0') - ((int)in2[in2_l - i - 1] - '0') - carrm;  //뺄셈 - 내림수 처리 및 형변환
		}
		else if (in1_l - i > 0) // 배열의 한 부분이 끝난 후 배열의 나머지 부분을 처리하는 로직
		{
			p = ((int)in1[in1_l - i - 1] - '0') + carrp;
			m = ((int)in1[in1_l - i - 1] - '0') - carrm;
		}
		else
		{
			p = carrp; m = carrm;
		} //문자열 계산이 끝난 뒤 남아있는 올림수와 내림수의 처리
		carrp = 0; carrm = 0;
		if (p >= 10)  //자리 올림이 발생했을 경우의 처리
		{
			carrp = p / 10; p %= 10;
		}
		sum[i] = p;
		if (m < 0)  //자리 내림이 발생했을 경우의 처리
		{
			carrm = 1; m += 10;
		}
		sub[i] = m;
	}

	int sw = 0;

	printf("덧셈 결과 : ");
	for (int i = in1_l; i >= 0; i--) //덧셈 출력
	{
		if (sw == 0 && sum[i] != 0 || sw == 1)  //가장 큰 자리의 수엔 0이 출력 되지 않게 만든다.
		{
			printf("%d", sum[i]); sw = 1;
		}
	}

	printf("\n");
	sw = 0;

	printf("뺄셈 결과 : ");
	for (int i = in1_l; i >= 0; i--) //뺄셈 출력
	{
		if (sw == 0 && sub[i] != 0 || sw == 1)
		{
			printf("%d", sub[i]); sw = 1;
		}
		if (sw == 0 && i == 0) printf("%d", sub[i]);  //뺄셈 값이 0이 나올 경우 0을 출력한다.
	}
	printf("\n");
}