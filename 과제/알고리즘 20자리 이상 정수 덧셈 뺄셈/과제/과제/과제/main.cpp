#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Calculate(char[], char[], int, int);

void main()
{
	char *num1 = (char *)malloc(sizeof(char)*255);
	char *num2 = (char *)malloc(sizeof(char)*255);
	int num1_l, num2_l;

	printf("20120540_������_20�ڸ�_�̻���_����_������_�˰���\n\n");

	while (1)
	{
		printf("�Է� 1 : "); gets(num1);
		printf("�Է� 2 : "); gets(num2);

		num1_l = strlen(num1); num2_l = strlen(num2); // strlen �Լ��� �̿� �� ���ڿ��� ���̸� �˾Ƴ� �� ����.
		if (num2_l>num1_l || strcmp(num1, num2)<0 && num1_l == num2_l) // �� ���ڿ��� ���Ͽ� ���� ū ���ڿ��� ã�Ƴ���.
		{
			Calculate(num2, num1, num2_l, num1_l);
		}
		else{ Calculate(num1, num2, num1_l, num2_l); }
	}

}