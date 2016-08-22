#if 0
//#Step 1
//1. Tree ����
#include <stdio.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root;
int main()
{

}
#endif

#if 0
//#Step 1
//2. insert_data() ����
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;
typedef enum{LEFT, RIGHT}TYPE;

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
}
void in_order(NODE* temp)
{
	if (temp == 0)
		return;
	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}
int main()
{
	insert_data(1, 0, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	in_order(root);
}
#endif

#if 0
// #Step 1
// 3. in_order()�Լ� ����
// ������: ��� ���� ���� (���ڷ� ��µ�)
// �ذ�å: �鿩 ���⸦ �̿�����
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;
typedef enum { LEFT, RIGHT }TYPE;

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
}
//void in_order(NODE* temp)
//{
//	if (temp == 0)
//		return;
//	
//	in_order(temp->left);
//	printf("%d\n", temp->data);
//	in_order(temp->right);
//}
void display(NODE* temp)
{
	int i;
	static int indent = -1;
	
	if (temp == 0)
		return;

	indent++;
	//display(temp->left);
	display(temp->right);
	/*for (i = 0; i < indent; i++)
		printf("%4c", ' ');
	printf("%4d\n", temp->data);*/
	printf("%*d\n", indent * 4, temp->data); // �� �ּ��� 3�ٰ� ���� ���̴�...?
	//in_order(temp->right);
	display(temp->left);
	indent--;
}

int main()
{
	insert_data(1, 0, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	display(root);
}
#endif

#if 0
// #Step 1
// 3. in_order()�Լ� ����
// ������: ��� ���� ���� (���ڷ� ��µ�)
// �ذ�å: �鿩 ���⸦ �̿�����
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;
typedef enum { LEFT, RIGHT }TYPE;

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
}
void display(NODE* temp)
{
	int i;
	static int indent = -1;

	if (temp == 0)
		return;

	indent++;
	display(temp->right);
	printf("%*d\n", indent * 4, temp->data); // "%(indent*4)d\n"�� ����������. (%0d, %4d, %8d, ...)
	display(temp->left);
	indent--;
}

int main()
{
	insert_data(1, 0, LEFT);
	insert_data(2, root, LEFT);
	insert_data(3, root, RIGHT);
	insert_data(4, root->left, LEFT);
	insert_data(5, root->left, RIGHT);
	insert_data(6, root->right, LEFT);
	insert_data(7, root->right, RIGHT);

	display(root);
}
#endif

#if 0
// #Step 1
// 3. in_order()�Լ� ����
// ������: ��� ���� ���� (���ڷ� ��µ�)
// �ذ�å: �鿩 ���⸦ �̿�����
// ������2: ������ ���η� ��µȴ�...
// �ذ�å2: �迭�� �̿��ؼ� �������!
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node* left;
	int data;
	struct _node* right;
}NODE;

NODE* root = 0;
typedef enum { LEFT, RIGHT }TYPE;

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
}

int(*__display(NODE* temp))[10]
{
	static int row = -1;
	static int col = 0;
	static int a[10][10] = { 0, };

	if (temp == 0)
		return a;

	row++;
	__display(temp->right);
	//printf("%*d\n", indent * 4, temp->data);
	a[row][col++] = temp->data;
	__display(temp->left);
	row--;
	return a;
}
//indent ==> row
//col����, �迭���� a[10][10]
void display(NODE* temp)
{
	int(*a)[10];
	a = __display(temp);
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (a[i][j] != 0)
				printf("%4d", a[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	system("pause");
	return;
}

int main()
{
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
}
#endif

#if 0
// #Step 1
// 3. in_order()�Լ� ����
// ������: ��� ���� ���� (���ڷ� ��µ�)
// �ذ�å: �鿩 ���⸦ �̿�����
// ������2: ������ ���η� ��µȴ�...
// �ذ�å2: �迭�� �̿��ؼ� �������!
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
typedef enum { LEFT, RIGHT }TYPE;

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
}

void __display(int* row, int* col, int (*a)[10], NODE* temp)
{
	if (temp == 0)
		return;

	(*row)++;
	__display(row, col, a, temp->left);
	a[*row][(*col)++] = temp->data;
	__display(row, col, a, temp->right);
	(*row)--;
	return;
}
//indent ==> row
//col����, �迭���� a[10][10]
void display(NODE* temp)
{
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };
	
	int i, j;
	__display(&row, &col, a, temp);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j] != 0)
				printf("%4d", a[i][j]);
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
}
#endif

#if 1
// #Step 1
// 3. in_order()�Լ� ����
// ������: ��� ���� ���� (���ڷ� ��µ�)
// �ذ�å: �鿩 ���⸦ �̿�����
// ������2: ������ ���η� ��µȴ�...
// �ذ�å2: �迭�� �̿��ؼ� �������!
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
typedef enum { LEFT, RIGHT }TYPE;

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
}
#endif