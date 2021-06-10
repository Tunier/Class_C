#include <stdio.h>
#include <stdlib.h>

//** 전역 변수 지역 [이미지 참고 ->  (../Resource/전역변수_지역변수.png)]



/********************************************************************

	[함수 사용]

	1. 정의와 선언.
		정의 : 어떤 말이나 사물의 뜻을 명백히 밝혀 규정함. 또는 그 뜻.
		선언 : 널리 펴서 말함. 또는 그런 내용.  &&  국가나 집단이 자기의 방침, 의견, 주장 따위...

	2. 함수 구성.
		[출력의 형태, 함수 이름, 입력의 형태, 정의 내용, 반환 값]

	** 이미지 참고 ->  (../Resource/함수구성.png)

*********************************************************************/


int main(void)
{
	//** 지역 변수 지역 [이미지 참고 ->  (../Resource/전역변수_지역변수.png)]
	system("pause");
	
	/**************************************************************
		[데이터 단위]
	
		* Bit		.....>	0 & 1 만 표현 가능
		* Byte		.....>	8개 -> 1 Byte
		* Kilobytes	.....>	1024 Byte -> 1 Kilobytes
		* Megabytes	.....>	1024 Kilobytes  ->  1 Megabytes
		* Gegabytes	.....>	1024 Megabytes  ->  1 Gegabytes
		* Terabytes	.....>	1024 Gegabytes  ->  1 Terabytes
		* Petabytes	.....>	1024 Terabytes  ->  1 Petabytes
		* Exabytes	.....>	1024 Petabytes  ->  1 Exabytes
		* Zettabytes	.....>	1024 Exabytes   ->  1 Zettabytes
		* Yottabytes	.....>	1024 Zettabytes ->  1 Yottabytes
	
		** 이미지 참고 ->  (.. /Resource/Data.png)
	
	**************************************************************/



	/******************************************
		
		[Operator]

		1. 산술 연산자
		2. 논리 연산자
		3. 비교 연산자


		** [산술 연산자]

		* [=] 대입
		* [+] 더하기
		* [-] 빼기
		* [*] 곱하기
		* [/] 나누기
		* [%] 나머지


		** [논리 연산자]

		* [&] AND 
		* [|] OR
		* [^] XOR
		* [!] NOT



		** [비교 연산자]

		* [<]  = A < B (A가 B보다 작은가?)
		* [>]  = A > B (A가 B보다 큰 가?)
		
		* [<=] = A <= B (A가 B보다 작거나 같은가?)
		* [>=] = A >= B (A가 B보다 크거나 같은가?)

		* [!=] = A != B (A와 B가 다른가?)
		* [==] = A == B (A와 B가 같은가?)

	******************************************/


	printf_s("true = %d\n", true);	//** 1
	printf_s("false = %d\n", false);	//** 0


	//** true
	printf_s("(1 == 1) = %d\n", (1 == 1));

	//** false
	printf_s("(1 != 1) = %d\n", (1 != 1));


	int iNumber = 10;

	//** true
	printf_s("(iNum > 1) = %d\n", (iNumber > 1));

	//** true
	printf_s("(iNum < 100) = %d\n", (iNumber < 100));

	//** true
	printf_s("(iNum > 1) && (iNum < 100) = %d\n", (iNumber > 1) && (iNumber < 100));

	//** false
	printf_s("(iNum > 100) = %d\n", (iNumber > 100));


	//** false
	printf_s("%d\n", (iNumber < 100) && (iNumber > 100));

	//** 풀이
	printf_s("%d && %d\n", (iNumber < 100), (iNumber > 100));


	//** true
	printf_s("%d\n", (iNumber < 100) || (iNumber > 100));

	//** true
	printf_s("%d\n", (iNumber < 100) && !(iNumber > 100));


	printf_s("\n\n\n");

	system("pause");

	return 0;
}
