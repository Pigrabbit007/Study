// AdivB.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double a, b;
	scanf_s("%lf%lf", &a, &b);
	printf("%.9lf", a / b);
    return 0;
}

