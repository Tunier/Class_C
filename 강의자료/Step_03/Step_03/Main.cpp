#include <stdio.h>
#include <stdlib.h>

//** ���� ���� ���� [�̹��� ���� ->  (../Resource/��������_��������.png)]



/********************************************************************

	[�Լ� ���]

	1. ���ǿ� ����.
		���� : � ���̳� �繰�� ���� ����� ���� ������. �Ǵ� �� ��.
		���� : �θ� �켭 ����. �Ǵ� �׷� ����.  &&  ������ ������ �ڱ��� ��ħ, �ǰ�, ���� ����...

	2. �Լ� ����.
		[����� ����, �Լ� �̸�, �Է��� ����, ���� ����, ��ȯ ��]

	** �̹��� ���� ->  (../Resource/�Լ�����.png)

*********************************************************************/


int main(void)
{
	//** ���� ���� ���� [�̹��� ���� ->  (../Resource/��������_��������.png)]
	system("pause");
	
	/**************************************************************
		[������ ����]
	
		* Bit		.....>	0 & 1 �� ǥ�� ����
		* Byte		.....>	8�� -> 1 Byte
		* Kilobytes	.....>	1024 Byte -> 1 Kilobytes
		* Megabytes	.....>	1024 Kilobytes  ->  1 Megabytes
		* Gegabytes	.....>	1024 Megabytes  ->  1 Gegabytes
		* Terabytes	.....>	1024 Gegabytes  ->  1 Terabytes
		* Petabytes	.....>	1024 Terabytes  ->  1 Petabytes
		* Exabytes	.....>	1024 Petabytes  ->  1 Exabytes
		* Zettabytes	.....>	1024 Exabytes   ->  1 Zettabytes
		* Yottabytes	.....>	1024 Zettabytes ->  1 Yottabytes
	
		** �̹��� ���� ->  (.. /Resource/Data.png)
	
	**************************************************************/



	/******************************************
		
		[Operator]

		1. ��� ������
		2. �� ������
		3. �� ������


		** [��� ������]

		* [=] ����
		* [+] ���ϱ�
		* [-] ����
		* [*] ���ϱ�
		* [/] ������
		* [%] ������


		** [�� ������]

		* [&] AND 
		* [|] OR
		* [^] XOR
		* [!] NOT



		** [�� ������]

		* [<]  = A < B (A�� B���� ������?)
		* [>]  = A > B (A�� B���� ū ��?)
		
		* [<=] = A <= B (A�� B���� �۰ų� ������?)
		* [>=] = A >= B (A�� B���� ũ�ų� ������?)

		* [!=] = A != B (A�� B�� �ٸ���?)
		* [==] = A == B (A�� B�� ������?)

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

	//** Ǯ��
	printf_s("%d && %d\n", (iNumber < 100), (iNumber > 100));


	//** true
	printf_s("%d\n", (iNumber < 100) || (iNumber > 100));

	//** true
	printf_s("%d\n", (iNumber < 100) && !(iNumber > 100));


	printf_s("\n\n\n");

	system("pause");

	return 0;
}
