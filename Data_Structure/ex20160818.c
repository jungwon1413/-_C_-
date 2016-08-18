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
}NODE;		// ����ü�� �Ϲ�ȭ�� �� �κ��̱���~

//NODE head = { &head,&head };

void __insert_data(NODE* prev, NODE* temp, NODE* next) // �����2�� ( __ ) �� ���Ͼ��̳� �Լ��ȿ��� ���°��� �ǹ��Ѵ�.
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

typedef enum { COM, ES, EA }FLAG;
NODE company = { &company, &company };
NODE e_system = { &e_system, &e_system };
NODE e_app = { &e_app, &e_app };

typedef struct
{
	char name[20];
	NODE bit_head;
	NODE bit_ES;
	NODE bit_EA;
}M_BIT;

#define list_entry(ptr, type, member) \
((type*)( (char*)ptr - (unsigned long) & ( (type*)0)->member) )

void display(NODE* head, int flag)
{
	NODE* temp;
	M_BIT* s;
	system("cls");
	printf("[Head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		if (flag == 1)
			s = list_entry(temp, M_BIT, bit_ES); // ��ü ����� �������� ���
		else if (flag == 2)
			s = list_entry(temp, M_BIT, bit_EA);
		else
			s = list_entry(temp, M_BIT, bit_head);
		printf(" <-> [%s]", s->name);
	}

	printf(" <-> [�Ӹ�]\n");
	_getch();
}

int main()
{
	int i;
	int cnt;
	int cat;
	M_BIT* temp;
	printf("�ο���: ");
	scanf_s("%d", &cnt);
	getchar();

	
	for (i = 0; i < cnt; i++)
	{
		temp = malloc(sizeof(M_BIT));
		printf("�̸��Է�: ");
		gets_s(temp->name, sizeof(temp->name));
		
		insert_back(&company, &temp->bit_head);
		printf("�ش� �μ�(1: ES // 2: EA): ");
		scanf_s("%d", &cat);
		getchar();

		switch (cat) {
		case 1:
			insert_front(&e_system, &temp->bit_ES);
			break;
		case 2:
			insert_front(&e_app, &temp->bit_EA);
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ش� ȸ����� ���Ҽ����� �����մϴ�.\n");
			break;
		}
	}

	system("cls");
	while (cat)
	{
		printf("���ϴ� �޴��� �������ּ���...\n");
		printf("1. Embedded System ������ ����\n");
		printf("2. Embedded Application ������ ����\n");
		printf("3. Bit Company ��� ������ ����\n");
		printf("0. ����\n");
		scanf_s("%d", &cat);

		switch (cat)
		{
		case 1:
			display(&e_system, ES);
			break;
		case 2:
			display(&e_app, EA);
			break;
		case 3:
			display(&company, COM);
			break;
		case 0:
			cat = 0;
		}
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#pragma warning(disable: 4703)
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
}NODE;		// ����ü�� �Ϲ�ȭ�� �� �κ��̱���~

			//NODE head = { &head,&head };

void __insert_data(NODE* prev, NODE* temp, NODE* next) // �����2�� ( __ ) �� ���Ͼ��̳� �Լ��ȿ��� ���°��� �ǹ��Ѵ�.
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

typedef enum { COM, ES, EA }FLAG;
NODE company = { &company, &company };
NODE e_system = { &e_system, &e_system };
NODE e_app = { &e_app, &e_app };

typedef struct
{
	char name[20];
	NODE bit_head;
	NODE bit_ES;
	NODE bit_EA;
}M_BIT;

#define list_entry(ptr, type, member) \
((type*)( (char*)ptr - (unsigned long) & ( (type*)0)->member) )

void display(NODE* head, int flag)
{
	NODE* temp;
	M_BIT* s;
	system("cls");
	printf("[Head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		switch (flag)
		{
		case ES:
			s = list_entry(temp, M_BIT, bit_ES); // ��ü ����� �������� ���
			break;
		case EA:
			s = list_entry(temp, M_BIT, bit_EA);
			break;
		case COM:
			s = list_entry(temp, M_BIT, bit_head);
			break;
		}
		printf(" <-> [%s]", s->name);
	}

	printf(" <-> [�Ӹ�]\n");
	_getch();
}

int main()
{
	int i;
	int cnt;
	int part;
	FLAG f = COM;
	M_BIT* temp;
	printf("�ο���: ");
	scanf_s("%d", &cnt);
	getchar();


	for (i = 0; i < cnt; i++)
	{
		temp = malloc(sizeof(M_BIT));
		printf("�̸��Է�: ");
		gets_s(temp->name, sizeof(temp->name));

		insert_back(&company, &temp->bit_head);
		printf("�ش� �μ�(1: ES // 2: EA): ");
		scanf_s("%d", &part);
		getchar();

		switch (part) {
		case 1:
			insert_front(&e_system, &temp->bit_ES);
			break;
		case 2:
			insert_front(&e_app, &temp->bit_EA);
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ش� ȸ����� ���Ҽ����� �����մϴ�.\n");
			break;
		}
	}

	while (part)
	{
		system("cls");
		printf("���ϴ� �޴��� �������ּ���...\n");
		printf("1. Embedded System ������ ����\n");
		printf("2. Embedded Application ������ ����\n");
		printf("3. Bit Company ��� ������ ����\n");
		printf("0. ����\n");
		
		scanf_s("%d", &part);

		switch (part){
		case 1:
			display(&e_system, ES);
			break;
		case 2:
			display(&e_app, EA);
			break;
		case 3:
			display(&company, COM);
			break;
		case 0:
			part = 0;
		}
	}
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int a = 3, b = 4;

//	a ^= b ^= a ^= b; // #1
	
	/*
	#2
	a = a + b;
	b = a - b;
	a = a - b;
	*/

	/*
	#3
	a = a * b;
	b = a / b;
	a = a / b;
	*/

	/*
	#4
	#define SWAP(a,b) (a ^= b ^= a ^= b) // ��ũ�η� �ھƳֱ�
	*/

	printf("a: %d, b: %d\n", a, b);
}
#endif

#if 0
// Bit field �������!
#include <stdio.h>
int main()
{
	int flag[4] = { 0, };
	int i;

	flag[0] = 1;
	flag[3] = 1;
	for (i = 0; i < 4; i++)
		if (flag[i])
			printf("%d\n", i);
	flag[3] = 0;
	printf("-------\n");
	for (i = 0; i < 4; i++)
		if (flag[i])
			printf("%d\n", i);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int flags = 0;
	int i;

	//flags = flags | 1 << 0;
	flags |= 1 << 0;
	//flags = flags | 1 << 3;
	flags |= 1 << 3;

	for (i = 0; i < 4; i++)
		if (flags & (1 << i))
			printf("%d\n", i);

	//flags = flags & ~8;
	flags &= ~(1 << 3);

	printf("-------\n");
	for (i = 0; i < 4; i++)
		if (flags & (1 << i))
			printf("%d\n", i);
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int flags[32] = { 0, };
	int i;

	flags[700 / 32] |= 1 << (700 % 32);
	flags[800 / 32] |= 1 << (800 % 32);
	
	for (i = 0; i < 1024; i++)
		if (flags[i / 32] & (1 << (i % 32)))
			printf("%d\n", i);
	flags[800 / 32] &= ~(1 << (800 % 32));
	printf("---------\n");
	for (i = 0; i < 1024; i++)
		if (flags[i / 32] & (1 << (i % 32)))
			printf("%d\n", i);
}
#endif

#if 1
#include <stdio.h>
#define BIT_SET(index, x) (x[index/32] |= (1 << (index % 32)))
#define BIT_ISSET(index, x) (x[index/32] & (1 << (index % 32)))
#define BIT_CLR(index, x) (x[index/32] &= ~(1 << (index % 32)))
//#define BIT_ZERO(x) { int i; for (i = 0; i < 32; i++) x[i] = 0; }
//#define BIT_ZERO(x) for(int i = 0; i < 32; x[i++] = 0)
#define BIT_ZERO(x) do{int i; for (i=0; i<32; i++) x[i]=0;} while(0) // �����ݷ��� �����ϱ����� do-while�� ����(������ ���...�̶�� �ؾ��ϳ�?)���� �ϳ��̴�.
typedef int bit_set[32]; // ���⼭�� int[32]�� Ÿ���� ������ ���ذ��̴�. �Լ������Ͷ��� ������ �����ϴ�.
typedef enum { FALSE, TRUE }INIT;

int main()
{
	int i;
	bit_set flags;
	INIT init;
	init = TRUE;
	if (init == TRUE)
		BIT_ZERO(flags);
	else
		printf("������\n");


	BIT_SET(700, flags);
	BIT_SET(800, flags);

	for (i = 0; i < 1024; i++)
		if (BIT_ISSET(i, flags))
			printf("%d\n", i);

	BIT_CLR(800, flags);
	printf("---------\n");

	for (i = 0; i < 1024; i++)
		if (BIT_ISSET(i, flags))
			printf("%d\n", i);
}
#endif