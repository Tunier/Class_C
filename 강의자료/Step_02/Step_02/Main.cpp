/*****************************************
	
	�ۼ��� : Winstone
	e-mail : winstone@winstonegames.com

*****************************************/
#include <stdio.h>
#include <stdlib.h> // system() = �Լ� ����� ����.


int main(void)
{
	//** [�ּ�] = �����Ϸ��� �ڵ�� �ν����� �ʴ� �޸� ����.

	// ���� �ּ� �Դϴ�.

	/*
		// �̰� ������?
		������ �ּ� �Դϴ�.
	*/


	
	/******************************************************
		Data Type

		** [������]

		signed		= ��ȣ�� ����.
		unsigned		= ��ȣ�� ����.

		* signed char	= 1 Byte
		* signed short	= 2 Byte
		* signed int	= 4 Byte
		* signed long	= 4 Byte

		* unsigned char		= 1 Byte
		* unsigned short	= 2 Byte
		* unsigned int		= 4 Byte
		* unsigned long		= 4 Byte


		** [�Ǽ���]

		* float		�Ҽ���  7��° �ڸ�
		* double		�Ҽ��� 15��° �ڸ�

		[signed, unsigned] = �Ǽ������� ������ ����.

		** �Ʒ��ʿ��� Ȯ���� ������ ����.

	*******************************************************/


	//** sizeof() = �����͸� ����Ʈ ������ ��ȯ. (��ȯ�� ��������)

	printf_s("[������] signed type\n");
	printf_s("char Type : %d Byte �Դϴ�.\n", sizeof(char));
	printf_s("short Type : %d Byte �Դϴ�.\n", sizeof(short));
	printf_s("int Type : %d Byte �Դϴ�.\n", sizeof(int));
	printf_s("long Type : %d Byte �Դϴ�.\n", sizeof(long));
	printf_s("\n");
	printf_s("[������] unsigned type\n");
	printf_s("unsigned char Type : %d Byte �Դϴ�.\n", sizeof(unsigned char));
	printf_s("unsigned short Type : %d Byte �Դϴ�.\n", sizeof(unsigned short));
	printf_s("unsigned int Type : %d Byte �Դϴ�.\n", sizeof(unsigned int));
	printf_s("unsigned long Type : %d Byte �Դϴ�.\n", sizeof(unsigned long));
	printf_s("\n");
	printf_s("[�Ǽ���]\n");
	printf_s("float Type : %d Byte �Դϴ�.\n", sizeof(float));
	printf_s("double Type : %d Byte �Դϴ�.\n", sizeof(double));


	system("pause"); //** �Ͻ� ���� �Լ�
	system("cls");	//** ȭ���� �����ִ� �Լ�


	/******************************************************
		Data ���� Ȯ��

		https://indevgame.tistory.com/9?category=831189

	*******************************************************/


	//** ����
	int a;

	//** �ʱ�ȭ
	a = 0;

	//** ����� ���ÿ� �ʱ�ȭ
	int b = 0;

	//** �������� ������ ���� �� �� �ִ�.
	int c, d;

	//** �������� ������ �ʱ�ȭ �� �� �ִ�.
	c = 0, d = 0;

	//** �������� ������ ����� ���ÿ� �ʱ�ȭ �� �� �ִ�.
	int e = 0, f = 0;


	/*********************************************************

		�� �밡���� ǥ��� ��

		1. ���̹� �˻�â���� [�밡���� ǥ���] �˻�
		2. �̹��� Ŭ��
		3. �밡���� ǥ��� ǥ Ȯ��.


		�� ���� ���� ���� ���� ��

		1. ������ �̸����� ���� �Ұ�.
		2. ���� �̸��� Ư�����ڷ� ���� �� �� ����.
		3. ���� �̸��� ���ڷ� ���� �Ҽ� ����.
		4. �����̸� ���̿� ������⸦ �� �� ����.

	*********************************************************/

	//** �߸��� ��
	/********************************************************************************

		int [#Attack = 10] �� ���� Ư�� ���ڷ� ���� �� �� ����.
		int [10Attack = 10] �� ���� ���ڷ� ���� �� �� ����.
		int [Player Attack = 10] �� ���� �����̸� ���̿� ������⸦ �� �� ����

	*********************************************************************************/


	//** ���� ��

	int iScore = 0;

	printf_s("Score : %d �� �Դϴ�.\n", iScore);

	system("pause");

	return 0;
}