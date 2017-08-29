#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30
typedef int element;

typedef struct ListNode{// 다항식리스트의각항을표시하게될구조체변수
	int coef;
	int expon;
	struct ListNode *link;
}ListNode;

typedef struct {// 리스트해더로쓰일구조체변수
	ListNode * head;
	int length;
}ListType;

typedef struct {// 입력받을때임시저장을위한구조체변수
	int coef;
	int expon;
	int checkpoint;
}Temp;

void init( ListType *list )// 리스트초기화함수
{
	list->length = 0;
	list->head = NULL;
}


int is_empty( ListType *list )// 리스트가비어있는지확인
{
	if( list->head == NULL ) return 1;
	else return 0;
}


int get_length( ListType *list )// 리스트의길이를구하는함수
{
	return list->length;
}


void add( ListType *list, int position, element coef, element expon );// 계수와지수를인자로받아노드를구성하는함수
void del( ListType *list, int pos );// 리스트의포지션을인자로받아삭제하는함수
void insert_node( ListNode **phead, ListNode *p, ListNode *New_node );// 노드를 삽입하는 함수( 3가지경우 )
void remove_node( ListNode **phead, ListNode *p, ListNode *removed );// 삭제될 노드와 선행노드를 인자로 가져와 삭제
void display_recur( ListNode *head );// 순환구문을 이용하여 리스트를 화면에 출력
ListNode* PADD( ListType* A, ListType* B, ListType* C );// A(x), B(x)를 연산하여 C(x)를 구성하는 함수
ListNode* ATTACH(int coef, int expon, ListNode* ptr);// New노드를 구성하여 ptr포인터에 링크시키는 함수
ListNode* get_node_at( ListType *list, int pos );// 리스트에서 포지션에 따른 노드포인터를 반환
void Menu( ListType* list1, ListType* list2, ListType* list3 );// 프로그램의 메인메뉴
int Insert( ListType* list );// 문자열로 입력받아 정렬하여 리스트를 구성하는 함수
int Print( ListType* list1, ListType* list2, ListType* list3 );// A(x), B(x), C(x) 리스트를 출력하는 함수
int Choices();// 작업을 수행하기전에 되물어 보는 함수
int Partition( Temp a[], int left, int right );// 퀵정렬시 구간을 나누는 작업을하는 함수
void Quick_Sort( Temp a[], int left, int right );// 순환을 사용한 빠른정렬인 퀵정렬
int Search_Node( ListType* Head );// 삭제를 위한 검색을 하는 함수
int Free_front( ListNode* Search );// 구조체 포인터 다음 노드를 삭제한다
void ALLFREE( ListType* list );// 모든 노드 해제


int main()
{
	ListType list1, list2, list3;// 해더리스트 선언

	init( &list1 );// 리스트 초기화
	init( &list2 );
	init( &list3 );

	Menu( &list1, &list2, &list3 );// 프로그램 메인메뉴 호출

	return 0;
}


void Menu( ListType* list1, ListType* list2, ListType* list3 )
{
	int select;
	int length=0, yesno=0;

	while( 1 )
	{
		system("cls");
		fputs( "\t\t┏━━━━━━━━━━━━━━━━━━━┓\n", stdout );
		fputs( "\t\t┃ ┃\n", stdout );
		fputs( "\t\t┃ 다항식덧셈 프로그램 ┃\n", stdout );
		fputs( "\t\t┃ 멀티미디어공학과 ┃\n", stdout );
		fputs( "\t\t┃ 20040417 이태호 ┃\n", stdout );
		fputs( "\t\t┣━━━━┯━━━━┯━━━━┯━━━━┫\n", stdout );
		fputs( "\t\t┃⑴입력 │ ⑵출력 │ ⑶삭제 │ ⑷종료 ┃\n", stdout );
		fputs( "\t\t┗━━━━┷━━━━┷━━━━┷━━━━┛\n", stdout );
		fputs( "\t\t ▶ 수행하실 작업을 입력하세요 : [ ]\b\b", stdout );
		scanf("%d", &select);

		while( getchar() != '\n' );

		switch( select )
		{
		case 1 :
			fputs( "\n\t\t【 입력 합니다 】 ", stdout );
			fputs( "\n\n\t\t A(x) 다항식을 입력하세요 (계수, 지수순)\n\n\t\t ", stdout );
			Insert( list1 );// 삽입함수 호출
			fputs( "\n\n\t\t B(x) 다항식을 입력하세요 (계수, 지수순)\n\n\t\t ", stdout );
			Insert( list2 );// 삽입함수 호출
			break;

		case 2 :
			fputs( "\n\t\t【 출력 합니다 】 ", stdout );
			list3->head = PADD( list1, list2, list3 );// list3 = list1 + list2
			Print( list1, list2, list3 );// 계산된 값을 출력
			break;
			
		case 3 :
			fputs( "\n\t\t【 삭제 합니다 】 ", stdout );
			list3->head = PADD( list1, list2, list3 );// list3 = list1 + list2

			if( Print( list1, list2, list3 ) ) break;// 삭제하기전 리스트 출력
			// 출력리스트 없으면 종료
			printf( "\n\t\t ＊ 삭제할 다항식을 선택하세요.\n" );

			while(1){
				printf( "\n\t\t ＊ A(x)는 '1', B(x)는 '2' ▶ < >\b\b");
				scanf( "%d", &select );
				while( getchar() != '\n' );

				switch( select ){
				case 1 :
					if( -1 == (length=Search_Node( list1 )) ) break;
					// 데이터가 없다면 -1 을 리턴함
					if( !(yesno = Choices()) ) break;// "삭제를 계속 하시겠습니까?"
					del( list1, length );// 확인됐다면 삭제
					break;

				case 2 :					
					if( -1 == (length=Search_Node( list2 )) ) break;
					// 데이터가 없다면 -1 을 리턴함
					if( !(yesno = Choices()) ) break;// "삭제를 계속 하시겠습니까?"
					del( list2, length );// 확인됐다면 삭제
					break;
				}

				if( ( select == 1 || select == 2 ) && length != -1 ) break;
				// 정상적인 수행후에는 종료

				fputs( "\n\t\t ＊ 잘 못 입력하셨습니다.\n", stdout );

				if( !Choices() ) break;// 잘 못 입력했을때 동작
			}
			
			if( yesno == 1 ) fputs( "\n\t\t ＊ 데이터가 삭제 되었습니다\n", stdout );
			// 삭제를 확인했다면 출력
			break;
			
		case 4 :
			fputs( "\n\t\t【 종료 합니다 】 ", stdout );
			if( !Choices() ) break;
			if( list1->head != NULL ) ALLFREE( list1 );// 생성한 노드 Free
			if( list2->head != NULL ) ALLFREE( list2 );// 생성한 노드 Free
			if( list3->head != NULL ) ALLFREE( list3 );// 생성한 노드 Free

			fputs( "\n\n\t\t\t이용해 주셔서 감사합니다^^\n\n", stdout );
			exit(1);// 종료
			break;

		default :
			fputs("\n\t\t【 잘 못 입력하셨습니다 】\n", stdout );
		}
		fputs( "\n\t\t ▶ 계속하시려면 엔터를 누르세요", stdout );
		while( getchar() != '\n' );
	}
}

ListNode *get_node_at( ListType *list, int pos )// 리스트에서 포지션에 따른 노드포인터를 반환
{
	int i;
	ListNode *tmp_node = list->head;

	if( pos < 0 ) return NULL;

	for( i=0 ; i<pos ; i++ )
		tmp_node = tmp_node->link;

	return tmp_node;
}



void add( ListType *list, int position, element coef, element expon )// 계수와 지수를 인자로 받아 노드를 구성
{
	ListNode *p;

	if( (position >= 0 ) && ( position <= list->length ) )// 포지션의 허용범위 안에서
	{
		ListNode *node = ( ListNode* )malloc( sizeof(ListNode) );
		
		if( node == NULL ) fputs("\n\n\t\t ＊ 메모리 할당에러\n", stdout );

		node->coef = coef;// NewNode 계수 구성
		node->expon = expon;// NewNode 지수 구성
		node->link = NULL;// NewNode 마지막은 NULL

		p = get_node_at(list, position-1);// 포지션의 값에 따른 노드포인터를 획득
		insert_node( &(list->head), p, node );// 노드삽입
		list->length++;// 삽입후 노드길이 증가
	}
}

int Insert( ListType* list )// 문자열로 입력받아 정렬하여 리스트를 구성하는 함수
{
	Temp Sort[MAX];
	char input[MAX] = {0, };
	char *ptr, *start;
	int i, j, k;
	ListNode* P = list->head;

	fgets( input, MAX, stdin );// 사용자 입력
	input[ strlen(input) -1 ] = '\0';// 엔터값 삭제
	
	for( i=0, j=0, k=0 ; i < (int)strlen(input) ; i++ )
	{
		start = &input[i];// 배열 인덱스에 해당하는 주소를 포인터에 대입

		if( !(input[i] >= 48 && input[i] <= 57) ) continue;// 정수범위가 아니면 continue

		if( j++%2 == 0 ) Sort[k].coef = strtol( &input[i], &ptr, 10 );// ptr은 오류가 난 지점의 주소를 리턴받음
		else {
			Sort[k].expon = strtol( &input[i], &ptr, 10 );
			Sort[k++].checkpoint=-1;// 추가노드의 위치정보를 담을 checkpoint변수
		}

		while( start++ != ptr ) i++;// 오류가 난 지점까지 인덱스를 끌어올리기
	}

	Quick_Sort( Sort, 0, k-1 );// 입력받은 데이타 퀵정렬

	if( P != NULL )// 추가 입력발생시 새로운노드의 위치를 지정해줌
		for(i=0 ; i<k ; i++ )
		{
			Sort[i].checkpoint=0;
			while( P->expon > Sort[i].expon ) {// 구성된 노드에 추가할 위치를 정함
				P = P->link;
				Sort[i].checkpoint++;// checkpoint가 추가노드를 넣을 위치
			}
		}

		for( i=0, j=0 ; i < k ; i++ )// 계수가 0인 노드를 제외한 단순연결리스트 구성하기
			if( Sort[i].checkpoint == -1 && Sort[i].coef != 0 ) add( list, j++, Sort[i].coef , Sort[i].expon );
			else if( Sort[i].checkpoint != -1 && Sort[i].coef != 0 )// 리스트구성이 처음이 아닐때
			{
				P = get_node_at( list, Sort[i].checkpoint );// 현재 리스트를 구성할 위치를 구함

				if( P->expon == Sort[i].expon )// 그 위치의 지수값이 같으면 더한다.
					P->coef += Sort[i].coef;
				else
					add( list, Sort[i].checkpoint, Sort[i].coef , Sort[i].expon );
				// 추가 리스트 구성시 작동
			}
			return 0;
}


void del( ListType *list, int pos )// 리스트의 포지션을 인자로 받아 삭제하는 함수
{
	if( !is_empty(list) && (pos>= 0) && ( pos < list->length ) )
	{
		ListNode *p = get_node_at( list, pos-1 );
		remove_node( &(list->head), p, (p!=NULL)? p->link : NULL );
		list->length--;
	}
}

void insert_node( ListNode **phead, ListNode *p, ListNode *New_node )// 노드를 삽입하는 함수( 3가지경우 )
{
	if( *phead == NULL ) {// 공백노드일때
		New_node->link = NULL;
		*phead = New_node;
	}
	else if( p == NULL ) {// 선행노드가 NULL이면 첫번째 노드로 삽입
		New_node->link = *phead;
		*phead = New_node;
	}
	else{// 중간노드로 삽입
		New_node->link = p->link;
		p->link = New_node;
	}
}



void remove_node( ListNode **phead, ListNode *p, ListNode *removed )// 삭제될 노드와 선행노드를 인자로 가져와 삭제
{
	if( p == NULL )
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}



void display_recur( ListNode *head )// 순환구문을 이용하여 리스트를 화면에 출력
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

int Print( ListType* list1, ListType* list2, ListType* list3 )// A(x), B(x), C(x) 리스트를 출력하는 함수
{
	if( list1->head == NULL && list2->head == NULL && list3->head == NULL )// 공백 리스트면 종료
	{
		fputs( "\n\n\t\t ＊ 자료가 없습니다\n", stdout );
		return 1;// 자료 없을시 1을 리턴
	}

	fputs("\n\n\t\t A(x) = ", stdout );display_recur( list1->head );
	fputs("\n\n\t\t B(x) = ", stdout );display_recur( list2->head );
	fputs("\n\n\t\t C(x) = ", stdout );display_recur( list3->head );
	fputc('\n', stdout);

	return 0;
}



ListNode* PADD( ListType* A, ListType* B, ListType* C )// A(x), B(x)를 연산하여 C(x)를 구성하는 함수
{
	ListNode* p = A->head;
	ListNode* q = B->head;
	ListNode* c = C->head;
	ListNode* d;// 삭제할 초기노드
	element x;
	
	c = ( ListNode* )malloc( sizeof(ListNode) );
	if( c == NULL ) fputs("\n\n\t\t ＊ 메모리 할당에러\n", stdout );
	d = c;// 변하는 포인터값을 지닐 d는 c를 위한 초기노드

	while( p != 0 && q != 0 )
	{
		if( p->expon == q->expon )// 지수가 같으면
		{
			x = p->coef + q->coef;
			if( x!=0 ) d = ATTACH( x, p->expon, d );
			p = p->link;q = q->link;
		}
		else if( p->expon < q->expon )// B(x)지수가 크면
		{
			d = ATTACH( q->coef, q->expon, d );
			q = q->link;
		}
		else// A(x)지수가 크면
		{
			d = ATTACH( p->coef, p->expon, d );
			p = p->link;
		}
		C->length++;
	}

	while( p != NULL )// 나머지항들 복사
	{
		d = ATTACH( p->coef, p->expon, d );
		p = p->link;
	}

	while( q != NULL )// 나머지항들 복사
	{
		d = ATTACH( q->coef, q->expon, d );
		q = q->link;
	}
	d->link = NULL;
	p = c;c= c->link; free(p);// 사용이 불필요해진 초기노드 반환

	return c;
}



ListNode* ATTACH(int coef, int expon, ListNode* ptr)// New노드를 구성하여 ptr포인터에 링크시키는 함수
{
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));

	if ( new_node == NULL ) {
		fputs("\n\n\t\t ＊ 메모리 할당에러\n", stdout );
		exit(1);
	}
	new_node -> coef = coef;
	new_node -> expon = expon;
	new_node -> link = NULL;

	if( ptr!=NULL ) ptr -> link = new_node;// ptr포인터에 연결

	return new_node;
}


int Choices()// 작업을 수행하기전에 되물어 보는 함수
{// Y를 선택시 1을 리턴 N를 선택시 0을 리턴

	char select;
	fputs( "\n\t\t ＊ 계속 하시겠습니까? ( y | n ) [ ] \b\b\b", stdout );
	
	while( 1 ){

		select = getchar();
		while( getchar() != '\n' );

		if( select == 'y' || select == 'Y' || select == 'N' || select == 'n' ) break;
		fputs( "\n\t\t ＊ 잘 못 입력하셨습니다. 계속하시겠습니까? ( y | n ) [ ] \b\b\b", stdout );
	}
	return ( select == 'Y' || select == 'y' )? 1 : 0;
}



int Partition( Temp a[], int left, int right )// 퀵정렬시 구간을 나누는 작업을하는 함수
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



void Quick_Sort( Temp a[], int left, int right )// 빠른정렬인 퀵정렬
{
	int middle;

	if( right > left )	{

		middle = Partition( a, left, right+1 );
		Quick_Sort( a, left, middle-1 );
		Quick_Sort( a, middle+1, right );
	}
}

int Search_Node( ListType* Head )// 삭제를 위한 검색을 하는 함수
{
	ListNode* P = Head->head;
	int num, length=0;

	fputs( "\n\n\t\t ＊ 삭제하시려는 항의 지수를 입력하세R요 : ", stdout );
	scanf( "%d", &num );
	while( getchar() != '\n' );// 입력값의 엔터값 삭제
	
	while( P != NULL && P->expon != num ){
		P = P->link;// 우선 P가 NULL일때까지 반복한다
		length++;
	}// 그리고 같은 번호 값을 찾았을시에 멈춘다
	if( P == NULL )// 검색값이 없으면 -1반환
	{
		fputs( "\n\t\t ＊ 데이터가 없습니다\n", stdout );
		return -1;
	}
	return length;// 찾는 키값의 위치를 리턴
}

int Free_front( ListNode* Search )// 구조체 포인터 다음 노드를 삭제한다
{
	ListNode* R;// 삭제할 노드

	if( Search == NULL ) return 0;// 공백리스트일 때 종료

	R = Search->link;// 삭제할 노드 대입
	// 초기화로 안시킨 이유는 잘못된 참조가 발생가능
	Search->link = R->link;// 삭제할 노드를 빼고 앞과 뒤를 연결시킴

	free(R);// 삭제할 노드 FREE

	return 1;// 삭제 정상 수행시 1 리턴
}

void ALLFREE( ListType* list )// 모든 노드 해제
{
	ListNode *P= list->head;
	
	if( P->link != NULL )while( Free_front(P) && P->link );// 공백 노드가 아니라면 모든 노드 해제
	
	free( list->head );// Head 포인터 Free
}
