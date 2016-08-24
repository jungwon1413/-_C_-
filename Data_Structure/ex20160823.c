#if 0
/* #Step 1
 //3. in_order()�Լ� ����
 ������: ��� ���� ���� (���ڷ� ��µ�)
 �ذ�å: �鿩 ���⸦ �̿�����
 ������2: ������ ���η� ��µȴ�...
 �ذ�å2: �迭�� �̿��ؼ� �������!
 ������3: ���α׷��� ���� �̷��� ©��...? (-_-)
 �ذ�å: ���� ����Ž��Ʈ�� ���� ���α׷�
	�� �� ���Խ� �ڵ����� ��ġ�� ã�� ����..
	insert_data() �ٽ� ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;
/*typedef enum { LEFT, RIGHT }TYPE;

void insert_data(int data, NODE* s, TYPE type)
{
	NODE* temp;
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;

	if (root == 0)
	{
		root = temp;
		return;
	}

	if (type == LEFT)
		s->left = temp;
	else if (type == RIGHT)
		s->right = temp;
}*/

void insert_data(int data)
{
	NODE* temp;
	NODE** p = &root;
	NODE* prev = 0;

	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	if (root == 0)
	{
		root = temp;
		return;
	}

	while (*p)
	{
		if ((*p)->data > data)
		{
			p = &(*p)->left;
		}
		else if ((*p)->data < data)
		{
			p = &(*p)->right;
		}
		else
			return;
	}
	*p = temp;
}

typedef struct _arg
{
	NODE* temp;
	int* row;
	int* col;
	int(*a)[10];
}ARG;

//void __display(int* row, int* col, int(*a)[10], NODE* temp)
void __display(ARG arg)
{
	ARG ar;
	ar = arg;

	if (arg.temp == 0)
		return;

	(*(arg.row))++;
	//arg.temp = arg.temp->left;
	ar.temp = arg.temp->left;
	__display(ar);

	(arg.a)[*(arg.row)][(*(arg.col))++] = (arg.temp)->data;

	//arg.temp = arg.temp->right;
	ar.temp = arg.temp->right;
	__display(ar);
	(*(arg.row))--;
	return;
}
//indent ==> row
//col����, �迭���� a[10][10]
void display(NODE* temp)
{
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };
	ARG arg = { temp, &row, &col, a }; // ���⼭ a�� �����ͺ��� �Ѱ��������Ƿ� �� [10][10]�迭ó�� �ʱ�ȭ�����ټ��� ���³븩�̴�... ���ŷο�...��������
									   /*arg.temp = temp;
									   arg.row = &row;
									   arg.col = &col;
									   arg.a = a;*/

	int i, j;
	__display(arg);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((arg.a)[i][j] != 0)
				printf("%4d", (arg.a)[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	_getch();
	return;
}

int main()
{
	/*
	display(root);
	insert_data(1, 0, LEFT);
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);
	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);
	display(root);
	*/
	int a[] = { 4,2,1,3,6,5,7 };
	int i;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;

void insert_data(int data)
{
	NODE* temp;
	NODE** p = &root;
	NODE* prev = 0;

	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	if (root == 0)
	{
		root = temp;
		return;
	}

	while (*p)
	{
		if ((*p)->data > data)
		{
			p = &(*p)->left;
		}
		else if ((*p)->data < data)
		{
			p = &(*p)->right;
		}
		else
			return;
	}
	*p = temp;
}

typedef struct _arg
{
	NODE* temp;
	int* row;
	int* col;
	int(*a)[10];
}ARG;

void __display(ARG arg)
{
	ARG ar;
	ar = arg;

	if (arg.temp == 0)
		return;

	(*(arg.row))++;
	ar.temp = arg.temp->left;
	__display(ar);

	(arg.a)[*(arg.row)][(*(arg.col))++] = (arg.temp)->data;

	ar.temp = arg.temp->right;
	__display(ar);
	(*(arg.row))--;
	return;
}

void display(NODE* temp)
{
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };
	ARG arg = { temp, &row, &col, a }; // ���⼭ a�� �����ͺ��� �Ѱ��������Ƿ� �� [10][10]�迭ó�� �ʱ�ȭ�����ټ��� ���³븩�̴�... ���ŷο�...��������

	int i, j;
	__display(arg);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if ((arg.a)[i][j] != 0)
				printf("%4d", (arg.a)[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	_getch();
	return;
}
void __fill(NODE* temp, int* a, int* n)
{
	if (temp == 0)
		return;
	__fill(temp->left, a, n);
	a[(*n)++] = temp->data;
	__fill(temp->right, a, n);
}
NODE* __val(int* a, int n)
{
	int mid = n / 2;
	NODE *temp;

	if (n < 1)
		return 0;
	temp = malloc(sizeof(NODE));
	temp->data = a[mid];
	temp->left = __val(a, mid);
	temp->right = __val(a + (n - mid), mid);
	return temp;
}
void val(NODE* temp)
{
	int a[100];
	int n = 0;
	__fill(temp, a, &n);

	root = __val(a, n);
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7 };
	int i;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
	}
	val(root);
	display(root);
}
#endif