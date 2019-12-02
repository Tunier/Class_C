#include "Headers.h"


#define HEAD 0



SCENEID SceneState = SCENEIDS_LOGO;

int Length = 0;


//** Manager ************************************************

void SetScene(Object* _pPlayer[]);

void SetCursorPosition(float _x, float _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDircetion(Object* _pObj);

void Collision(Object* _Temp, Object* _Dest);
//***********************************************************



//** Logo
void LogoInitialize();
void LogoProgress();
void LogoRender();

//** Menu
void MenuInitialize();
void MenuProgress();
void MenuRender();

//** Stage
void StageInitialize(Object* _pPlayer[]);
void StageProgress(Object* _pPlayer[]);
void StageRender(Object* _pPlayer[]);


//** Player
void PlayerInitialize(Object* _pPlayer[]);
void PlayerProgress(Object* _pPlayer[]);
void PlayerRender(Object* _pPlayer[]);


//** Target
void TargetInitialize(Object* _pObj);
void TargetProgress(Object* _pObj);
void TargetRender(Object* _pObj);



int main(void)
{
	Object* Player[128];
	Object

	for (int i = 0; i < 128; ++i)
		Player[i] = (Object*)malloc(sizeof(Object));

	LogoInitialize();
	MenuInitialize();
	StageInitialize(Player);

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 100 < GetTickCount())
		{
			dwTime = GetTickCount();

			system("cls");

			SetScene(Player);
		}
	}

	return 0;
}

//=> ���� ������.
void SetScene(Object* _pPlayer[])
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
		exit(NULL);
		break;
	}
}



//=> _x, _y ��ǥ�� _pTexture �� �����.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

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


//=> ������ ������ ��ü�� ������ �޾� ������ ������ ������ ������.
void SetDircetion(Object* _pObj)
{
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
			_pObj->Position.x -= 2;
		break;

	case ROTATEIDS_RIGHT:
		if (_pObj->Position.x < 116)
			_pObj->Position.x += 2;
		break;
	}
}

//=> �ΰ��� ������Ʈ�� �浹�ߴ��� Ȯ��.
void Collision(Object* _Temp, Object* _Dest)
{

}


//=> Logo �ʱ�ȭ ������ �ۼ���.
void LogoInitialize()
{

}

//=> Logo ������׿����� �ڵ带 �ۼ���.
void LogoProgress()
{
	if (GetAsyncKeyState('1'))
	{
		SceneState = SCENEIDS_MENU;
	}
}

//=> Logo ��³��뿡���� �ڵ带 �ۼ���.
void LogoRender()
{
	SetCursorPosition(57, 15, (char*)"Logo");
}

//=> Menu �ʱ�ȭ ������ �ۼ���.
void MenuInitialize()
{

}

//=> Menu ������׿����� �ڵ带 �ۼ���.
void MenuProgress()
{
	if (GetAsyncKeyState('2'))
	{
		SceneState = SCENEIDS_STAGE;
	}
}

//=> Menu ��³��뿡���� �ڵ带 �ۼ���.
void MenuRender()
{
	SetCursorPosition(57, 15, (char*)"Menu");
}

//=> Stage �ʱ�ȭ ������ �ۼ���.
void StageInitialize(Object* _Player[])
{
	PlayerInitialize(_Player);
	//TargetInitialize(Object* _pObj);
}


//=> Stage ������׿����� �ڵ带 �ۼ���.
void StageProgress(Object* _Player[])
{
	PlayerProgress(_Player);
	//TargetProgress(Object * _pObj);


	//** �浹 Ȯ��.
	//void Collision(Object * _Temp, Object * _Dest);

	if (GetAsyncKeyState(VK_SPACE))
	{
		PlayerInitialize(_Player);
	}

	if (GetAsyncKeyState(VK_ESCAPE))
		SceneState = SCENEIDS_EXIT;
}

//=> Stage ��³��뿡���� �ڵ带 �ۼ���.
void StageRender(Object* _Player[])
{
	//** Target �� �켱����ϰ�...
	//TargetRender(Object * _pObj);

	//** Player �� ���߿� ����Ͽ� Target�� ��¹��� �������. (Player�� Target�� ���� ��ġ�� ����Ҷ� �÷��̾ ���̰� �ϱ�����.)
	PlayerRender(_Player);
}

//=> �ʱ�ȭ ������ �ۼ���.
void PlayerInitialize(Object* _Player[])
{
	if (Length == 0)
	{
		_Player[Length]->pTexture = (char*)"��";

		_Player[Length]->Position.x = 59.f;
		_Player[Length]->Position.y = 15.f;

		_Player[Length]->Scale.x = 2.f;
		_Player[Length]->Scale.y = 1.f;

		_Player[Length]->Rotate = 3;
	}
	else
	{
		_Player[Length]->pTexture = (char*)"��";
		_Player[Length]->Rotate = _Player[Length - 1]->Rotate;

		switch (_Player[Length]->Rotate)
		{
		case ROTATEIDS_UP:
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y + 1;
			break;

		case ROTATEIDS_DOWN:
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y - 1;
			break;

		case ROTATEIDS_LEFT:
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x + 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;

		case ROTATEIDS_RIGHT:
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x - 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;
		}

		_Player[Length]->Scale.x = 2.f;
		_Player[Length]->Scale.y = 1.f;
	}

	++Length;
}


//=> ������׿����� �ڵ带 �ۼ���.
void PlayerProgress(Object* _Player[])
{
	//* �Է¹��� Ű�� ���¿� ���� ������ ID ������ ������.
	InputKey(_Player[0]);

	//** ������ ID ������ ������ ������ ������ ������.
	SetDircetion(_Player[0]);

	for (int i = (Length - 1); i > 0; --i)
	{
		if (i != 0)
		{
			_Player[i]->Rotate = _Player[i - 1]->Rotate;

			_Player[i]->Position.x = _Player[i - 1]->Position.x;
			_Player[i]->Position.y = _Player[i - 1]->Position.y;
		}
	}
}


//=> ��³��뿡���� �ڵ带 �ۼ���.
void PlayerRender(Object* _Player[])
{
	for (int i = 0; i < Length; ++i)
	{
		SetCursorPosition(
			_Player[i]->Position.x,
			_Player[i]->Position.y,
			_Player[i]->pTexture);
	}

	for (int y = 0; y < 29; y++)
	{
		if (y == 0 || y == 28)
			SetCursorPosition(0.f, (float)y, (char*)"�������������������������������������������������������������");
		else
		{
			SetCursorPosition(0.f, (float)y, (char*)"��");
			SetCursorPosition(118.f, (float)y, (char*)"��");
		}
	}
}


//=> Target �ʱ�ȭ ������ �ۼ���.
void TargetInitialize(Object* _pObj)
{
	srand(time(NULL));
		
	int iTargetX = rand() % 110 + 1;
	int iTargetY = rand() % 54 + 1;
	
	/*SetCursorPosition(
		_pObj->Position.x = iTargetX,
		_pObj->Position.y = iTargetY,
		_pObj->pTexture = (char*)"��";
	*/
	_pObj->pTexture = (char*)"��";
	
	_pObj->Position.x = iTargetX;
	_pObj->Position.y = iTargetY;
	
	_pObj->Scale.x = 2.f;
	_pObj->Scale.y = 1.f;
} 


//=> Target ������׿����� �ڵ带 �ۼ���.
void TargetProgress(Object* _pObj)
{

}

//=> Target ��³��뿡���� �ڵ带 �ۼ���.
void TargetRender(Object* _pObj)
{
	SetCursorPosition(
		_pObj->Position.x,
		_pObj->Position.y,
		_pObj->pTexture);
}