// 기찍N.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int n;
	scanf_s("%d", &n);

	for (int i = n; i > 0; i--) {
		printf("%d\n", i);
	}
	return 0;
}

