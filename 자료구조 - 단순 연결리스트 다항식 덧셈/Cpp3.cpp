#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode		//다항식 리스트 정의
{
	int coef;
	int expon;
	struct Listnode *Link
}Listnode;

typedef struct		//다항식 리스트 헤더 정의
{
	Listnode *head;
	int lengeh;
}List_type;

typedef struct		//임시 저장 구조체
{
	int coef;
	int expon;
	int tmp_link;
}Tmp;

void init(List_type *list)		//다항식 초기화
{
	list->length = 0;
	list->head = NULL;
}

int check_list(List_type *list)		//다항식 헤더 정의
{
	if(list->head == NULL) return 1;
	else return 0;
}

int check_length(List_type *list)		//리스트 길이 체크
{
	return list->length;
}

void insert_node(Listnode **phead, Listnode *p, Listnode *new_node)		//연결리스트 삽입 함수
{
	if(*phead == NULL){
		new_node->link = NULL;
		*phead = new_node;
	}
	else if(p==NULL){
		new_node->link = *phead;
		*phead = new_node;
	}
	else{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(Listnode **phead, Listnode *p, Listnode *new_node)		//연결리스트 삭제 함수
{
	if(p==NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}