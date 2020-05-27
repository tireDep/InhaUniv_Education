#include<stdio.h>
#include<string.h>

struct Group_s
{
	int a;
	double b;
};

struct Score_s
{
	int math;
	int eng;
	int total;
};

struct Test_s
{
	char name;
	Score_s score;
};

// ----------------------------------------------------------------

typedef struct Group2_2
{
	int cnt;
}GroupGroup;

// ----------------------------------------------------------------

struct Pointer_s
{
	int *x;
	int *y;
	int **dy;
};

struct Point_s
{
	int x;
	int y;
};

// ----------------------------------------------------------------

struct Student_s
{
	char year[32];
	char name[32];
	int num;
};

int main()
{
	struct Group_s g1 = { 5,10.1 }, g2, g3;
	g2.a = 2;
	g2.b = 7.8;

	printf("g1\n%d\n%.2lf\n", g1.a, g1.b);
	printf("\ng2\n%d\n%.2lf\n", g2.a, g2.b);

	g3 = g1;
	printf("\ng3\n%d\n%.2lf\n", g3.a, g3.b);


	Test_s gTest = { 0 };
	gTest.score.eng = 75;
	gTest.score.math = 85;
	gTest.score.total = gTest.score.eng + gTest.score.math;
	printf("\nTotal : %d\n", gTest.score.total);

	puts("\n----------------------------------------------------------");
	// --------------------------------------------------------------------------

	GroupGroup dg;
	dg.cnt = 10;
	printf("\n%d\n", dg.cnt);

	puts("\n----------------------------------------------------------\n");
	// --------------------------------------------------------------------------

	Student_s studentG[3] = { 
		{ "2020", "Park", 100},
		{ "2020", "Kim", 90 },
		{ "2020", "Lee", 80 } 
	};

	for (int i = 0; i < 3; i++)
	{
		printf("학번 : %s, 성 : %s, 성적 : %d\n", studentG[i].year, studentG[i].name, studentG[i].num);
	}

	puts("");
	strcpy_s(studentG[0].year, "2019");
	for (int i = 0; i < 3; i++)
	{
		printf("학번 : %s, 성 : %s, 성적 : %d\n", studentG[i].year, studentG[i].name, studentG[i].num);
	}

	puts("\n----------------------------------------------------------\n");
	// --------------------------------------------------------------------------

	puts("포인터를 이용한 값 출력1");

	int num1 = 4;
	int num2 = 5;

	Pointer_s p1;
	p1.x = &num1;
	p1.y = &num2;
	p1.dy = &p1.x;

	// printf("주소\nx : %d, y : %d\n", p1.x, p1.y);
	printf("값\nx : %d, y : %d, y : %d\n", *p1.x, *p1.y, **p1.dy);

	Point_s pp1 = { 20,30 };

	printf("\n\n%x %x\n", &pp1, &pp1.x);	// 두개가 같은 값을 가리키고 있음
	printf("%d %d\n", pp1.x, pp1.y);

	puts("\n----------------------------------------------------------\n");
	// --------------------------------------------------------------------------

	Student_s stu = { "2001","Park",100 };
	Student_s *pStu = NULL;
	pStu = &stu;

	puts("포인터를 이용한 값 출력2");
	printf("%s %s %d\n", stu.year, stu.name, stu.num);
	printf("%s %s %d\n", pStu->year, pStu->name, pStu->num);
	printf("%s %s %d\n", (*pStu).year, (*pStu).name, (*pStu).num);


	return 0;
}