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
	ARG arg = { temp, &row, &col, a }; // 여기서 a는 포인터변수 한개만있으므로 위 [10][10]배열처럼 초기화시켜줄수는 없는노릇이다... 번거로움...ㅂㄷㅂㄷ

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
void bal(NODE* temp)
{
	int a[100];
	int n = 0;
	__fill(temp, a, &n);

	root = __val(a, n);
}
/*
AVL로 트리를 전환한다!!
-> 우리가 할일은 무엇인가?
1. AVL의 LL, RR, LR, RL 구현
2. tree의 search()함수 구현
*/

NODE* search(NODE* node, int key)
{
	if (node == NULL)
		return NULL;
	if (key == node->data)
		return node;
	else if (key < node->data)
		search(node->left, key);
	else
		search(node->right, key);
}
NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}

NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ( ( sizeof(a) / sizeof(a[0]) ) )
#define MAX(a,b)	( ( (a) > (b) ) ? (a) : (b) )
int get_height(NODE* node)
{
	int height = 0;
	
	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}
int get_balance(NODE* node)
{
	if (node == NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE* balance_tree(NODE** node)
{
	int height_diff;
	height_diff = get_balance(*node);

	if (height_diff > 1)
	{
		if (get_balance((*node)->left > 0))
		{
			*node = rotate_LL(*node);
		}
		else
		{
			*node = rotate_LR(*node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance((*node)->right > 0))
		{
			*node = rotate_RL(*node);
		}
		else
			*node = rotate_RR(*node);
	}
}
int main()
{
	/*NODE* node = 0;
	int i;*/
	//1. RR 일때
	/*
	int a[] = { 6,3,1,5,7,11 };
	display(root);
	for (i = 0; i < 6; i++)
	{
		insert_data(a[i]);
		display(root);
	}

	insert_data(12);
	display(root);
	printf("RR test\n");
	_getch();
	node = search(root, 6);
	node->right = rotate_RR(node->right);
	display(root);
	*/

	//2. LL 일때
	/*
	int a[] = { 7,6,3,12 };
	display(root);
	for (i = 0; i < 4; i++)
	{
		insert_data(a[i]);
		display(root);
	}
	insert_data(1);
	display(root);
	printf("LL test\n");
	_getch();
	node = search(root, 7);
	node->left = rotate_LL(node->left);
	display(root);
	*/

	//3. LR rotation
	/*
	int a[] = { 7,3,6,1,12 };
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	insert_data(5);
	display(root);
	printf("LR test\n");
	_getch();
	node = search(root, 7);
	root = rotate_LR(node);
	display(root);
	*/

	//4. RL rotation
	/*
	int a[] = { 6,3,1,5,7,12 };
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	insert_data(9);
	display(root);
	printf("RL test\n");
	_getch();
	node = search(root, 6);
	root->right = rotate_RL(node->right);
	display(root);
	*/

	NODE* node = 0;
	int i, height, in, bal;
	int a[] = { 6, 3, 1, 5, 7, 12, 4,2,9 };

	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	/*
	printf("Tree height test\n");
	_getch();
	height = get_height(root);
	printf("root height: %d\n", height);

	_getch();
	printf("insert 9\n");
	insert_data(9);
	display(root);
	height = get_height(root);
	printf("root height: %d\n", height);
	*/
	display(root);

	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in);
		getchar();
		
		if (in == -1)
			break;
		node = search(root, in);
		height = get_height(node);
		bal = get_balance(node);
		printf("%d의 높이는 %d\n", in, height);
	}
	return 0;
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
NODE* balance_tree(NODE** node);
/*
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
*/
NODE* insert_data(NODE** root, int data)
{
	NODE** p = root;
	if (*p == NULL)
	{
		*p = (NODE*)malloc(sizeof(NODE));
		if (*p == NULL)
		{
			printf("메모리 할당 실패\n");
			exit(-1);
		}
		(*p)->data = data;
		(*p)->left = (*p)->right = NULL;
	}
	else if (data < (*p)->data)
	{
		(*p)->left = insert_data(&((*p)->left), data);
		(*p) = balance_tree(p);
	}
	else if (data > (*p)->data)
	{
		(*p)->right = insert_data(&((*p)->right), data);
		(*p) = balance_tree(p);
	}
	else
	{
		printf("중복 데이터 입력\n");
		exit(-1);
	}
	return *p;
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
	ARG arg = { temp, &row, &col, a }; // 여기서 a는 포인터변수 한개만있으므로 위 [10][10]배열처럼 초기화시켜줄수는 없는노릇이다... 번거로움...ㅂㄷㅂㄷ

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
void bal(NODE* temp)
{
	int a[100];
	int n = 0;
	__fill(temp, a, &n);

	root = __val(a, n);
}
/*
AVL로 트리를 전환한다!!
-> 우리가 할일은 무엇인가?
1. AVL의 LL, RR, LR, RL 구현
2. tree의 search()함수 구현
*/

NODE* search(NODE* node, int key)
{
	if (node == NULL)
		return NULL;
	if (key == node->data)
		return node;
	else if (key < node->data)
		search(node->left, key);
	else
		search(node->right, key);
}
NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}

NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ( ( sizeof(a) / sizeof(a[0]) ) )
#define MAX(a,b)	( ( (a) > (b) ) ? (a) : (b) )
int get_height(NODE* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}
int get_balance(NODE* node)
{
	if (node == NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE* balance_tree(NODE** node)
{
	int height_diff;
	height_diff = get_balance(*node);

	if (height_diff > 1)
	{
		if (get_balance((*node)->left) > 0)
		{
			*node = rotate_LL(*node);
		}
		else
		{
			*node = rotate_LR(*node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance((*node)->right) > 0)
		{
			*node = rotate_RL(*node);
		}
		else
			*node = rotate_RR(*node);
	}
}
NODE* search_parent(NODE* node, int key)
{
	if (node->left->data == key)
		return node;

	if (node->right->data == key)
		return node;

	if (key < node->data)
		search_parent(node->left, key);
	else
		search_parent(node->right, key);
}
int main()
{
//	int a[] = { 6,3,1,5,7,12,4,2,9 };
//	int a[] = { 5,1,3,4,6,7 };
	int a[] = { 1,2,3,4,5,6,7 };
	NODE* node = 0;
//-	int i, height, in, bal;
	display(root);

	for (int i = 0; i < SIZE(a); i++)
	{
		insert_data(&root, a[i]);
		display(root);

	}

	/*
	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in);
		getchar();
		if (in == -1)
			break;
		node = search(root, in);
		bal = get_balance(node);
		printf("%d의 밸런스: %d\n", in, bal);
		if (bal < -1 || bal > 1)
		{
			node = search_parent(root, in);
			if (node->data < in)
				node->right = balance_tree(&(node->right));
			else
				node->left = balance_tree(&(node->left));
		}
		_getch();
		display(root);
	}
	*/
	return 0;
}
#endif

//////////////////////////////////////////// 여기까지 수업시간에 적다가 중간에 미스난 코드


#if 1
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct _node *left;
	int data;
	struct _node *right;
}NODE;

NODE *root = 0;
NODE * balance_tree(NODE **);


NODE * insert_data(NODE ** root, int data)
{
	NODE **p = root;

	if (*p == NULL)
	{
		*p = (NODE*)malloc(sizeof(NODE));
		if (*p == NULL)
		{
			printf("메모리 할당 실패\n");
			exit(-1);
		}
		(*p)->data = data;
		(*p)->left = (*p)->right = NULL;
	}
	else if (data < (*p)->data)
	{
		(*p)->left = insert_data(&((*p)->left), data);
		(*p) = balance_tree(p);
	}
	else if (data >(*p)->data)
	{
		(*p)->right = insert_data(&((*p)->right), data);
		(*p) = balance_tree(p);
	}
	else
	{
		printf("중복 데이터 입력\n");
		exit(-1);
	}
	return *p;
}
typedef struct _arg {
	NODE * temp;
	int(*a)[10];
	int *row;
	int *col;
}ARG;

void __display(ARG arg)
{
	ARG ar;  ar = arg;
	if (arg.temp == 0) return;
	++(*(arg.row));

	ar.temp = arg.temp->left;
	__display(ar);
	arg.a[*(arg.row)][(*(arg.col))++] = arg.temp->data;

	ar.temp = arg.temp->right;
	__display(ar);
	--(*(arg.row));
	return;
}

void display(NODE *temp)
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

NODE * search(NODE *node, int key)
{
	if (node == NULL) return NULL;

	if (key == node->data)
		return node;
	else if (key < node->data)
		search(node->left, key);
	else
		search(node->right, key);
}
NODE * rotate_RR(NODE *parent)
{
	NODE *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
NODE * rotate_LL(NODE *parent)
{
	NODE * child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;

}
NODE *rotate_LR(NODE *parent)
{
	NODE *child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);

}

NODE *rotate_RL(NODE *parent)
{
	NODE * child = parent->right;
	parent->right = rotate_LL(child);

	return rotate_RR(parent);
}

#define SIZE(a) ( (sizeof(a)) / (sizeof(a[0])))
#define MAX(a,b)   ( ( (a) > (b) ) ? (a) : (b) )
#pragma warning(disable:4996)
int get_height(NODE *node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}
int get_balance(NODE *node)
{
	if (node == NULL)return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE * balance_tree(NODE **node)
{
	int height_diff;
	height_diff = get_balance(*node);
	if (height_diff > 1)
	{
		if (get_balance((*node)->left) > 0)
		{
			*node = rotate_LL(*node);
		}
		else {
			*node = rotate_LR(*node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance((*node)->right) < 0)
		{
			*node = rotate_RR(*node);
		}
		else
		{
			*node = rotate_RL(*node);
		}
	}
	return *node;
}
NODE * search_parent(NODE *node, int key)
{
	if (node->left->data == key)
		return node;
	if (node->right->data == key)
		return node;
	if (key < node->data)
		search_parent(node->left, key);
	else
		search_parent(node->right, key);
}
int main()
{
	//	int a[] = { 6,3,1,5,7,12,4,2,9 }; // RL rotation
	//	int a[] = { 5,1,3,4,6,7 };			//LR rotation
	int a[] = { 1,2,3,4,5,6,7 };

	display(root);

	for (int i = 0; i < SIZE(a); i++)
	{
		insert_data(&root, a[i]);
		display(root);
	}

	return 0;

}
#endif


//////////////////////////////////////////// 여기까지 강사님 코드