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

#if 1
#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE *src, *dest; // source파일, destination파일
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