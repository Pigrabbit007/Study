// 그대로출력하기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char arr[101];

	while (gets_s(arr)) {
		puts(arr);
	}

	return 0;
}