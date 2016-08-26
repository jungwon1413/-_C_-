#if 1
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
/*
typedef struct rb_node
{
	unsigned long rb_parent_color;
	struct rb_node *rb_left;
	struct rb_node *rb_right;
}RB_NODE;

#define rb_parent(r)	( (strut rb_node* )( (r)->rb_parent_color & ~3))
#define rb_color(r)		( (r)->rb_parent_color & 1)
#define rb_is_red(r)	(!rb_color(r))
#define rb_set_black(r)	do{ (r)->rb_parent_color |= 1;}while(0)
#define rb_set_red(r)	do{ (r)->rb_parent_color &= ~1;}while(0)
*/
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

typedef struct
{
	int data;
	int color;
}INFO;

#define MAX 15
typedef struct _arg {
	RB_NODE * temp;
	INFO (*a)[MAX];
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
	arg.a[*(arg.row)][(*(arg.col))].color = arg.temp->color;
	arg.a[*(arg.row)][(*(arg.col))++].data = arg.temp->data;

	ar.temp = arg.temp->right;
	__display(ar);
	--(*(arg.row));
	return;
}

void display(RB_NODE *temp)
{
	int row = -1;
	int col = 0;
	INFO a[MAX][MAX] = { 0, };
	ARG arg;

	arg.temp = temp;
	arg.row = &row;
	arg.col = &col;
	arg.a = a;

	int i, j;
	system("cls");

	__display(arg);
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (a[i][j].data != 0)
			{
				if (a[i][j].color == RB_Red)
					printf("[%d]", a[i][j].data);
				else
					printf(" %d ", a[i][j].data);
			}
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	getchar();
	return;
}
#define SIZE(a) (sizeof(a) / sizeof(a[0]))
void erase_color_rb(RB_NODE* node, RB_NODE* parent, RB_NODE** root);
void erase_rb(RB_NODE *node, RB_NODE** root)
{
	RB_NODE *child, *parent;
	int color;

	if (!node->left)
	{
		child = node->right;
	}
	else if (!node->right)
	{
		child = node->left;
	}
	else
	{
		RB_NODE *old = node, *left;
		node = node->right;
		while ((left = node->left) != NULL)
			node = left;
		if (old->parent)
		{
			if (old->parent->left == old)
				old->parent->left = node;
			else
				old->parent->right = node;
		}
		else
			*root = node;
		child = node->right;
		parent = node->parent;
		color = node->color;

		if (parent == old)
		{
			parent = node;
		}
		else
		{
			if (child)
				child->parent = parent;
			parent->left = child;
			node->right = old->right;
			old->right->parent = node;
		}

		node->color = old->color;
		node->parent = old->parent;
		node->left = old->left;
		old->left->parent = node;
		goto COLOR;
	}
	parent = node->parent;
	color = node->color;

	if (child)
		child->parent = parent;

	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		*root = child;
COLOR:
	if (color == RB_Black)
		//printf("Let's go erase_color\n");
		erase_color_rb(child, parent, root);
}

void erase_data(RB_NODE** root, int data)
{
	RB_NODE** p = root;
	RB_NODE* parent = NULL;

	while (*p)
	{
		parent = *p;
		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
		else if ((*p)->data == data)
			break;
		else
			return;
	}
	//	printf("data: %d, node.data: %d\n", data, (*p)->data);
	erase_rb(*p, root);
}
void erase_color_rb(RB_NODE* node, RB_NODE* parent, RB_NODE** root)
{
	struct rb_node* other;

	while ((!node || node->color == RB_Black) && node != *root)
	{
		if (parent->left == node) // 왼쪽
		{
			other = parent->right;
			if (other->color == RB_Red) // Case 2
			{
				other->color = RB_Black;
				parent->color = RB_Red;
				rotate_left(parent, root);
				other = parent->right;
			}
			if ((!other->left || other->left->color == RB_Black) && (!other->right || other->right->color == RB_Black)) // Case 3 (P: black) & 4 (P: Red) -> (Case 2를 거쳐온 Case 4)
			{
				other->color = RB_Red;
				node = parent;
				parent = node->parent;
			}
			else // Case 5
			{
				if ((!other->left || other->left->color == RB_Red) && (!other->right || other->right->color == RB_Black))
				{
					other->left->color = RB_Black;
					other->color = RB_Red;
					rotate_right(other, root);
					other = parent->right;
				}
				other->color = parent->color;
				parent->color = RB_Black;
				other->right->color = RB_Black;
				rotate_left(parent, root);
				node = *root;
				break;
			}
		}
		else // Case 6
		{
			other = parent->left;
			if (other->color == RB_Red)
			{
				other->color = RB_Black;
				parent->color = RB_Red;
				rotate_right(parent, root);
				other = parent->left;
			}
			if ((!other->left || other->left->color == RB_Black) && (!other->right || other->right->color == RB_Black))
			{
				other->color = RB_Red;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if ((!other->left || other->left->color == RB_Black) && (!other->right || other->right->color == RB_Red))
				{
					other->right->color = RB_Black;
					other->color = RB_Red;
					rotate_left(other, root);
					other = parent->left;
				}
				other->color = parent->color;
				parent->color = RB_Black;
				other->left->color = RB_Black;
				rotate_right(parent, root);
				break;
			}
		}
	}
	if (node)
		node->color = RB_Black;
}
int main()
{
	/*
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	display(root);
	for (int i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	erase_data(&root, 4);
	display(root);
	erase_data(&root, 7);
	display(root);
	*/

	int i, re;
	display(root);

	for (i = 0; i < MAX; i++)
	{
		insert_data(i + 1);
		display(root);
	}

	while (1)
	{
		printf("지울노드 입력(exit: -1): ");
		scanf_s("%d", &re);
		if (re == -1)
			break;
		erase_data(&root, re);
		display(root);
	}
}
#endif