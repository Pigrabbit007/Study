// ab2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main() {

	int origin, div_three = 0;

	scanf_s("%d", &origin);

	while (1) {
		if (origin % 5 == 0) {
			printf("%d", origin / 5 + div_three);
			break;
		}
		else if (origin <= 0) {
			printf("-1");
			break;
		}
		origin -= 3;
		div_three++;
	}
	return 0;
}