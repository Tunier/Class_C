#include <stdio.h>
#include <stdlib.h>

//** 구조체
struct tagStudent
{
	//char* pcName;
	int iNumber;

	int iKor;
	int iEng;
	int iMath;
};



int main(void)
{
	/*
	tagStudent tStudent;

	tStudent.iKor	= 1;
	tStudent.iEng	= 10;
	tStudent.iMath	= 100;

	printf_s("%d\n", tStudent.iKor);
	printf_s("%d\n", tStudent.iEng);
	printf_s("%d\n", tStudent.iMath);

	system("pause");
	*/



	/*************************************
		** [구조체 배열 사용]

		* 학생 성적 관리 프로그램 만들기.

	**************************************/


	const int MAX = 10;

	tagStudent tStudent[MAX];

	for (int i = 0; i < MAX; i++)
	{
		tStudent[i].iKor = 0;
		tStudent[i].iEng = 0;
		tStudent[i].iMath = 0;
		tStudent[i].iNumber = i + 1;
	}

	for (int i = 0; i < MAX; i++)
	{
		printf_s("학생 번호 : %d\n", tStudent[i].iNumber);
		printf_s("국어 점수 : %d\n", tStudent[i].iKor);
		printf_s("영어 점수 : %d\n", tStudent[i].iEng);
		printf_s("수학 점수 : %d\n", tStudent[i].iMath);
		printf_s("\n");
	}


	system("pause");

	return 0;
}






