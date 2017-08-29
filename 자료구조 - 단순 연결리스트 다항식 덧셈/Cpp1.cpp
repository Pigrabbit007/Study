#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
typedef int element;

typedef struct ListNode{// ���׽ĸ���Ʈ�ǰ�����ǥ���ϰԵɱ���ü����
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;

typedef struct {// ����Ʈ�ش��ξ��ϱ���ü����
	ListNode * head;
	int length;
}ListType;

typedef struct {// �Է¹������ӽ����������ѱ���ü����
	int coef;
	int expon;
	int checkpoint;
}Temp;

void init( ListType *list )// ����Ʈ�ʱ�ȭ�Լ�
{
	list->length = 0;
	list->head = NULL;
}


int is_empty( ListType *list )// ����Ʈ������ִ���Ȯ��
{
	if( list->head == NULL ) return 1;
	else return 0;
}


int get_length( ListType *list )// ����Ʈ�Ǳ��̸����ϴ��Լ�
{
	return list->length;
}


void add( ListType *list, int position, element coef, element expon );// ��������������ڷι޾Ƴ�带�����ϴ��Լ�
void del( ListType *list, int pos );// ����Ʈ�������������ڷι޾ƻ����ϴ��Լ�
void insert_node( ListNode **phead, ListNode *p, ListNode *New_node );// ��带 �����ϴ� �Լ�( 3������� )
void remove_node( ListNode **phead, ListNode *p, ListNode *removed );// ������ ���� �����带 ���ڷ� ������ ����
void display_recur( ListNode *head );// ��ȯ������ �̿��Ͽ� ����Ʈ�� ȭ�鿡 ���
ListNode* PADD( ListType* A, ListType* B, ListType* C );// A(x), B(x)�� �����Ͽ� C(x)�� �����ϴ� �Լ�
ListNode* ATTACH(int coef, int expon, ListNode* ptr);// New��带 �����Ͽ� ptr�����Ϳ� ��ũ��Ű�� �Լ�
ListNode* get_node_at( ListType *list, int pos );// ����Ʈ���� �����ǿ� ���� ��������͸� ��ȯ
void Menu( ListType* list1, ListType* list2, ListType* list3 );// ���α׷��� ���θ޴�
int Insert( ListType* list );// ���ڿ��� �Է¹޾� �����Ͽ� ����Ʈ�� �����ϴ� �Լ�
int Print( ListType* list1, ListType* list2, ListType* list3 );// A(x), B(x), C(x) ����Ʈ�� ����ϴ� �Լ�
int Choices();// �۾��� �����ϱ����� �ǹ��� ���� �Լ�
int Partition( Temp a[], int left, int right );// �����Ľ� ������ ������ �۾����ϴ� �Լ�
void Quick_Sort( Temp a[], int left, int right );// ��ȯ�� ����� ���������� ������
int Search_Node( ListType* Head );// ������ ���� �˻��� �ϴ� �Լ�
int Free_front( ListNode* Search );// ����ü ������ ���� ��带 �����Ѵ�
void ALLFREE( ListType* list );// ��� ��� ����


int main()
{
	ListType list1, list2, list3;// �ش�����Ʈ ����

	init( &list1 );// ����Ʈ �ʱ�ȭ
	init( &list2 );
	init( &list3 );

	Menu( &list1, &list2, &list3 );// ���α׷� ���θ޴� ȣ��

	return 0;
}


void Menu( ListType* list1, ListType* list2, ListType* list3 )
{
	int select;
	int length=0, yesno=0;

	while( 1 )
	{
		system("cls");
		fputs( "\t\t������������������������������������������\n", stdout );
		fputs( "\t\t�� ��\n", stdout );
		fputs( "\t\t�� ���׽ĵ��� ���α׷� ��\n", stdout );
		fputs( "\t\t�� ��Ƽ�̵����а� ��\n", stdout );
		fputs( "\t\t�� 20040417 ����ȣ ��\n", stdout );
		fputs( "\t\t������������������������������������������\n", stdout );
		fputs( "\t\t�����Է� �� ����� �� ����� �� ������ ��\n", stdout );
		fputs( "\t\t������������������������������������������\n", stdout );
		fputs( "\t\t �� �����Ͻ� �۾��� �Է��ϼ��� : [ ]\b\b", stdout );
		scanf("%d", &select);

		while( getchar() != '\n' );

		switch( select )
		{
		case 1 :
			fputs( "\n\t\t�� �Է� �մϴ� �� ", stdout );
			fputs( "\n\n\t\t A(x) ���׽��� �Է��ϼ��� (���, ������)\n\n\t\t ", stdout );
			Insert( list1 );// �����Լ� ȣ��
			fputs( "\n\n\t\t B(x) ���׽��� �Է��ϼ��� (���, ������)\n\n\t\t ", stdout );
			Insert( list2 );// �����Լ� ȣ��
			break;

		case 2 :
			fputs( "\n\t\t�� ��� �մϴ� �� ", stdout );
			list3->head = PADD( list1, list2, list3 );// list3 = list1 + list2
			Print( list1, list2, list3 );// ���� ���� ���
			break;
			
		case 3 :
			fputs( "\n\t\t�� ���� �մϴ� �� ", stdout );
			list3->head = PADD( list1, list2, list3 );// list3 = list1 + list2

			if( Print( list1, list2, list3 ) ) break;// �����ϱ��� ����Ʈ ���
			// ��¸���Ʈ ������ ����
			printf( "\n\t\t �� ������ ���׽��� �����ϼ���.\n" );

			while(1){
				printf( "\n\t\t �� A(x)�� '1', B(x)�� '2' �� < >\b\b");
				scanf( "%d", &select );
				while( getchar() != '\n' );

				switch( select ){
				case 1 :
					if( -1 == (length=Search_Node( list1 )) ) break;
					// �����Ͱ� ���ٸ� -1 �� ������
					if( !(yesno = Choices()) ) break;// "������ ��� �Ͻðڽ��ϱ�?"
					del( list1, length );// Ȯ�εƴٸ� ����
					break;

				case 2 :					
					if( -1 == (length=Search_Node( list2 )) ) break;
					// �����Ͱ� ���ٸ� -1 �� ������
					if( !(yesno = Choices()) ) break;// "������ ��� �Ͻðڽ��ϱ�?"
					del( list2, length );// Ȯ�εƴٸ� ����
					break;
				}

				if( ( select == 1 || select == 2 ) && length != -1 ) break;
				// �������� �����Ŀ��� ����

				fputs( "\n\t\t �� �� �� �Է��ϼ̽��ϴ�.\n", stdout );

				if( !Choices() ) break;// �� �� �Է������� ����
			}
			
			if( yesno == 1 ) fputs( "\n\t\t �� �����Ͱ� ���� �Ǿ����ϴ�\n", stdout );
			// ������ Ȯ���ߴٸ� ���
			break;
			
		case 4 :
			fputs( "\n\t\t�� ���� �մϴ� �� ", stdout );
			if( !Choices() ) break;
			if( list1->head != NULL ) ALLFREE( list1 );// ������ ��� Free
			if( list2->head != NULL ) ALLFREE( list2 );// ������ ��� Free
			if( list3->head != NULL ) ALLFREE( list3 );// ������ ��� Free

			fputs( "\n\n\t\t\t�̿��� �ּż� �����մϴ�^^\n\n", stdout );
			exit(1);// ����
			break;

		default :
			fputs("\n\t\t�� �� �� �Է��ϼ̽��ϴ� ��\n", stdout );
		}
		fputs( "\n\t\t �� ����Ͻ÷��� ���͸� ��������", stdout );
		while( getchar() != '\n' );
	}
}

ListNode *get_node_at( ListType *list, int pos )// ����Ʈ���� �����ǿ� ���� ��������͸� ��ȯ
{
	int i;
	ListNode *tmp_node = list->head;

	if( pos < 0 ) return NULL;

	for( i=0 ; i<pos ; i++ )
		tmp_node = tmp_node->link;

	return tmp_node;
}



void add( ListType *list, int position, element coef, element expon )// ����� ������ ���ڷ� �޾� ��带 ����
{
	ListNode *p;

	if( (position >= 0 ) && ( position <= list->length ) )// �������� ������ �ȿ���
	{
		ListNode *node = ( ListNode* )malloc( sizeof(ListNode) );
		
		if( node == NULL ) fputs("\n\n\t\t �� �޸� �Ҵ翡��\n", stdout );

		node->coef = coef;// NewNode ��� ����
		node->expon = expon;// NewNode ���� ����
		node->link = NULL;// NewNode �������� NULL

		p = get_node_at(list, position-1);// �������� ���� ���� ��������͸� ȹ��
		insert_node( &(list->head), p, node );// ������
		list->length++;// ������ ������ ����
	}
}

int Insert( ListType* list )// ���ڿ��� �Է¹޾� �����Ͽ� ����Ʈ�� �����ϴ� �Լ�
{
	Temp Sort[MAX];
	char input[MAX] = {0, };
	char *ptr, *start;
	int i, j, k;
	ListNode* P = list->head;

	fgets( input, MAX, stdin );// ����� �Է�
	input[ strlen(input) -1 ] = '\0';// ���Ͱ� ����
	
	for( i=0, j=0, k=0 ; i < (int)strlen(input) ; i++ )
	{
		start = &input[i];// �迭 �ε����� �ش��ϴ� �ּҸ� �����Ϳ� ����

		if( !(input[i] >= 48 && input[i] <= 57) ) continue;// ���������� �ƴϸ� continue

		if( j++%2 == 0 ) Sort[k].coef = strtol( &input[i], &ptr, 10 );// ptr�� ������ �� ������ �ּҸ� ���Ϲ���
		else {
			Sort[k].expon = strtol( &input[i], &ptr, 10 );
			Sort[k++].checkpoint=-1;// �߰������ ��ġ������ ���� checkpoint����
		}

		while( start++ != ptr ) i++;// ������ �� �������� �ε����� ����ø���
	}

	Quick_Sort( Sort, 0, k-1 );// �Է¹��� ����Ÿ ������

	if( P != NULL )// �߰� �Է¹߻��� ���ο����� ��ġ�� ��������
		for(i=0 ; i<k ; i++ )
		{
			Sort[i].checkpoint=0;
			while( P->expon > Sort[i].expon ) {// ������ ��忡 �߰��� ��ġ�� ����
				P = P->link;
				Sort[i].checkpoint++;// checkpoint�� �߰���带 ���� ��ġ
			}
		}

		for( i=0, j=0 ; i < k ; i++ )// ����� 0�� ��带 ������ �ܼ����Ḯ��Ʈ �����ϱ�
			if( Sort[i].checkpoint == -1 && Sort[i].coef != 0 ) add( list, j++, Sort[i].coef , Sort[i].expon );
			else if( Sort[i].checkpoint != -1 && Sort[i].coef != 0 )// ����Ʈ������ ó���� �ƴҶ�
			{
				P = get_node_at( list, Sort[i].checkpoint );// ���� ����Ʈ�� ������ ��ġ�� ����

				if( P->expon == Sort[i].expon )// �� ��ġ�� �������� ������ ���Ѵ�.
					P->coef += Sort[i].coef;
				else
					add( list, Sort[i].checkpoint, Sort[i].coef , Sort[i].expon );
				// �߰� ����Ʈ ������ �۵�
			}
			return 0;
}


void del( ListType *list, int pos )// ����Ʈ�� �������� ���ڷ� �޾� �����ϴ� �Լ�
{
	if( !is_empty(list) && (pos>= 0) && ( pos < list->length ) )
	{
		ListNode *p = get_node_at( list, pos-1 );
		remove_node( &(list->head), p, (p!=NULL)? p->link : NULL );
		list->length--;
	}
}

void insert_node( ListNode **phead, ListNode *p, ListNode *New_node )// ��带 �����ϴ� �Լ�( 3������� )
{
	if( *phead == NULL ) {// �������϶�
		New_node->link = NULL;
		*phead = New_node;
	}
	else if( p == NULL ) {// �����尡 NULL�̸� ù��° ���� ����
		New_node->link = *phead;
		*phead = New_node;
	}
	else{// �߰����� ����
		New_node->link = p->link;
		p->link = New_node;
	}
}



void remove_node( ListNode **phead, ListNode *p, ListNode *removed )// ������ ���� �����带 ���ڷ� ������ ����
{
	if( p == NULL )
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}



void display_recur( ListNode *head )// ��ȯ������ �̿��Ͽ� ����Ʈ�� ȭ�鿡 ���
{
	ListNode *p = head;

	if( p != NULL )
	{
		if( p->expon != 0 ) printf( "%dX^%d", p->coef, p->expon );
		else printf( "%d", p->coef );

		if( p->link != NULL ) fputs(" + ", stdout);
		display_recur(p->link);
	}
}

int Print( ListType* list1, ListType* list2, ListType* list3 )// A(x), B(x), C(x) ����Ʈ�� ����ϴ� �Լ�
{
	if( list1->head == NULL && list2->head == NULL && list3->head == NULL )// ���� ����Ʈ�� ����
	{
		fputs( "\n\n\t\t �� �ڷᰡ �����ϴ�\n", stdout );
		return 1;// �ڷ� ������ 1�� ����
	}

	fputs("\n\n\t\t A(x) = ", stdout );display_recur( list1->head );
	fputs("\n\n\t\t B(x) = ", stdout );display_recur( list2->head );
	fputs("\n\n\t\t C(x) = ", stdout );display_recur( list3->head );
	fputc('\n', stdout);

	return 0;
}



ListNode* PADD( ListType* A, ListType* B, ListType* C )// A(x), B(x)�� �����Ͽ� C(x)�� �����ϴ� �Լ�
{
	ListNode* p = A->head;
	ListNode* q = B->head;
	ListNode* c = C->head;
	ListNode* d;// ������ �ʱ���
	element x;
	
	c = ( ListNode* )malloc( sizeof(ListNode) );
	if( c == NULL ) fputs("\n\n\t\t �� �޸� �Ҵ翡��\n", stdout );
	d = c;// ���ϴ� �����Ͱ��� ���� d�� c�� ���� �ʱ���

	while( p != 0 && q != 0 )
	{
		if( p->expon == q->expon )// ������ ������
		{
			x = p->coef + q->coef;
			if( x!=0 ) d = ATTACH( x, p->expon, d );
			p = p->link;q = q->link;
		}
		else if( p->expon < q->expon )// B(x)������ ũ��
		{
			d = ATTACH( q->coef, q->expon, d );
			q = q->link;
		}
		else// A(x)������ ũ��
		{
			d = ATTACH( p->coef, p->expon, d );
			p = p->link;
		}
		C->length++;
	}

	while( p != NULL )// �������׵� ����
	{
		d = ATTACH( p->coef, p->expon, d );
		p = p->link;
	}

	while( q != NULL )// �������׵� ����
	{
		d = ATTACH( q->coef, q->expon, d );
		q = q->link;
	}
	d->link = NULL;
	p = c;c= c->link; free(p);// ����� ���ʿ����� �ʱ��� ��ȯ

	return c;
}



ListNode* ATTACH(int coef, int expon, ListNode* ptr)// New��带 �����Ͽ� ptr�����Ϳ� ��ũ��Ű�� �Լ�
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	if ( new_node == NULL ) {
		fputs("\n\n\t\t �� �޸� �Ҵ翡��\n", stdout );
		exit(1);
	}
	new_node -> coef = coef;
	new_node -> expon = expon;
	new_node -> link = NULL;

	if( ptr!=NULL ) ptr -> link = new_node;// ptr�����Ϳ� ����

	return new_node;
}


int Choices()// �۾��� �����ϱ����� �ǹ��� ���� �Լ�
{// Y�� ���ý� 1�� ���� N�� ���ý� 0�� ����

	char select;
	fputs( "\n\t\t �� ��� �Ͻðڽ��ϱ�? ( y | n ) [ ] \b\b\b", stdout );
	
	while( 1 ){

		select = getchar();
		while( getchar() != '\n' );

		if( select == 'y' || select == 'Y' || select == 'N' || select == 'n' ) break;
		fputs( "\n\t\t �� �� �� �Է��ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? ( y | n ) [ ] \b\b\b", stdout );
	}
	return ( select == 'Y' || select == 'y' )? 1 : 0;
}



int Partition( Temp a[], int left, int right )// �����Ľ� ������ ������ �۾����ϴ� �Լ�
{
	int PartElem, Value_expon, Value_coef;
	Temp tmp;
	PartElem = left;
	Value_expon = a[PartElem].expon;
	Value_coef = a[PartElem].coef;

	do{
		do{ }while( a[++left].expon > Value_expon );
		do{ }while( a[--right].expon < Value_expon );

		if( left < right )	{

			tmp.coef = a[left].coef;
			a[left].coef = a[right].coef;
			a[right].coef = tmp.coef;

			tmp.expon = a[left].expon;
			a[left].expon = a[right].expon;
			a[right].expon = tmp.expon;
		}
		else break;
	}while(1);

	a[PartElem].expon = a[right].expon;
	a[PartElem].coef = a[right].coef;

	a[right].expon = Value_expon;
	a[right].coef = Value_coef;

	return right;
}



void Quick_Sort( Temp a[], int left, int right )// ���������� ������
{
	int middle;

	if( right > left )	{

		middle = Partition( a, left, right+1 );
		Quick_Sort( a, left, middle-1 );
		Quick_Sort( a, middle+1, right );
	}
}

int Search_Node( ListType* Head )// ������ ���� �˻��� �ϴ� �Լ�
{
	ListNode* P = Head->head;
	int num, length=0;

	fputs( "\n\n\t\t �� �����Ͻ÷��� ���� ������ �Է��ϼ�R�� : ", stdout );
	scanf( "%d", &num );
	while( getchar() != '\n' );// �Է°��� ���Ͱ� ����
	
	while( P != NULL && P->expon != num ){
		P = P->link;// �켱 P�� NULL�϶����� �ݺ��Ѵ�
		length++;
	}// �׸��� ���� ��ȣ ���� ã�����ÿ� �����
	if( P == NULL )// �˻����� ������ -1��ȯ
	{
		fputs( "\n\t\t �� �����Ͱ� �����ϴ�\n", stdout );
		return -1;
	}
	return length;// ã�� Ű���� ��ġ�� ����
}

int Free_front( ListNode* Search )// ����ü ������ ���� ��带 �����Ѵ�
{
	ListNode* R;// ������ ���

	if( Search == NULL ) return 0;// ���鸮��Ʈ�� �� ����

	R = Search->link;// ������ ��� ����
	// �ʱ�ȭ�� �Ƚ�Ų ������ �߸��� ������ �߻�����
	Search->link = R->link;// ������ ��带 ���� �հ� �ڸ� �����Ŵ

	free(R);// ������ ��� FREE

	return 1;// ���� ���� ����� 1 ����
}

void ALLFREE( ListType* list )// ��� ��� ����
{
	ListNode *P= list->head;
	
	if( P->link != NULL )while( Free_front(P) && P->link );// ���� ��尡 �ƴ϶�� ��� ��� ����
	
	free( list->head );// Head ������ Free
}
