#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sol(char na1[], char nb1[], int nan1, int nbn1);

void main()
{
	char num1[201], num2[201];
	int num1_l, num2_l;

	while (1)
	{
		gets(num1); gets(num2);

		num1_l = strlen(num1); num2_l = strlen(num2); // strlen함수를 이용하여 각 문자열의 길이를 알아 내고 있습니다.
		if (num2_l>num1_l || strcmp(num1, num2)<0 && num1_l == num2_l) //두 문자열을 비교하여 값이 큰 문자열을 찾아내는 것입니다.
		{
			sol(num2, num1, num2_l, num1_l);
		}
		else{ sol(num1, num2, num1_l, num2_l); }
	}


}

void sol(char num1[], char num2[], int num1_l, int num2_l)
{
	int i, k, h, carr=0, carr1=0, sw=0, j;

	char nsum[201], nsub[201];

	for (i = 0; i <= num1_l; i++)
	{
		if (num2_l - i > 0 && num1_l - i > 0)
		{
			k = ((int)num1[num1_l - i - 1] - '0') + ((int)num2[num2_l - i - 1] - '0') + carr;  //덧셈을 하는 부분입니다. 각 자리를 정수형으로 변환 후 아스키코드값인 '0'의 값을 빼고 올림수(carr)가 있으면 더해 주었습니다. 
			h = ((int)num1[num1_l - i - 1] - '0') - ((int)num2[num2_l - i - 1] - '0') - carr1;  //뺄셈도 마찬가지 입니다. 다만 내림수를 빼주는 것이 다릅니다. 
		}
		else if (num1_l - i > 0) //이 부분은 짧은 문자열이 끝났을 경우에 나머지 긴 문자열을 처리하는 부분입니다.
		{
			k = ((int)num1[num1_l - i - 1] - '0') + carr;
			h = ((int)num1[num1_l - i - 1] - '0') - carr1;
		}
		else
		{
			k = carr; h = carr1;
		} //이 부분은 모든 문자열이 끝나고 올림수와 내림수가 남았을 경우의 처리 부분입니다.
		carr = 0; carr1 = 0;
		if (k >= 10)  //자리 올림이 발생했을 경우의 처리 내용입니다.
		{
			carr = k / 10; k = k % 10;
		}
		nsum[i] = k;
		if (h < 0)  //자리 내림이 발생했을 경우의 처리 내용입니다.
		{
			carr1 = 1; h = 10 + h;
		}
		nsub[i] = h;
	}

	for (i = num1_l; i >= 0; i--) //덧셈 출력
	{
		if (sw == 0 && nsum[i] != 0 || sw == 1)  //숫자의 앞에는 0을 표시하지 않기 때문에 sw를 사용하여 앞에 0이 나오면 출력하지 않게 하였습니다. 
		{
			printf("%d", nsum[i]); sw = 1;
		}
		
	}
	printf("\n");
	sw = 0;
	for (j = num1_l; j >= 0; j--) //뺄셈 출력
	{
		if (sw == 0 && nsub[j] != 0 || sw == 1)
		{
			printf("%d", nsub[j]); sw = 1;
		}
		if (sw == 0 && j == 0) printf("%d", nsub[j]);  //뺄셈에서 값이 0이 나올 때를 대비하여 조건을 하나 넣었습니다.
	}
	printf("\n");
}