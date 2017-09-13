// 나머지.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int A, B, C;
	scanf_s("%d%d%d", &A, &B, &C);
	printf("%d\n", (A + B) % C);
	printf("%d\n", (A%C + B%C) % C);
	printf("%d\n", (A*B) % C);
	printf("%d\n", (A%C * B%C) % C);
	return 0;
}

