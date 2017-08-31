// Tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#define EMPTY 0

typedef struct node {
	int data;
	struct node *rnode;
	struct node *lnode;
};

node * get_node() {
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->rnode = NULL;
	tmp->lnode = NULL;
	return tmp;
}

void add_tree(node **root, int data) {
	if (*root == NULL) {
		*root = get_node();
		(*root)->data = data;
		return;
	}
	if ((*root)->data < data)
		add_tree(&(*root)->rnode, data);
	else add_tree(&(*root)->lnode, data);
}

void print_data(node *root) {
	if (root = NULL)
		return;
	print_data(root->lnode);
	printf("%d", root->data);
	print_data(root->rnode);
}

void preorder(node *root) {
	if (root == NULL)
		return;

	printf("%d", root->data);
	preorder(root->lnode);
	preorder(root->rnode);
}

void inorder(node *root) {
	if (root == NULL)
		return;
	
	inorder(root->lnode);
	printf("%d", root->data);
	inorder(root->rnode);
}

void postorder(node *root) {
	if (root == NULL)
		return;
	
	postorder(root->lnode);
	postorder(root->rnode);
	printf("%d", root->data);
}

void delete_data(node **root, int data) {
	node * tmp = NULL;

	if ((*root)->data == NULL)
		return;
	if ((*root)->data == data) {
		tmp = *root;
		if ((*root)->lnode == NULL && (*root)->rnode == NULL) {
			(*root) = NULL;
		}
		else if ((*root)->lnode == NULL && (*root)->rnode != NULL) {
			node *tmp2 = *root;
			tmp = *root;
			*root = (*root)->lnode;
			while (tmp2->rnode != NULL) {
				tmp2 = (*root)->rnode;
			}
			tmp2->rnode = tmp->rnode;
		}
		else {
			if ((*root)->lnode != NULL)
				*root = (*root)->lnode;
			else
				*root = (*root)->rnode;
		}
		free(tmp);
		return;
	}

	if ((*root)->data > data)
		delete_data(&(*root)->lnode, data);
	else
		delete_data(&(*root)->rnode, data);
}

void search_data(node *root, int data) {
	if (root == NULL)
		return;

	if (root->data == data) {
		printf("찾는 값은 %d번지에 있습니다.\n", &root->data);
		return;
	}

	if (root->data > data)
		search_data(root->lnode, data);
	else
		search_data(root->rnode, data);
}

int main()
{
	node * root = NULL;
	int i;
	int data[19] = { 30,45,80,90,45,60,20,12,45,95,65,12,45,75,96,32,12,47,5 };

	for (i = 0; i < 19; i++) 
		add_tree(&root, data[i]);
	search_data(root, 80);
	search_data(root, 77);
	delete_data(&root, 90);
	print_data(root);
	
    return 0;
}