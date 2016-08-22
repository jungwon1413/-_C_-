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

#if 0
#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE *src, *dest; // source����, destination����
	int c;
	char buff[100] = { 0, };

	fopen_s(&src, "ex20160819.c", "r");
	fopen_s(&dest, "ex20160819_copy.c", "w");
	getchar(); // system("pause");�� �ᵵ �������Ű���...
	/*while ((c = fgetc(src)) != EOF)
	{
		fputc(c, dest);
	}*/
	while (fgets(buff, sizeof(buff), src))
	{
		fputs(buff, dest);
	}
	printf("\n");

	fclose(src);
	fclose(dest);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *src, *dest;
	char buff[4096] = { 0, };
	int ret;

	fopen_s(&src, "C:\\GCC_Practice\\22_22.jpg", "rb"); // �� ������ ������ �ش� ���丮�� ������ �����ؾ��Ѵ�. �׷���������� �����ν��� ���� ����....
	fopen_s(&dest, "C:\\GCC_Practice\\22_22_copy_2.jpg", "wb"); // ��μ����Ҷ��� ��������(\)�� 2���� ����ȴ�.

	//while (fgets(buff, sizeof(buff), src)) // ���̳ʸ��� �а����� fgets, fputs�� ������!!! �����Ұ�!!!
	//{
	//	fputs(buff, dest);
	//}
	while (ret = fread(buff, 1, sizeof(buff), src)) // <�ҽ�>���� <����>�� �о���̴µ� <buff������> <1>����ŭ �о�鿩��! ��� �̾߱�.
	{
		fwrite(buff, 1, ret, dest);//<����(buff)>���� <1>���� ���µ� <ret>���� ���ϵȸ�ŭ <dest>�� ���.
	}
	fclose(src);
	fclose(dest);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
#define MAX 3
typedef struct
{
	char name[20];
	int age;
	float score;
}ST;

void input(ST* s)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("%d�� �л�\n", i + 1);
		
		printf("�̸�: ");
		gets_s(s[i].name, (sizeof(char)*20));

		printf("����: ");
		scanf_s("%d", &s[i].age); // �켱������ .�� ()���� ����.

		printf("����: ");
		scanf_s("%f", &s[i].score);
		getchar(); 
	}
}
void display(ST* s)
{
	int i;
	printf("�̸�\t����\t����\n");
	printf("==============================\n");
	for (i = 0; i < MAX; i++)
		printf("%s\t%4d\t%5.2f\n", s[i].name, s[i].age, s[i].score);
}
void save_text(ST* s, char* file_name)
{
	int i;
	FILE *fp;
	fopen_s(&fp, file_name, "w+");

	for (i = 0; i < MAX; i++)
		fprintf(fp, "%s\t%4d\t%5.2f\n", s[i].name, s[i].age, s[i].score); // fp�� ����Ű��...
	fclose(fp);
}
void display_text(ST* s, char* file_name)
{
	int i;
	FILE* fp;
	memset(s, 0, sizeof(ST) * 3); // s�� 0������ ���ý��Ѷ� ~> sizeof(ST)*3��ŭ...

	fopen_s(&fp, file_name, "r");
	for (i = 0; i < MAX; i++)
		fscanf_s(fp, "%s %d %f", s[i].name, sizeof(char)*20, &s[i].age, &s[i].score);
	
	fclose(fp);

	printf("�̸�\t����\t����\n");
	printf("==============================\n");
	for (i = 0; i < MAX; i++)
		printf("%s\t%4d\t%5.2f\n", s[i].name, s[i].age, s[i].score);
}
void save_binary(ST* s, char* file_name)
{
	FILE* fp;
	fopen_s(&fp, file_name, "wb+");

	fwrite(s, sizeof(ST), 3, fp);
	fclose(fp);
}
void display_binary(ST* s, char* file_name)
{
	int i;
	FILE* fp;
	memset(s, 0, sizeof(ST) * 3);

	fopen_s(&fp, file_name, "rb");
	fread(s, sizeof(ST), 3, fp);
	fclose(fp);

	printf("�̸�\t����\t����\n");
	printf("==============================\n");
	for (i = 0; i < MAX; i++)
		printf("%s\t%4d\t%5.2f\n", s[i].name, s[i].age, s[i].score);
}
int main()
{
	char buff[4096] = { 0, };
	ST s[MAX] = { 0, };
	char file_name[100] = "C:\\GCC_Practice\\st.dat";
//	ST* p = s;

	input(s);
	//p->age = 10;
	//(p + 1)->age = 20;
	//(p + 2)->age = 30;

	//save_text(s, file_name);
	save_binary(s, file_name);
	getchar();
	//display_text(s, file_name);
	display_binary(s, file_name);
}
#endif

//#if 1
//#include <stdio.h>
//int main()
//{
//	FILE *fp;
//
//	fopen_s(&fp, "test.txt", "r+");
//	fprintf(fp, "This is testing for fprintf...\n");
//	fputs("This is testing for fputs...\n", fp);
//	fclose(fp);
//}
////#endif
//#include <stdio.h>
//int main()
//{
//	//char *p = 0;
//	char ch = 'a';
//	void *ptr;
//	ptr = ch;
//
//	printf("%c\n", (int)*ptr);
//}