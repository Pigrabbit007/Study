// Pointer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, *b=NULL;

	a = 10;
	b = &a;

	printf("%d %d", a, *b);

    return 0;
}

