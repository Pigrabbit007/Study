#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int first1, i, case_num, n_num, result, input;
	scanf_s("%d", &first1);
	case_num = first1;

	while (first1--){
		scanf_s("%d", &n_num);
		result = 0;

		for (i = 0; i < n_num; i++){
			scanf_s("%d", &input);
			result = result ^ input;
		}
		printf("Case #%d\n", case_num - first1);
		printf("%d\n", result);
	}
}