#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) // a�� b�� ���ؼ� a�� ũ�� a�� �ƴϸ� b��

typedef struct
{
	int degree;
	float c[100];
}poly;

poly add_poly(poly a, poly b)	 // ���׽� ���� �Լ�
{
	poly c;
		c.degree = MAX(a.degree, b.degree);

	int Apos=0, Bpos=0, Cpos=0; // �ε��� ����
	int degree_a = a.degree, degree_b = b.degree;

	while(Apos<=a.degree && Bpos<=b.degree)
	{
		if(degree_a > degree_b){	// a�� > b��
			c.c[Cpos++] = a.c[Apos++];
		degree_a--;
		}
		else if(degree_a == degree_b){	// a�� = b��
			c.c[Cpos++] = a.c[Apos++]+b.c[Bpos++];
		degree_a--, degree_b--;
		}
		else{	// a�� < b��
			c.c[Cpos++] = b.c[Bpos++];
		degree_b--;
		}
	}

	return c;
}

poly subtract_poly(poly a, poly b)	// ���׽� ���� �Լ�
{
	poly c;
		c.degree = MAX(a.degree, b.degree);

	int Apos=0, Bpos=0, Cpos=0;		// �ε��� ����
	int degree_a = a.degree, degree_b = b.degree;

	while(Apos<=a.degree && Bpos<=b.degree)
	{
		if(degree_a > degree_b){	// a�� > b��
			c.c[Cpos++] = a.c[Apos++];
		degree_a--;
		}
		else if(degree_a == degree_b){	//a�� = b��
			c.c[Cpos++] = a.c[Apos++]-b.c[Bpos++];
		degree_a--, degree_b--;
		}
		else{	//a�� < b��
			c.c[Cpos++] = b.c[Bpos++];
		degree_b--;
		}
	}

	return c;
}


void print_add_poly(poly a)		//���� ��� �Լ�
{
	int i, j;

	for(i=0, j=a.degree; i<=a.degree; j--, i++)
	{
		if(a.c[i]!=0){
			if(j==1) printf("%gx", a.c[i]);
			else if(j==0) printf("%g\n", a.c[i]);
			else printf("%gx^%d", a.c[i], j);
			if(j!=0) printf(" + ");
		}
		
	}
}

void print_subtract_poly(poly a)	//���� ��� �Լ�
{
	int i, j;

	for(i=0, j=a.degree; i<=a.degree; j--, i++)
	{
		if(a.c[i]!=0){
			if(j==1) printf("%gx", a.c[i]);
			else if(j==0) printf("%g\n", a.c[i]);
			else printf("%gx^%d", a.c[i], j);
			if(j!=0) printf(" - ");
			if(j<0) printf(" + " );
		}
		
	}
}

void main()	//�����Լ�
{
	poly a = {5,{3,6,0,0,0,10}};
	poly b = {4,{7,0,5,0,1}};
	poly c;
	poly d;

	c = add_poly(a, b);
	d = subtract_poly(a, b);

	printf("a = ");
	print_add_poly(a);
	printf("b = ");
	print_add_poly(b);

	printf("\na+b = ");
	print_add_poly(c);

	printf("\na-b = ");
	print_subtract_poly(d);

}