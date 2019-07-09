// 별찍기1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("*");
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
    return 0;
}

