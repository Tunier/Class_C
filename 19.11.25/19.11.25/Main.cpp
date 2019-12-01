#include "Headers.h"


// ��������, ������ �ΰ�� �ʱ�ȭ
SCENEID SceneState = SCENEIDS_LOGO;



// ������
void SetScene(Object* _pPlayer);

// �÷��̾� ��ġ ���
void SetCursorPosition(float _x, float _y, char* _pTexture);

// Ű�Է� ����
void InputKey(Object* _pObj);

// �÷��̾� �̵� ���� ����
void SetDirection(Object* _pObj);

//** Logo ���� ���漱��
void LogoInitialize();
void LogoProgress();
void LogoRender();

//** Menu ���� ���漱��
void MenuInitialize();
void MenuProgress();
void MenuRender();

//** Stage ���� ���漱��
void StageInitialize(Object* _pPlayer);
void StageProgress(Object* _pPlayer);
void StageRender(Object* _pPlayer);

//** Player ���� ���漱��
void PlayerInitialize(Object* _pObj);
void PlayerProgress(Object* _pObj);
void PlayerRender(Object* _pObj);



int main(void)
{
	Object Player;
	
	// �ΰ�, �޴�, �������� �ʱ�ȭ
	LogoInitialize();
	MenuInitialize();
	StageInitialize(&Player);

	// time�� Ÿ�̸ӷ�
	DWORD dwTime = GetTickCount();
	
	// ���ѹݺ���
	while (true)
	{
		// dwTime + 80ms < Ÿ�̸� �ΰ�� dwTime�� Ÿ�̸ӷ� ����
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();

			//** ȭ���� ��� ����
			system("cls");
						
			SetScene(&Player);
		}
	}
	   	  
	return 0;
}

// Scene ��Ʈ��.
void SetScene(Object* _pPlayer)
{
	switch (SceneState)
	{
	case SCENEIDS_LOGO:
		LogoProgress();
		LogoRender();
		break;

	case SCENEIDS_MENU:
		MenuProgress();
		MenuRender();
		break;

	case SCENEIDS_STAGE:
		StageProgress(_pPlayer);
		StageRender(_pPlayer);
		break;

	case SCENEIDS_EXIT:

		break;
	}
}


//** _x, _y ��ǥ�� _pTexture �� �����.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	// x, y ��ǥ ���� ���̺귯��
	COORD Position = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	printf_s("%s\n", _pTexture);
}

// ���� ȭ��ǥŰ�� ID���� ����
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
	// ������Ű�� ������ y�� 1�� �ƴҶ� y���� -1��ŭ �ٲ�
	case ROTATEIDS_UP:
		if (_pObj->Position.y != 1)
			_pObj->Position.y -= 1;
		break;

	// �Ʒ�����Ű�� ������ y�� 27�� �ƴҶ� y���� +1��ŭ �ٲ�
	case ROTATEIDS_DOWN:
		if (_pObj->Position.y != 27)
			_pObj->Position.y += 1;
		break;

	// ������Ű�� ������ x > 2 �϶� x���� -1��ŭ �ٲ�
	case ROTATEIDS_LEFT:
		if (_pObj->Position.x > 2)
			_pObj->Position.x -= 1;
		break;

	// ������Ű�� ������ x < 116 �϶� x���� +1��ŭ �ٲ�
	case ROTATEIDS_RIGHT:
		if (_pObj->Position.x < 116)
			_pObj->Position.x += 1;
		break;
	}
}

// �ʱ�ȭ ������� �ڵ�
void PlayerInitialize(Object* _pObj)
{
	// �÷��̾� ���
	_pObj->pTexture = (char*)"��";

	// �÷��̾� ������ġ�� (59, 15)
	_pObj->Position.x = 59.f;
	_pObj->Position.y = 15.f;

	// ũ��� ���� 2(1ĭ) ���� 1(1ĭ)
	_pObj->Scale.x = 2.f;
	_pObj->Scale.y = 1.f;

	// ù ������ ����������
	_pObj->Rotate = 3;

}

// ������(����Ÿ��) ����Ǵ� ���׿� ���� �ڵ�
void PlayerProgress(Object* _pObj)
{
	//* �Է¹��� Ű�� ���¿� ���� ������ ID ������ ����.
	InputKey(_pObj);
	
	//** ������ ID ������ ������ ������ ������ ����.
	SetDirection(_pObj);
}

// ȭ�� ��³��뿡 ���� �ڵ�
void PlayerRender(Object* _pObj)
{
	//** �׸��� ���������� �ش� ��ǥ�� �����.
	SetCursorPosition(
		_pObj->Position.x,
		_pObj->Position.y,
		_pObj->pTexture);
	// int�� y �� 0, y < (30 - 1)�϶�����, y�� 1������)
	for (int y = 0; y < (30 - 1); y++)
	{
		// ���� y�� 0 �Ǵ� 28�϶�
		if (y == 0 || y == 28)
			// (0, y)�� "�������������������������������������������������������������" ���
			SetCursorPosition(0, y, (char*)"�������������������������������������������������������������");
		// y�� 0 �Ǵ� 28�� �ƴҶ��� (0, y), (118, y)�� "��" ���
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

// Logo �ʱ�ȭ
void LogoInitialize()
{

}

// Logo ������ ����, ����Ǵ� ���׵�
void LogoProgress()
{
	// '1'Ű�� ��������� �����¸� �޴��� ����
	if (GetAsyncKeyState('1'))
	{
		SceneState = SCENEIDS_MENU;
	}
}

void LogoRender()
{
	// (57, 15)�� "Logo" ���
	SetCursorPosition(57, 15, (char*)"Logo");
}


void MenuInitialize()
{

}

void MenuProgress()
{
	// '2'Ű�� ��������� �����¸� ���������� ����
	if (GetAsyncKeyState('2'))
	{
		SceneState = SCENEIDS_STAGE;
	}
}

void MenuRender()
{
	// (57, 15)�� "Menu" ���
	SetCursorPosition(57, 15, (char*)"Menu");
}


void StageInitialize(Object* _Player)
{
	PlayerInitialize(_Player);
}

void StageProgress(Object* _Player)
{
	PlayerProgress(_Player);
}

void StageRender(Object* _Player)
{
	PlayerRender(_Player);
}

