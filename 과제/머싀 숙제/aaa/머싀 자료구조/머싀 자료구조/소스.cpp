#include<stdio.h>
#include<stdlib.h>
#include <string.h>


#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s) // ������ �ʱ�ȭ�ϴ� �Լ��Դϴ�
{
	s->top = -1;
}
int is_empty(StackType *s)// ������ ���� ���¸� �����ϴ� �Լ��Դϴ�
{
	return(s->top == -1);
}
int is_full(StackType *s)// ������ ��ȭ ���¸� �����ϴ� �ռ��Դϴ�
{
	return(s->top == -1);
}
void push(StackType *s, element item)// ���ÿ� item�� �����ϴ� �Լ��Դϴ�
{
	if (is_full(s))
	{
		fprintf(stderr, "STACK FULL ERROR\n"); //������ ��ȭ ������ ���� �˷��ִ� �ڵ��Դϴ�
		return;
	}
	else s->stack[++(s->top)] = item;//�׷��� ���� ��� ���ÿ� �����մϴ�

}
element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "STACK EMPTY ERROR\n");//������ ���� �������� �˷��ݴϴ�

	}
	else return s->stack[(s->top)--];// �׷��� ���� ��� ���ÿ��� �Ѱ��� pop(����)�մϴ�.

}
element peek(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "STACK EMPTY ERROR\n"); //������ ���� �������� �˷��ݴϴ�
	}
	else return s->stack[s->top];
}
int prec(char op)// ������ �켱 ������ ��ȯ�ϴ� ���� �����մϴ�
{
	switch (op)
	{
	case '(':case')': return 0;
	case '+':case'-': return 1;
	case '*':case'/': return 2;
	}
	return -1;
}




// ���� ǥ�� ������ ���� ǥ�� �������� �ٲٴ� �Լ��� �����ϰڽ��ϴ�
void in_to_post(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch)
		{
		case'+':case'-':case'*':case'/': //�������� ���

			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))   // ���ÿ� �ִ� �������� �켱������
				printf("%c", pop(&s));                              // �� ũ�ų� ������ ����մϴ�
			push(&s, ch);
			break;
		case'(': //���� ��ȣ�� ���
			push(&s, ch);
			break;
		case')': //������ ��ȣ�� ���
			top_op = pop(&s);
			while (top_op != '(')
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int eval(char exp[])  // ���
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - 0;
			push(&s, value);
		}

		else
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
			case'+':push(&s, op1 + op2); break;
			case'-':push(&s, op1 - op2); break;
			case'*':push(&s, op1 * op2); break;
			case'/':push(&s, op1 / op2); break;



			default:
				break;
			}
		}
	}
}
void main()
{
	in_to_post("(5+4)-4/2");
	printf("���� ǥ����� ");

}