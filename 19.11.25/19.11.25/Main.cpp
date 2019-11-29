#include "Headers.h"

void Initialize(Object* _pObj);
void Progress(Object* _pObj);
void Render(Object* _pObj);

void SetCursorPosition(float _x, float _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDirection(Object* _pObj);

int main(void)
{
	Object player;
	Initialize(&player);

	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 60 < GetTickCount())
		{
			dwTime = GetTickCount();

			//** ȭ���� ��� ����
			system("cls");

			Progress(&player);
			Render(&player);

		}
	}
	   	  
	system("pause");

	return 0;
}


// �ʱ�ȭ ������� �ڵ�
void Initialize(Object* _pObj)
{
	_pObj->pTexture = (char*)"��";

	_pObj->Position.x = 59.f;
	_pObj->Position.y = 15.f;

	_pObj->Scale.x = 2.f;
	_pObj->Scale.y = 1.f;

	_pObj->Rotate = 3;

}

// ������ ����Ǵ� ���׿� ���� �ڵ�
void Progress(Object* _pObj)
{
	//* �Է¹��� Ű�� ���¿� ���� ������ ID ������ ����.
	InputKey(_pObj);
	
	//** ������ ID ������ ������ ������ ������ ����.
	SetDirection(_pObj);
}

// ��³��뿡 ���� �ڵ�
void Render(Object* _pObj)
{
	//** �׸��� ���������� �ش� ��ǥ�� �����.
	SetCursorPosition(
		_pObj->Position.x,
		_pObj->Position.y,
		_pObj->pTexture);

	for (int y = 0; y < (30 - 1); y++)
	{
		if (y == 0 || y == 28)
			SetCursorPosition(0, y, (char*)"�������������������������������������������������������������");
		else
		{
			SetCursorPosition(0, y, (char*)"��");
			SetCursorPosition(118, y, (char*)"��");
		}
	}
	/*
	for (int y = 0; y < (30 - 1); y++)
	{
		for (int x = 0; x < (120 - 1); x+=2)
		{
			if (y == 0 || y == 28)
				SetCursorPosition(x, y, (char*)"��");
			else
			{
				SetCursorPosition(0, y, (char*)"��");
				SetCursorPosition(118, y, (char*)"��");
			}
		}
	}
	*/
}

// cpu ������ ó�� �������� �˻�

//** _x, _y ��ǥ�� _pTexture �� �����.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	printf_s("%s\n", _pTexture);
}

//=> �Է¹��� ȭ��ǥŰ�� ID���� ������.   (enum ROTATEIDS ���� ����)
void InputKey(Object* _pObj)
{
	if (GetAsyncKeyState(VK_UP))
		_pObj->Rotate = ROTATEIDS_UP;

	if (GetAsyncKeyState(VK_DOWN))
		_pObj->Rotate = ROTATEIDS_DOWN;

	if (GetAsyncKeyState(VK_LEFT))
		_pObj->Rotate = ROTATEIDS_LEFT;

	if (GetAsyncKeyState(VK_RIGHT))
		_pObj->Rotate = ROTATEIDS_RIGHT;
}

void SetDirection(Object* _pObj)
{
	//** ������ ID ������ ������ ������ ������ ������.
	switch (_pObj->Rotate)
	{
	case ROTATEIDS_UP:
		if (_pObj->Position.y != 1)
			_pObj->Position.y -= 1;
		break;

	case ROTATEIDS_DOWN:
		if (_pObj->Position.y != 27)
			_pObj->Position.y += 1;
		break;

	case ROTATEIDS_LEFT:
		if (_pObj->Position.x > 2)
			_pObj->Position.x -= 1;
		break;

	case ROTATEIDS_RIGHT:
		if (_pObj->Position.x < 116)
			_pObj->Position.x += 1;
		break;
	}
}