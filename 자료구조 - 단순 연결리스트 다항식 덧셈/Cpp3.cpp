#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode		//���׽� ����Ʈ ����
{
	int coef;
	int expon;
	struct Listnode *Link
}Listnode;

typedef struct		//���׽� ����Ʈ ��� ����
{
	Listnode *head;
	int lengeh;
}List_type;

typedef struct		//�ӽ� ���� ����ü
{
	int coef;
	int expon;
	int tmp_link;
}Tmp;

void init(List_type *list)		//���׽� �ʱ�ȭ
{
	list->length = 0;
	list->head = NULL;
}

int check_list(List_type *list)		//���׽� ��� ����
{
	if(list->head == NULL) return 1;
	else return 0;
}

int check_length(List_type *list)		//����Ʈ ���� üũ
{
	return list->length;
}

void insert_node(Listnode **phead, Listnode *p, Listnode *new_node)		//���Ḯ��Ʈ ���� �Լ�
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

void remove_node(Listnode **phead, Listnode *p, Listnode *new_node)		//���Ḯ��Ʈ ���� �Լ�
{
	if(p==NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}