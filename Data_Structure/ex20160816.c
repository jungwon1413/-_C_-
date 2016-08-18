#if 0
//NULL�� ������ Single Linked list�� �ڷ� ����
#include <stdio.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

NODE *head;
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

NODE *head = 0;
void insert_data(int data)
{
	NODE *temp;
	
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}
void display_data()
{
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head; temp != 0; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}

int main()
{
	int i;
	NODE* list;
	for (i = 0; i < 7; i++)
	{
		insert_data(i + 1);
		display_data();
	}
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

NODE *head = 0;

void insert_data(NODE** head, int data)
{
	NODE *temp;

	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
//���ϴ� ��ġ �ڿ� ��带 �����ϰ� �ʹ�.
void insert_next(NODE** head, int data)
{
	NODE* temp;
	
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = (*head)->next; // �켱������ *���� ->�� ����. �׷��Ƿ� ()�ʿ�
	(*head)->next = temp;
}
void display_data(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[HEAD]");
	for (temp = head; temp != 0; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}

int main()
{
	int i;
	NODE* temp;
	display_data(head);

	for (i=0; i<7; i++)
	{
		insert_data(&head, i + 1);
		display_data(head);
	}

	for (temp = head; temp->data != 3; temp = temp->next);

	insert_next(&temp, 25);
	display_data(head);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

//NODE *head = 0;
NODE head = { 0,0 };

//�Լ� ������ �Ϲ�ȭ
void insert_data(NODE* head, int data)
{
	NODE *temp;

	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void display_data(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[�Ӹ�]");
	for (temp = head->next; temp != 0; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}

int main()
{
	int i;
	NODE* temp;
	display_data(&head);

	for (i = 0; i<7; i++)
	{
		insert_data(&head, i + 1);
		display_data(&head);
	}

	for (temp = head.next; temp->data != 3; temp = temp->next);

	insert_data(temp, 25);
	display_data(&head);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

//NODE *head = 0;
NODE head = { 0,0 };
NODE tail = { 0,0 };

void init(void)
{
	head.next = &tail;
	tail.next = &tail;
}
//�Լ� ������ �Ϲ�ȭ
void insert_data(NODE* head, int data)
{
	NODE *temp;

	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void display_data(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[�Ӹ�]");
	for (temp = head->next; temp != &tail; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}

int main()
{
	int i;
	NODE* temp;
	init();
	display_data(&head);

	for (i = 0; i<7; i++)
	{
		insert_data(&head, i + 1);
		display_data(&head);
	}

	for (temp = head.next; temp->data != 3; temp = temp->next);

	insert_data(temp, 25);
	display_data(&head);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

//NODE *head = 0;
NODE head = { 0,&head };
//NODE tail = { 0,0 };

//void init(void)
//{
//	head.next = &tail;
//	tail.next = &tail;
//}

//�Լ� ������ �Ϲ�ȭ
void insert_data(NODE* head, NODE* temp)
{
	
	temp->next = head->next;
	head->next = temp;
}

void display_data(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[�Ӹ�]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}

int main()
{
	int i;
	NODE* temp;
	NODE list = { 0,&list };
	//	init();
	display_data(&head);

	for (i = 0; i<7; i++)
	{
		temp = malloc(sizeof(NODE));
		temp->data = i+1;

		insert_data(&head, temp);
		display_data(&head);
	}

	for (temp = head.next; temp->data != 3; temp = temp->next);

	insert_data(temp, 25);
	display_data(&head);
	printf("========================\n");
	display_data(&list);
	for (i = 0; i<7; i++)
	{
		temp = malloc(sizeof(NODE));
		temp->data = 7-i;
		insert_data(&list, temp);
		display_data(&list);
	}
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	int data;
	struct _Node *next;
}NODE;

//NODE *head = 0;
NODE head = { 0,&head };
//NODE tail = { 0,0 };

//void init(void)
//{
//	head.next = &tail;
//	tail.next = &tail;
//}

//�Լ� ������ �Ϲ�ȭ
void insert_data(NODE* head, NODE* temp)
{

	temp->next = head->next;
	head->next = temp;
}

void display_data(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[�Ӹ�]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		printf(" -> [%d]", temp->data);
	}
	getchar();
}
void reverse(NODE* head)
{
	NODE* prev = head, *curr, *next;
	curr = prev->next;
	while (curr != head)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}
void reverse_display(NODE* target)
{
	NODE* temp;
	temp = target->next;

	if (temp->next != &head)
		reverse_display(target->next);
	printf(" -> [%d]", temp->data);
}

int main()
{
	int i;
	NODE* temp;
	NODE list = { 0,&list };
	//	init();
	display_data(&head);

	for (i = 0; i<7; i++)
	{
		temp = malloc(sizeof(NODE));
		temp->data = i + 1;

		insert_data(&head, temp);
		display_data(&head);
	}
	printf("[�Ӹ�]");
	reverse_display(&head);
	printf("\n");
}
#endif

// ==========================Single Linked List============================