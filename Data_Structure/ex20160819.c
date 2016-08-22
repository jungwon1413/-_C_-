#if 0
#include <stdio.h>
int main()
{
	int score;
	printf("점수 입력: ");
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
		printf("점수 입력: ");
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
	printf("인원수 입력: ");
	scanf_s("%d", &n);
	score = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
	{
		printf("점수 입력: ");
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
	printf("인원수 입력: ");
	scanf_s("%d", n);
	*score = (int*)malloc(sizeof(int)* (*n));
}
void input(int score[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("점수 입력: ");
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
	int a[0]; // 마지막에 쓸때만 가능하다. 편법으로 쓰던것이 공식화가 된 케이스....
	//a[0]은 포인트 변수처럼 쓰면되는...거같다?
};

int main()
{
	struct st s;
	printf("%d\n", sizeof(s)); // a[0]은 구조체 사이즈에 잡히지않는다.
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

struct st
{
	int count;
	int entry[0]; // int entry[];의 형태도 가능하다.
};

int main() // Flexible Array의 예시
{
	struct st *s;
	int n;
	int i;

	printf("인원수: ");
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

	s = (struct st*)malloc(4096); // 4k를 아예 할당해놓은 모습이다. (보통 4k가 제일 normal합니다.)
	s->count = (4096 - sizeof(struct st)) / sizeof(int);
	s->entry[0] = 100;
}
#endif

#if 0
#include <stdio.h>
#include <Windows.h>
int main()
{
	FILE *fp; // File stream (파일 스트림)이라고 부른다.
	int c;

	fopen_s(&fp, "ex20160819.c", "r"); // ex20160819.c를 "r"형식(읽기전용)으로 불러오겠다. 라고 해석가능

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
	FILE *src, *dest; // source파일, destination파일
	int c;
	char buff[100] = { 0, };

	fopen_s(&src, "ex20160819.c", "r");
	fopen_s(&dest, "ex20160819_copy.c", "w");
	getchar(); // system("pause");를 써도 괜찮을거같다...
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

	fopen_s(&src, "C:\\GCC_Practice\\22_22.jpg", "rb"); // 단 파일을 읽을때 해당 디렉토리에 파일이 존재해야한다. 그러지않을경우 원본인식을 하지 못함....
	fopen_s(&dest, "C:\\GCC_Practice\\22_22_copy_2.jpg", "wb"); // 경로설정할때는 역슬래시(\)를 2개를 쓰면된다.

	//while (fgets(buff, sizeof(buff), src)) // 바이너리로 읽고쓰려면 fgets, fputs는 못쓴다!!! 주의할것!!!
	//{
	//	fputs(buff, dest);
	//}
	while (ret = fread(buff, 1, sizeof(buff), src)) // <소스>에서 <버퍼>로 읽어들이는데 <buff사이즈> <1>개만큼 읽어들여라! 라는 이야기.
	{
		fwrite(buff, 1, ret, dest);//<버프(buff)>에서 <1>개를 쓰는데 <ret>에서 리턴된만큼 <dest>에 써라.
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
		printf("%d번 학생\n", i + 1);
		
		printf("이름: ");
		gets_s(s[i].name, (sizeof(char)*20));

		printf("나이: ");
		scanf_s("%d", &s[i].age); // 우선순위가 .이 ()보다 높다.

		printf("점수: ");
		scanf_s("%f", &s[i].score);
		getchar(); 
	}
}
void display(ST* s)
{
	int i;
	printf("이름\t나이\t점수\n");
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
		fprintf(fp, "%s\t%4d\t%5.2f\n", s[i].name, s[i].age, s[i].score); // fp가 가리키는...
	fclose(fp);
}
void display_text(ST* s, char* file_name)
{
	int i;
	FILE* fp;
	memset(s, 0, sizeof(ST) * 3); // s를 0값으로 세팅시켜라 ~> sizeof(ST)*3만큼...

	fopen_s(&fp, file_name, "r");
	for (i = 0; i < MAX; i++)
		fscanf_s(fp, "%s %d %f", s[i].name, sizeof(char)*20, &s[i].age, &s[i].score);
	
	fclose(fp);

	printf("이름\t나이\t점수\n");
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

	printf("이름\t나이\t점수\n");
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