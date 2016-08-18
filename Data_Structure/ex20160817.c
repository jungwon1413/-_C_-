// =========================== Double Linked List ===========================
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	struct _node* prev;
	int data;
	struct _node* next;
}NODE;

NODE head = { &head,0,&head };

void insert_data(NODE* head, NODE* temp)
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev = temp;
}
void display(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[머리]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		printf(" <-> [%d]", temp->data);
	}
	printf(" <-> [머리]\n");
	getch();
}

int main()
{
	int i;
	NODE* temp;
	display(&head);
	for (i = 0; i < 7; i++)
	{
		temp = malloc(sizeof(NODE));
		temp->data = i + 1;
		insert_data(&head, temp);
		display(&head);
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//typedef struct _node
//{
//	struct _node* prev;
//	int data;
//	struct _node* next;
//}NODE;

typedef struct _node
{
	struct _node *prev;
	void* data;
	struct _node *next;
}NODE;

NODE head = { &head,0,&head };
//--------------------------------------------------------------------------------------
void __insert_data(NODE* prev, NODE* temp, NODE* next) // 언더바2개 ( __ ) 는 파일안이나 함수안에서 쓰는것을 의미한다.
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}

//--------------------------------------------------------------------------------------
typedef struct
{
	char name[20];
}SAWON;
void display(NODE* head)
{
	NODE* temp;
	SAWON* s;
	system("cls");
	printf("[머리]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		s = (SAWON*)temp->data;
		printf(" <-> [%s]", s->name);
	}
	printf(" <-> [머리]\n");
	_getch();
}

int main()
{
	int i;
	int cnt;
	NODE* temp;
//	SAWON s[5] = { "홍길동", "이순신", "유관순", "안중근", "박문수" };
	SAWON* ptr;
	printf("인원수: ");
	scanf_s("%d", &cnt);
	getchar();

	for (i = 0; i < cnt; i++)
	{
		temp = malloc(sizeof(NODE));
		ptr = malloc(sizeof(SAWON));
		printf("이름입력: ");
		gets_s(ptr->name, strlen(ptr->name));

		temp->data = ptr;
		insert_back(&head, temp);
//		display(&head);
	}
	/*temp = malloc(sizeof(NODE));
	temp->data = 8;
	insert_front(&head, temp);
	display(&head);*/
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//typedef struct _node
//{
//	struct _node* prev;
//	int data;
//	struct _node* next;
//}NODE;

//typedef struct _node
//{
//	struct _node *prev;
//	void* data;
//	struct _node *next;
//}NODE;

typedef struct _node
{
	struct _node* prev;
	struct _node* next;
}NODE;		// 구조체의 일반화가 된 부분이구요~

NODE head = { &head, &head };
//--------------------------------------------------------------------------------------
void __insert_data(NODE* prev, NODE* temp, NODE* next) // 언더바2개 ( __ ) 는 파일안이나 함수안에서 쓰는것을 의미한다.
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}

//--------------------------------------------------------------------------------------
typedef struct
{
	char name[20];
	NODE list;
}SAWON;

#define list_entry(ptr, type, member) \
((type*)( (char*)ptr - (unsigned long) & ( (type*)0)->member) )

void display(NODE* head)
{
	NODE* temp;
	SAWON* s;
	system("cls");
	printf("[머리]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
//		s = (SAWON*)((char*)temp - (sizeof(SAWON) - sizeof(NODE)));
		//s = (SAWON*)((char*)temp - (unsigned long) &((SAWON*)0)->list);
		s = list_entry(temp, SAWON, list);
		printf(" <-> [%s]", s->name);
	}
	printf(" <-> [머리]\n");
	_getch();
}

int main()
{
	int i;

	int cnt;
	SAWON* temp;
	printf("인원수: ");
	scanf_s("%d", &cnt);
	getchar();

	for (i = 0; i < cnt; i++)
	{
		temp = malloc(sizeof(SAWON));
		printf("이름입력: ");
		gets_s(temp->name, sizeof(temp->name));

		insert_back(&head, &temp->list);
		//		display(&head);
	}
	/*temp = malloc(sizeof(NODE));
	temp->data = 8;
	insert_front(&head, temp);*/
	display(&head);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	unsigned int foo;
	char bar;
	char boo;
}NODE;

int main()
{
	NODE tmp;
	printf("tmp address: %p\n\n", &tmp);
	printf("tmp->foo address: %p \t foo offset: %lu\n", &tmp.foo, (unsigned long)&((NODE*)0)->foo);
	printf("tmp->foo address: %p \t bar offset: %lu\n", &tmp.bar, (unsigned long)&((NODE*)0)->bar);
	printf("tmp->foo address: %p \t boo offset: %lu\n", &tmp.boo, (unsigned long)&((NODE*)0)->boo);

	printf("computed address of &tmp using: \n");

	printf("address: %p\n", (struct NODE *) (((char*)&tmp.foo) - ((unsigned long) & ((NODE*)0)->foo)));
	printf("address: %p\n", (struct NODE *) (((char*)&tmp.bar) - ((unsigned long) & ((NODE*)0)->bar)));
	printf("address: %p\n", (struct NODE *) (((char*)&tmp.boo) - ((unsigned long) & ((NODE*)0)->boo)));
}

#endif