#include <stdio.h>
#include <stdlib.h>

void Calculate(char in1[], char in2[], int in1_l, int in2_l)
{
	
	char *sum = (char *)malloc(sizeof(char) * 255);
	char *sub = (char *)malloc(sizeof(char) * 255);

	int p, m;
	int carrp=0, carrm=0;
	for (int i = 0; i <= in1_l; i++)
	{
		if (in2_l - i > 0 && in1_l - i > 0)
		{
			p = ((int)in1[in1_l - i - 1] - '0') + ((int)in2[in2_l - i - 1] - '0') + carrp;  //���� - �ø��� ó�� �� ����ȯ
			m = ((int)in1[in1_l - i - 1] - '0') - ((int)in2[in2_l - i - 1] - '0') - carrm;  //���� - ������ ó�� �� ����ȯ
		}
		else if (in1_l - i > 0) // �迭�� �� �κ��� ���� �� �迭�� ������ �κ��� ó���ϴ� ����
		{
			p = ((int)in1[in1_l - i - 1] - '0') + carrp;
			m = ((int)in1[in1_l - i - 1] - '0') - carrm;
		}
		else
		{
			p = carrp; m = carrm;
		} //���ڿ� ����� ���� �� �����ִ� �ø����� �������� ó��
		carrp = 0; carrm = 0;
		if (p >= 10)  //�ڸ� �ø��� �߻����� ����� ó��
		{
			carrp = p / 10; p %= 10;
		}
		sum[i] = p;
		if (m < 0)  //�ڸ� ������ �߻����� ����� ó��
		{
			carrm = 1; m += 10;
		}
		sub[i] = m;
	}

	int sw = 0;

	printf("���� ��� : ");
	for (int i = in1_l; i >= 0; i--) //���� ���
	{
		if (sw == 0 && sum[i] != 0 || sw == 1)  //���� ū �ڸ��� ���� 0�� ��� ���� �ʰ� �����.
		{
			printf("%d", sum[i]); sw = 1;
		}
	}

	printf("\n");
	sw = 0;

	printf("���� ��� : ");
	for (int i = in1_l; i >= 0; i--) //���� ���
	{
		if (sw == 0 && sub[i] != 0 || sw == 1)
		{
			printf("%d", sub[i]); sw = 1;
		}
		if (sw == 0 && i == 0) printf("%d", sub[i]);  //���� ���� 0�� ���� ��� 0�� ����Ѵ�.
	}
	printf("\n");
}