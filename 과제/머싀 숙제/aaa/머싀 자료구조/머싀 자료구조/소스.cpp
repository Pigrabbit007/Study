#include<stdio.h>
#include<stdlib.h>
#include <string.h>


#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s) // 스택을 초기화하는 함수입니다
{
	s->top = -1;
}
int is_empty(StackType *s)// 스택의 공백 상태를 검출하는 함수입니다
{
	return(s->top == -1);
}
int is_full(StackType *s)// 스택의 포화 상태를 검출하는 합수입니다
{
	return(s->top == -1);
}
void push(StackType *s, element item)// 스택에 item을 삽입하는 함수입니다
{
	if (is_full(s))
	{
		fprintf(stderr, "STACK FULL ERROR\n"); //스택이 포화 상태인 것을 알려주는 코드입니다
		return;
	}
	else s->stack[++(s->top)] = item;//그렇지 않을 경우 스택에 저장합니다

}
element pop(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "STACK EMPTY ERROR\n");//스택이 공백 상태임을 알려줍니다

	}
	else return s->stack[(s->top)--];// 그렇지 않을 경우 스택에서 한개를 pop(빼냄)합니다.

}
element peek(StackType *s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "STACK EMPTY ERROR\n"); //스택이 공백 상태임을 알려줍니다
	}
	else return s->stack[s->top];
}
int prec(char op)// 연산자 우선 순위를 반환하는 것을 선언합니다
{
	switch (op)
	{
	case '(':case')': return 0;
	case '+':case'-': return 1;
	case '*':case'/': return 2;
	}
	return -1;
}




// 중위 표기 수식을 후위 표기 수식으로 바꾸는 함수를 선언하겠습니다
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
		case'+':case'-':case'*':case'/': //연산자일 경우

			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))   // 스택에 있는 연산자의 우선순위가
				printf("%c", pop(&s));                              // 더 크거나 같으면 출력합니다
			push(&s, ch);
			break;
		case'(': //왼쪽 괄호인 경우
			push(&s, ch);
			break;
		case')': //오른쪽 괄호인 경우
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

int eval(char exp[])  // 계산
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
	printf("후위 표기식은 ");

}