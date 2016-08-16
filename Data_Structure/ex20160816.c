#if 0
//NULL로 끝나는 Single Linked list의 자료 설계
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

#if 1
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
	NODE* list = 0;
	display_data(list);

	for (i = 0; i < 7; i++)
	{
		insert_data(&list, i + 1);
		display_data(list);
	}

	for (i = 0; i < 7; i++)
	{
		insert_data(&head, i + 1);
		display_data(head);
	}
}
#endif