#if 0
#include <stdio.h>
int main()
{
	int score;
	printf("���� �Է�: ");
	scanf_s("%d", &score);
	printf("%d\n", score);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int score[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("���� �Է�: ");
		scanf("%d", &score[i]);
		//scanf("%d", score + i);
	}
	for (i = 0; i < 3; i++)
		printf("%d\n", score[i]);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *score;
	int n = 0;
	int i;
	printf("�ο��� �Է�: ");
	scanf_s("%d", &n);
	score = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		printf("���� �Է�: ");
		scanf_s("%d", &score[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", score[i]);
	}
	free(score);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
void init(int**, int*);
void input(int*, int);
void output(int*, int);

int main()
{
	int* score;
	int n = 0;
	init(&score, &n);
	input(score, n);
	output(score, n);
	free(score);
	return 0;
}

void init(int* *score, int* n)
{
	printf("�ο��� �Է�: ");
	scanf_s("%d", n);
	*score = (int*)malloc(sizeof(int)* (*n));
}
void input(int score[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("���� �Է�: ");
		scanf_s("%d", &score[i]);
	}
}
void output(int score[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", score[i]);
	}
}
#endif

#if 0
int main()
{
	int a[0];
	return 0;
}
#endif

#if 0
#include <stdio.h>
struct st
{
	int count;
	int aaa;
	int a[0]; // �������� ������ �����ϴ�. ������� �������� ����ȭ�� �� ���̽�....
	//a[0]�� ����Ʈ ����ó�� ����Ǵ�...�Ű���?
};

int main()
{
	struct st s;
	printf("%d\n", sizeof(s)); // a[0]�� ����ü ����� �������ʴ´�.
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct st
{
	int count;
	int entry[0]; // int entry[];�� ���µ� �����ϴ�.
};

int main() // Flexible Array�� ����
{
	struct st *s;
	int n;
	int i;

	printf("�ο���: ");
	scanf_s("%d", &n);
	s = (struct st*)malloc(sizeof(struct st) + sizeof(int)*n);
	s->count = n;
	
	for (i = 0; i < s->count; i++)
		s->entry[i] = i + 100;

	for (i = 0; i < s->count; i++)
		printf("s->entry[%d]: %d\n", i, s->entry[i]);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
struct st
{
	int count;
	struct st *next;
	int entry[];
};

int main()
{
	struct st *s;
	int n;

	s = (struct st*)malloc(4096); // 4k�� �ƿ� �Ҵ��س��� ����̴�. (���� 4k�� ���� normal�մϴ�.)
	s->count = (4096 - sizeof(struct st)) / sizeof(int);
	s->entry[0] = 100;
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	FILE *fp; // File stream (���� ��Ʈ��)�̶�� �θ���.
	int c;

	fopen_s(&fp, "ex20160819.c", "r"); // ex20160819.c�� "r"����(�б�����)���� �ҷ����ڴ�. ��� �ؼ�����

	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
		Sleep(100);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	FILE *fp;
	char buff[100] = { 0, };
	fopen_s(&fp, "ex20160819.c", "r");
	while (fgets(buff, sizeof(buff), fp))
	{
		printf("%s", buff);
		Sleep(100);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	FILE* fp;
	int c;

	fopen_s(&fp, "ex20160819.c", "rb"); // read binary
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
		Sleep(100);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
#endif

#if 1
#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE *src, *dest; // source����, destination����
	int c;

	fopen_s(&src, "ex20160819.c", "r");
	fopen_s(&dest, "ex20160819_copy.c", "w");
	getchar();
	while ((c = fgetc(src)) != EOF)
	{
		fputc(c, dest);
	}
	printf("\n");

	fclose(src);
	fclose(dest);
	return 0;
}
#endif