#if 0
/*
#Step 1
1. RB-Tree 설계
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct rb_node
{
	struct rb_node *parent;
	struct rb_node *l_child;
	struct rb_node *r_child;
	int color;
	int data;
}RB_NODE;

RB_NODE* root = 0;


int main()
{

}
#endif

#if 0
/*
#Step 1
1. RB-Tree 설계
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct rb_node
{
	struct rb_node *parent;
	struct rb_node *left;
	struct rb_node *right;
	int color;
	int data;
}RB_NODE;

RB_NODE* root = 0;

void insert_data(int data)
{
	RB_NODE* temp;
	RB_NODE** p = &root;
	RB_NODE* parent = NULL;

	temp = malloc(sizeof(RB_NODE));
	temp->data = data;
	temp->left = temp->right = temp->parent = 0;

	while (*p)
	{
		parent = *p;

		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
		else
			return;
	}
	temp->parent = parent;
	*p = temp;
}
typedef struct _arg {
	RB_NODE * temp;
	int(*a)[10];
	int *row;
	int *col;
}ARG;

void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++(*(arg.row));

	ar.temp = arg.temp->left;
	__display(ar);
	arg.a[*(arg.row)][(*(arg.col))++] = arg.temp->data;

	ar.temp = arg.temp->right;
	__display(ar);
	--(*(arg.row));
	return;
}

void display(RB_NODE *temp)
{
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };
	ARG arg;

	arg.temp = temp;
	arg.row = &row;
	arg.col = &col;
	arg.a = a;

	int i, j;
	system("cls");

	__display(arg);
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
	getchar();
	return;
}
int main()
{
	int a[] = { 4,2,1,3,6,5,7 };
	int i;
	RB_NODE* s;

	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}
}
#endif

#if 0
/*
#Step 1
1. RB-Tree 설계
2. RB_rotate 설계
*/
#include <stdio.h>
#include <stdlib.h>
#define RB_Black	0
#define RB_Red		1
typedef struct rb_node
{
	struct rb_node *parent;
	struct rb_node *left;
	struct rb_node *right;
	int color;
	int data;
}RB_NODE;

RB_NODE* root = 0;

void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* RB_right = node->right;
	RB_NODE* parent = node->parent;

	if ((node->right = RB_right->left))
		RB_right->left->parent = node;
	RB_right->left = node;

	RB_right->parent = parent;

	if (parent)
	{
		if (node == parent->left)
			parent->left = RB_right;
		else
			parent->right = RB_right;
	}
	else
		*root = RB_right;
	node->parent = RB_right;
}
void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* RB_left = node->left;
	RB_NODE* parent = node->parent;

	if ((node->left = RB_left->right))
		RB_left->right->parent = node;
	RB_left->right = node;

	RB_left->parent = parent;

	if (parent)
	{
		if (node == parent->right)
			parent->right = RB_left;
		else
			parent->left = RB_left;
	}
	else
		*root = RB_left;
	node->parent = RB_left;
}
void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE *parent, *gparent, *uncle, *temp;
	while ((parent = node->parent) && (parent->color == RB_Red))
	{
		gparent = parent->parent;
		if (parent == gparent->left)
		{
			uncle = gparent->right;
			if (uncle && (uncle->color == RB_Red))
			{
				uncle->color = RB_Black;
				parent->color = RB_Black;
				gparent->color = RB_Red;
				node = gparent;
				continue; // while의 시작으로 다시 올라간다. 즉, 다시 while문을 처음부터 시작한다는 말이다. 할아버지부터 다시 검사를 한다는 뜻임!
			}
			if (parent->right == node)
			{
				rotate_left(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			parent->color = RB_Black;
			gparent->color = RB_Red;
			rotate_right(gparent, root);
		}
		else
		{
			uncle = gparent->left;
			if (uncle && (uncle->color == RB_Red))
			{
				uncle->color = RB_Black;
				parent->color = RB_Black;
				gparent->color = RB_Red;
				node = gparent;
				continue; // 위와 동일
			}
			if (parent->left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			parent->color = RB_Black;
			gparent->color = RB_Red;
			rotate_left(gparent, root);
		}
	}
	(*root)->color = RB_Black;
}
void insert_data(int data)
{
	RB_NODE* temp;
	RB_NODE** p = &root;
	RB_NODE* parent = NULL;

	temp = malloc(sizeof(RB_NODE));
	temp->data = data;
	temp->color = RB_Red;
	temp->left = temp->right = temp->parent = 0;

	while (*p)
	{
		parent = *p;

		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
		else
			return;
	}
	temp->parent = parent;
	*p = temp;
	
	insert_color(temp, &root);
}

typedef struct _arg {
	RB_NODE * temp;
	int(*a)[10];
	int *row;
	int *col;
}ARG;

void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++(*(arg.row));

	ar.temp = arg.temp->left;
	__display(ar);
	arg.a[*(arg.row)][(*(arg.col))++] = arg.temp->data;

	ar.temp = arg.temp->right;
	__display(ar);
	--(*(arg.row));
	return;
}

void display(RB_NODE *temp)
{
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };
	ARG arg;

	arg.temp = temp;
	arg.row = &row;
	arg.col = &col;
	arg.a = a;

	int i, j;
	system("cls");

	__display(arg);
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
	getchar();
	return;
}
#define SIZE(a) (sizeof(a) / sizeof(a[0]))
int main()
{
	/*
	#Case 1
	int a[] = { 2,1,3,4,5 };
	int i;
	RB_NODE* s;

	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	s = root->right;
	rotate_left(s, &root);
	//rotate_left(root, &root);
	display(root);
	*/

	/*
	#Case 2
	int a[] = { 6,4,2,1,3,5 };
	int i;
	RB_NODE* s;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	s = root->left;
	rotate_right(s, &root);
	display(root);
	*/

	int a[] = { 1,2,3,4,5,6,7 };
	display(root);
	for (int i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
}
#endif