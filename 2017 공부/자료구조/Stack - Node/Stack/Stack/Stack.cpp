// Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#define EMPTY 0

struct node
{
	int data;
	struct node *link;
};
typedef struct node stack;

stack * get_node()
{
	stack*tmp;
	tmp = (stack *)malloc(sizeof(stack));
	return tmp;
}

void push(stack **top, int data)
{
	stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
}

void pop(stack **top) {
	stack *tmp;
	tmp = *top;
	*top = (*top)->link;
	free(tmp);
}

int peek(stack **top) {
	stack *tmp;
	int num;
	tmp = *top;
	if (*top == EMPTY)
	{
		printf("Stack is Empty");
		return NULL;
	}
	num = tmp->data;
	return num;
}

int main()
{
	stack * top = EMPTY;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);

	printf("%d\n", peek(&top));
	pop(&top);
	printf("%d\n", peek(&top));
	pop(&top);
	printf("%d\n", peek(&top));
	pop(&top);
	printf("%d\n", peek(&top));
	pop(&top);
    return 0;
}

