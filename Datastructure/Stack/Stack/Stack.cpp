// Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node *top;
}stack;

stack * get_node() {
	stack *tmp;
	tmp = (stack*)malloc(sizeof(stack));
	return tmp;
}

void push(stack **top, int data) {
	stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->top = tmp;
}

void pop(stack **top) {
	*top = (*top)->top;
}

int peek(stack **top) {
	if (*top == NULL)
		return NULL;
	else return (*top)->data;
}

void main() {
	stack *top=0;
	
	push(&top, 10);
	push(&top, 30);
	push(&top, 20);

	printf("%d\n", peek(&top));
	pop(&top);
	printf("%d\n", peek(&top));
	pop(&top);
	printf("%d\n", peek(&top));
	pop(&top);
}