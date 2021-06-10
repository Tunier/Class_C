#include <stdio.h>
#include <stdlib.h>	//** 난수 생성
#include <time.h>	//** 시간 함수
#include <malloc.h>	//** 동적 할당


struct tagStudent
{
	int iKor;
	int iEng;
	int iMath;
};


int main(void)
{
	//** 구조체 포인터

	/*
	tagStudent* ptStudent = (tagStudent*)malloc(sizeof(tagStudent));

	ptStudent->iKor	= 0;
	ptStudent->iEng	= 0;
	ptStudent->iMath	= 0;

	printf_s( "%d\n", ptStudent->iKor );
	printf_s("%d\n", ptStudent->iEng);
	printf_s("%d\n", ptStudent->iMath);

	system("pause");
	*/



	/*
	//** 구조체 포인터 배열
	tagStudent* ptStudent[3];

	for (int i = 0; i < 3; i++)
	{
		ptStudent[i] = (tagStudent*)malloc(sizeof(tagStudent));
		ptStudent[i]->iKor = 0;
		ptStudent[i]->iEng = 0;
		ptStudent[i]->iMath = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		printf_s("%d\n", ptStudent[i]->iKor);
		printf_s("%d\n", ptStudent[i]->iEng);
		printf_s("%d\n", ptStudent[i]->iMath);
	}

	system("pause");
	*/

	//** [난수 생성]
	/*
	srand(time(NULL));

	int iRand = rand();

	printf_s("%d\n", iRand);
	system("pause");
	*/




	/**********************************************

		** 실습 : [구조체 포인터 배열 사용]

		* 로또 번호 생성 프로그램 만들기.

		※ 요구 사항 ※

			A. 숫자는 1부터 45까지의 정수로 한다.
			B. 숫자는 하나의 조합당 6개를 포함하고,
				중복된 수는 갖지 않는다.

			C. 총 5 개의 조합을 만들고,
				조합간의 중복된 숫자는 상관없다.

		** Tip

		typedef struct tagNumbers
		{
			int Number[6];

		}Numbers;

		Numbers* ptNumberList[5];

		==============================

		1 ~ 45 사이의 난수 생성 방법.

		int iRand = rand() % 45 + 1;

	***********************************************/






	system("pause");

	return 0;
}