#include <stdio.h>
#include <stdlib.h>	//** ���� ����
#include <time.h>	//** �ð� �Լ�
#include <malloc.h>	//** ���� �Ҵ�


struct tagStudent
{
	int iKor;
	int iEng;
	int iMath;
};


int main(void)
{
	//** ����ü ������

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
	//** ����ü ������ �迭
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

	//** [���� ����]
	/*
	srand(time(NULL));

	int iRand = rand();

	printf_s("%d\n", iRand);
	system("pause");
	*/




	/**********************************************

		** �ǽ� : [����ü ������ �迭 ���]

		* �ζ� ��ȣ ���� ���α׷� �����.

		�� �䱸 ���� ��

			A. ���ڴ� 1���� 45������ ������ �Ѵ�.
			B. ���ڴ� �ϳ��� ���մ� 6���� �����ϰ�,
				�ߺ��� ���� ���� �ʴ´�.

			C. �� 5 ���� ������ �����,
				���հ��� �ߺ��� ���ڴ� �������.

		** Tip

		typedef struct tagNumbers
		{
			int Number[6];

		}Numbers;

		Numbers* ptNumberList[5];

		==============================

		1 ~ 45 ������ ���� ���� ���.

		int iRand = rand() % 45 + 1;

	***********************************************/






	system("pause");

	return 0;
}