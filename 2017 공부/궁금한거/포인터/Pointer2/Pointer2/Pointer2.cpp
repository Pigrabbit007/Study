// Pointer2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void m_parray(int* pa) {
	for (int i=0; i<3; i++)
	printf("%d\n", &pa[i]);
}

int main()
{
	int array[3] = { 0, 1, 2 };
	int *parray = array;
	m_parray(parray);

    return 0;
}

