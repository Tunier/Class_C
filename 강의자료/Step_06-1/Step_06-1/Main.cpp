#include <stdio.h>


int main(void)
{
	/*
	//** [1 ���� �迭]
	int iArray[10];

	for (int i = 0; i < 10; i++)
	{
		iArray[i] = i ;
	}

	for (int i = 0; i < 10; i++)
	{
		printf_s("%d\n", iArray[i]);
	}
	*/



	/*
	//** [2 ���� �迭]
	int iArray[2][5];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			iArray[i][j] = i * 5 + j;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf_s("%d\n", iArray[i][j]);
		}
	}
	*/



	/*
	//** [3 ���� �迭]

	int iArray[2][2][2];
	int iCount = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				iArray[i][j][k] = ++iCount;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				printf_s("%d\n", iArray[i][j][k]);
			}
		}
	}
	*/




	/*******************
		* Pointer
	********************/

	
	int iNumber = 100;
	int* piNum = &iNumber;

	printf_s("%p : iNumber �� �ּ�\n", &iNumber);
	printf_s("%p : piNum ������ ����ִ� �ּ�\n", piNum);

	printf_s("%p : piNum �� �ּ�\n", &piNum);

	printf_s("%d : piNum ������ ����ִ� �ּ��� ��\n", *piNum);
	printf_s("%d : iNumber �� ��\n", iNumber);
	



	return 0;
}
