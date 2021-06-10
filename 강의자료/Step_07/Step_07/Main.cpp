#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*********************
		* 배열과 포인터
	**********************/

	//**  [실습]
	
	/*
	int iNum1 = 10;
	int iNum2 = 20;

	iNum1 = iNum2;

	int* piNum1 = &iNum1;

	int* piNum2;

	piNum2 = piNum1;
	*/



	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int* piPointer = iArray;

	printf_s("%d\n", *(piPointer++));
	printf_s("%d\n", *(piPointer++));
	printf_s("%d\n", *(piPointer));
	printf_s("%d\n", *(piPointer + 1));
	printf_s("%d\n", *(piPointer + 2));
	printf_s("%d\n", *(piPointer + 3));	// <= 쓰레기 값

	system("pause");
	*/ 
	
	


	





	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int* piter = iArray;

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", *(piter + i));
	}
	system("pause");
	*/
	











	/*
	int iArray[5] = { 0, 1, 2, 3, 4 };
	int* piPointer = iArray;

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", piPointer[i]);
	}
	system("pause");
	*/







	/********************************************************
		** [배열과 문자열]

		* [PPT 참고 ->  (../Resource/배열_문자열.png)]



		* [서식 문자] 
		
			%c = 문자 출력
			%s = 문자열 출력

	********************************************************/

	//**  [실습]
	
	/*
	char cArray[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	char* piter = cArray;

	for (int i = 0; i < 6; i++)
	{
		printf_s("%c", *(piter + i));
	}
	printf_s("\n");

	printf_s("%s\n", cArray);

	system("pause");
	*/
	




	/*
	char cString[] = { 'H', 'i', 0, 'T', 'h', 'e', 'r', 'e', 32 };
	
	for (int i = 0; i < 9; i++)
	{
		printf_s("%c", cString[i]);
	}
	printf_s("\n");

	printf_s("%s\n", cString);

	system("pause");
	*/
	






	/********************************************************
		** [포인터 문자열]

		* [PPT 참고 ->  (.. / Resource / 배열_문자열.png)]

	********************************************************/


	//**  [실습]

	/*
	char* pcString = (char*)"홍길동";
	
	printf_s("%s\n", pcString);
	
	//printf_s("%c\n", pcString[0]);
	
	system("pause");
	*/
	


	return 0;
}