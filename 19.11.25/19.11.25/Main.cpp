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
	printf_s("입력 : \n");
	scanf_s("%d", &num);
	printf_s("%d", num);
	*/

	Object player;

	player.pTexture = (char*)"■";

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
	//** GetTickCount() = 타이머(계속 증가함)

	//** 타이머로 dwTime 값을 초기화.
	DWORD dwTime = GetTickCount();

	//** 무한루프
	while (true)
	{
		//** 만약에 dwTime + 500 보다 GetTickCount() 가 더 크다면...
		if (dwTime + 80 < GetTickCount())
		{
			//** 다시 타이머로 dwTime 값을 초기화.
			dwTime = GetTickCount();

			//** 화면을 모두 지움
			system("cls");

			//** GetAsyncKeyState() = 키 입력 확인 함수.
			



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
			
			
			
			
			//** 그리고 마지막으로 해당 좌표에 출력함.
			SetCursorPosition(
				player.Position.x,
				player.Position.y,
				player.pTexture);
		}
	}
	   	  







	system("pause");

	return 0;
}


//** _x, _y 좌표에 _pTexture 을 출력함.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf_s("%s\n", _pTexture);
}

