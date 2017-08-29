#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sol(char na1[], char nb1[], int nan1, int nbn1);

void main()
{
	char num1[201], num2[201];
	int num1_l, num2_l;

	while (1)
	{
		gets(num1); gets(num2);

		num1_l = strlen(num1); num2_l = strlen(num2); // strlen�Լ��� �̿��Ͽ� �� ���ڿ��� ���̸� �˾� ���� �ֽ��ϴ�.
		if (num2_l>num1_l || strcmp(num1, num2)<0 && num1_l == num2_l) //�� ���ڿ��� ���Ͽ� ���� ū ���ڿ��� ã�Ƴ��� ���Դϴ�.
		{
			sol(num2, num1, num2_l, num1_l);
		}
		else{ sol(num1, num2, num1_l, num2_l); }
	}


}

void sol(char num1[], char num2[], int num1_l, int num2_l)
{
	int i, k, h, carr=0, carr1=0, sw=0, j;

	char nsum[201], nsub[201];

	for (i = 0; i <= num1_l; i++)
	{
		if (num2_l - i > 0 && num1_l - i > 0)
		{
			k = ((int)num1[num1_l - i - 1] - '0') + ((int)num2[num2_l - i - 1] - '0') + carr;  //������ �ϴ� �κ��Դϴ�. �� �ڸ��� ���������� ��ȯ �� �ƽ�Ű�ڵ尪�� '0'�� ���� ���� �ø���(carr)�� ������ ���� �־����ϴ�. 
			h = ((int)num1[num1_l - i - 1] - '0') - ((int)num2[num2_l - i - 1] - '0') - carr1;  //������ �������� �Դϴ�. �ٸ� �������� ���ִ� ���� �ٸ��ϴ�. 
		}
		else if (num1_l - i > 0) //�� �κ��� ª�� ���ڿ��� ������ ��쿡 ������ �� ���ڿ��� ó���ϴ� �κ��Դϴ�.
		{
			k = ((int)num1[num1_l - i - 1] - '0') + carr;
			h = ((int)num1[num1_l - i - 1] - '0') - carr1;
		}
		else
		{
			k = carr; h = carr1;
		} //�� �κ��� ��� ���ڿ��� ������ �ø����� �������� ������ ����� ó�� �κ��Դϴ�.
		carr = 0; carr1 = 0;
		if (k >= 10)  //�ڸ� �ø��� �߻����� ����� ó�� �����Դϴ�.
		{
			carr = k / 10; k = k % 10;
		}
		nsum[i] = k;
		if (h < 0)  //�ڸ� ������ �߻����� ����� ó�� �����Դϴ�.
		{
			carr1 = 1; h = 10 + h;
		}
		nsub[i] = h;
	}

	for (i = num1_l; i >= 0; i--) //���� ���
	{
		if (sw == 0 && nsum[i] != 0 || sw == 1)  //������ �տ��� 0�� ǥ������ �ʱ� ������ sw�� ����Ͽ� �տ� 0�� ������ ������� �ʰ� �Ͽ����ϴ�. 
		{
			printf("%d", nsum[i]); sw = 1;
		}
		
	}
	printf("\n");
	sw = 0;
	for (j = num1_l; j >= 0; j--) //���� ���
	{
		if (sw == 0 && nsub[j] != 0 || sw == 1)
		{
			printf("%d", nsub[j]); sw = 1;
		}
		if (sw == 0 && j == 0) printf("%d", nsub[j]);  //�������� ���� 0�� ���� ���� ����Ͽ� ������ �ϳ� �־����ϴ�.
	}
	printf("\n");
}