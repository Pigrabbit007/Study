// Stack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node *link;
}stack;

stack * get_node(){
	stack *tmp;
	tmp = (stack*)malloc(sizeof(stack));
	return tmp;
}

void push(stack **top, int data) {
	stack *tmp;
	tmp = *top;
	*top = get_node();
	(*top)->data = data;
	(*top)->link = tmp;
	*top = tmp;
}

int main()
{
	
    return 0;
}

