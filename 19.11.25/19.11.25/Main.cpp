#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


struct vector3
{
	float x, y;
};

struct Object
{
	char* pTexture;
	vector3 Position;
	vector3 Scale;
	vector3 Rotate;
};

void SetCursorPosition(float _x, float _y, char* _pTexture);

int main(void)
{
	/*
	printf_s("Hello World!! \n");

	int num = 1;
	printf_s("�Է� : \n");
	scanf_s("%d", &num);
	printf_s("%d", num);
	*/

	Object player;

	player.pTexture = (char*)"��";

	player.Position.x = 6;
	player.Position.y = 6;
	
	player.Scale.x = 3;
	player.Scale.y = 4;

	player.Rotate.x = 5;
	player.Rotate.y = 6;

	/*
	printf_s("%s\n", player.pTexture);

	printf_s("%f\n", player.Position.x);
	printf_s("%f\n", player.Position.y);

	printf_s("%f\n", player.Scale.x);
	printf_s("%f\n", player.Scale.y);

	printf_s("%f\n", player.Rotate.x);
	printf_s("%f\n", player.Rotate.y);
	*/


	//** DWORD = unsigned long
	//** GetTickCount() = Ÿ�̸�(��� ������)

	//** Ÿ�̸ӷ� dwTime ���� �ʱ�ȭ.
	DWORD dwTime = GetTickCount();

	//** ���ѷ���
	while (true)
	{
		//** ���࿡ dwTime + 500 ���� GetTickCount() �� �� ũ�ٸ�...
		if (dwTime + 80 < GetTickCount())
		{
			//** �ٽ� Ÿ�̸ӷ� dwTime ���� �ʱ�ȭ.
			dwTime = GetTickCount();

			//** ȭ���� ��� ����
			system("cls");

			//** GetAsyncKeyState() = Ű �Է� Ȯ�� �Լ�.
			



			if (GetAsyncKeyState(VK_UP))
			{
				player.Position.y -= 1;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				player.Position.y += 1;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				player.Position.x += 2;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				player.Position.x -= 2;
			}
			
			
			
			
			//** �׸��� ���������� �ش� ��ǥ�� �����.
			SetCursorPosition(
				player.Position.x,
				player.Position.y,
				player.pTexture);
		}
	}
	   	  







	system("pause");

	return 0;
}


//** _x, _y ��ǥ�� _pTexture �� �����.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf_s("%s\n", _pTexture);
}

