// Queue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#define EMPTY 0

typedef struct node{
	int data;
	struct node *link;
}queue;

queue * get_node() {
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	tmp->link = EMPTY;
	return tmp;
}

void enqueue(queue **front, queue **rear, int data) {
	queue *tmp;
	tmp = *rear;
	*rear = get_node();
	(*rear)->data = data;
	if (*front == EMPTY)
		*front = *rear;
	else (tmp)->link = *rear;

}

void dequeue(queue **front, queue **rear) {
	queue * tmp;
	tmp = *front;
	*front = tmp->link;
	free(tmp);
}

int peek(queue **front) {
	queue * tmp;
	if (*front == EMPTY) {
		printf("큐가 비엇어용!\n");
		return NULL;
	}
	else return (*front)->data;
}

int main()
{
	queue *front = EMPTY;
	queue *rear = EMPTY;
	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);
	enqueue(&front, &rear, 40);

	printf("%d\n", peek(&front));
	dequeue(&front, &rear);
	printf("%d\n", peek(&front));
	dequeue(&front, &rear);
	printf("%d\n", peek(&front));
	dequeue(&front, &rear);
	printf("%d\n", peek(&front));
	dequeue(&front, &rear);
    return 0;
}

