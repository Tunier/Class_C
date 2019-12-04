#include "Headers.h"


#define HEAD 0
#define MAX_SIZE_X 120
#define MAX_SIZE_Y 30




SCENEID SceneState = SCENEIDS_LOGO;

int Length = 0;
int Score = 0;

//** Manager ************************************************

void SetScene(Object* _pPlayer[], Object* _Target);

void SetCursorPosition(float _x, float _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDircetion(Object* _pObj);

void Collision(Object* _Player[], Object* _Target);
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
void StageInitialize(Object* _pPlayer[], Object* _Target);
void StageProgress(Object* _pPlayer[], Object* _Target);
void StageRender(Object* _pPlayer[], Object* _Target);


//** Player
void PlayerInitialize(Object* _pPlayer[]);
void PlayerProgress(Object* _pPlayer[]);
void PlayerRender(Object* _pPlayer[]);


//** Target
void TargetInitialize(Object* _pTarget);
void TargetProgress(Object* _pTarget);
void TargetRender(Object* _pTarget);



int main(void)
{
	Object* Player[128];
	Object* Target;

	for (int i = 0; i < 128; ++i)
		Player[i] = (Object*)malloc(sizeof(Object));

	Target = (Object*)malloc(sizeof(Object));

	LogoInitialize();
	MenuInitialize();
	StageInitialize(Player, Target);

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();

			system("cls");

			SetScene(Player, Target);
		}
	}

	return 0;
}

//=> ���� ������.
void SetScene(Object* _pPlayer[], Object* _Target)
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
		StageProgress(_pPlayer, _Target);
		StageRender(_pPlayer, _Target);
		break;

	case SCENEIDS_EXIT:
		exit(NULL);
		break;
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
	if (GetAsyncKeyState(VK_UP)) //** ���ʹ��� ȭ��ǥŰ�� �������� 
		if (_pObj->Rotate != ROTATEIDS_DOWN)	//** ���� ������ �Ʒ��� ������ �ƴҶ�����
			_pObj->Rotate = ROTATEIDS_UP;	//** ���� ����Ű�� �Է¹����� �ִ�.

	if (GetAsyncKeyState(VK_DOWN)) //** �Ʒ��ʹ��� ȭ��ǥŰ�� �������� 
		if (_pObj->Rotate != ROTATEIDS_UP)	//** ���� ������ ���� ������ �ƴҶ�����
			_pObj->Rotate = ROTATEIDS_DOWN;	//** �Ʒ��� ����Ű�� �Է¹����� �ִ�.

	if (GetAsyncKeyState(VK_LEFT))	//** ���ʹ��� ȭ��ǥŰ�� �������� 
		if (_pObj->Rotate != ROTATEIDS_RIGHT)	//** ���� ������ ������ ������ �ƴҶ�����
			_pObj->Rotate = ROTATEIDS_LEFT;	//** ���� ����Ű�� �Է¹����� �ִ�.

	if (GetAsyncKeyState(VK_RIGHT))	//** �����ʹ��� ȭ��ǥŰ�� �������� 
		if (_pObj->Rotate != ROTATEIDS_LEFT)	//** ���� ������ ���� ������ �ƴҶ�����
			_pObj->Rotate = ROTATEIDS_RIGHT;	//** ������ ����Ű�� �Է¹����� �ִ�.
}


//=> ������ ������ ��ü�� ������ �޾� ������ ������ ������ ������.
void SetDircetion(Object* _pObj)
{
	switch (_pObj->Rotate)
	{
	case ROTATEIDS_UP:
		//if (_pObj->Position.y != 1)
			_pObj->Position.y -= 1;
		break;

	case ROTATEIDS_DOWN:
		//if (_pObj->Position.y != (MAX_SIZE_Y -2))
			_pObj->Position.y += 1;
		break;

	case ROTATEIDS_LEFT:
		//if (_pObj->Position.x > 2)
			_pObj->Position.x -= 2;
		break;

	case ROTATEIDS_RIGHT:
		//if (_pObj->Position.x < (MAX_SIZE_X - 3))
			_pObj->Position.x += 2;
		break;
	}
}

//=> �ΰ��� ������Ʈ�� �浹�ߴ��� Ȯ��.
void Collision(Object* _Player[], Object* _Target)
{
	if (_Player[HEAD]->Position.x < _Target->Position.x + _Target->Scale.x &&
		_Target->Position.x < _Player[HEAD]->Position.x + _Player[HEAD]->Scale.x &&
		_Player[HEAD]->Position.y == _Target->Position.y)
	{
		PlayerInitialize(_Player);
		TargetInitialize(_Target);
		Score += 1;
	}

	if (_Player[HEAD]->Position.x <= 1 || _Player[HEAD]->Position.x + 1 >= MAX_SIZE_X ||
		_Player[HEAD]->Position.y <= 1 || _Player[HEAD]->Position.y + 1 >= MAX_SIZE_Y)
	{
		SetCursorPosition(57, 15, (char*)"Game Over");
		
		system("pause");

		SceneState = SCENEIDS_EXIT;
	}

	for(int i = 1; i < Length; ++i)
		if (_Player[HEAD]->Position.x == _Player[i]->Position.x &&
			_Player[HEAD]->Position.y == _Player[i]->Position.y)
		{
			SetCursorPosition(57, 15, (char*)"Game Over");

			system("pause");

			SceneState = SCENEIDS_EXIT;
		}
}


//=> Logo �ʱ�ȭ ������ �ۼ���.
void LogoInitialize()
{

}

//=> Logo ������׿����� �ڵ带 �ۼ���.
void LogoProgress()
{
	if (GetAsyncKeyState('1'))
		SceneState = SCENEIDS_MENU;
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
		SceneState = SCENEIDS_STAGE;
}

//=> Menu ��³��뿡���� �ڵ带 �ۼ���.
void MenuRender()
{
	SetCursorPosition(57, 15, (char*)"Menu");
}

//=> Stage �ʱ�ȭ ������ �ۼ���.
void StageInitialize(Object* _Player[], Object* _Target)
{
	PlayerInitialize(_Player);
	TargetInitialize(_Target);
}


//=> Stage ������׿����� �ڵ带 �ۼ���.
void StageProgress(Object* _Player[], Object* _Target)
{
	PlayerProgress(_Player);
	TargetProgress(_Target);

	//** �浹 Ȯ��.
	Collision(_Player, _Target);

	if (GetAsyncKeyState(VK_SPACE))
		PlayerInitialize(_Player);

	if (GetAsyncKeyState(VK_ESCAPE))
		SceneState = SCENEIDS_EXIT;
}

//=> Stage ��³��뿡���� �ڵ带 �ۼ���.
void StageRender(Object* _Player[], Object* _Target)
{
	//** Target �� �켱����ϰ�...
	TargetRender(_Target);

	//** Player �� ���߿� ����Ͽ� Target�� ��¹��� �������. (Player�� Target�� ���� ��ġ�� ����Ҷ� �÷��̾ ���̰� �ϱ�����.)
	PlayerRender(_Player);
}

//=> �ʱ�ȭ ������ �ۼ���.
void PlayerInitialize(Object* _Player[])
{
	//** ���̰� 0 �� ���¶��...
	if (Length == HEAD)
	{
		//** Head �κ��� �Ʒ� �������� �ʱ�ȭ ��.
		_Player[HEAD]->pTexture = (char*)"��";

		_Player[HEAD]->Position.x = (MAX_SIZE_X / 2);
		_Player[HEAD]->Position.y = (MAX_SIZE_Y / 2);

		_Player[HEAD]->Scale.x = 2.f;
		_Player[HEAD]->Scale.y = 1.f;

		_Player[HEAD]->Rotate = 0;
	}
	else
	{
		//** Head �κ��� ������ ������ �κ��� ������ ���� �����κ��� �ʱ�ȭ ��.
		_Player[Length]->pTexture = (char*)"��";

		//** ���� ������ġ�� �տ��ִ� ���� ������ �޾� �ʱ�ȭ ��.
		_Player[Length]->Rotate = _Player[Length - 1]->Rotate;

		//** �տ��ִ� ������ ���� 
		switch (_Player[Length]->Rotate)
		{
		case ROTATEIDS_UP:
			//** UP �����̸� �Ʒ�������..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y + 1;
			break;

		case ROTATEIDS_DOWN:
			//** DOWN �����̸� ��������..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y - 1;
			break;

		case ROTATEIDS_LEFT:
			//** LEFT �����̸� ����������..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x + 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;

		case ROTATEIDS_RIGHT:
			//** RIGHT �����̸� ��������..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x - 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;
		}
		//** �ʱ�ȭ ��.


		//** ũ�Ⱚ ����.
		_Player[Length]->Scale.x = 2.f;
		_Player[Length]->Scale.y = 1.f;
	}

	//** ������ ����������.
	++Length;
}


//=> ������׿����� �ڵ带 �ۼ���.
void PlayerProgress(Object* _Player[])
{
	//* �Է¹��� Ű�� ���¿� ���� ������ ID ������ ������.
	InputKey(_Player[0]);

	//** �տ��ִ� ������ �ڿ��ִ� ������ ��� ����ٴҼ� �ֵ��� ����.
	for (int i = (Length - 1); i > HEAD; --i)
	{
		//** �տ��ִ� ������ ������ �ڿ��ִ� �������� �����ϴµ� ���� ����� �Ųٷ� ������.
		//** (�����κ��� �����ϸ� ������ �ִ� �����Ͱ� ������� ����..)

		//** �Ųٷ� ���ٺ��� Index �� 0 �϶����� Head �κ��̱� ������ ���ܽ�����. 
		if (i != HEAD)
		{
			_Player[i]->Rotate = _Player[i - 1]->Rotate;

			_Player[i]->Position.x = _Player[i - 1]->Position.x;
			_Player[i]->Position.y = _Player[i - 1]->Position.y;
		}
	}

	//** ������ ID ������ ������ ������ ������ ������.
	SetDircetion(_Player[0]);
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

	for (int y = 1; y < MAX_SIZE_Y - 1; y++)
	{
		if (y == 1 || y == MAX_SIZE_Y - 2)
			SetCursorPosition(0.f, (float)y, (char*)"�������������������������������������������������������������");
		else
		{
			SetCursorPosition(0.f, (float)y, (char*)"��");
			SetCursorPosition((MAX_SIZE_X - 2), (float)y, (char*)"��");
		}
	}
	gotoxy(0, 0);
	printf_s("%s %d", (char*)"Score : ", Score);		
}


//=> Target �ʱ�ȭ ������ �ۼ���.
void TargetInitialize(Object* _pTarget)
{
	_pTarget->Position.x = rand() % (MAX_SIZE_X - 5) + 3;
	_pTarget->Position.y = rand() % (MAX_SIZE_Y - 3) + 1;

	_pTarget->pTexture = (char*)"��";

	_pTarget->Scale.x = 2;
	_pTarget->Scale.y = 1;

	_pTarget->Rotate = 0;
}

//=> Target ������׿����� �ڵ带 �ۼ���.
void TargetProgress(Object* _pTarget)
{

}

//=> Target ��³��뿡���� �ڵ带 �ۼ���.
void TargetRender(Object* _pTarget)
{
	SetCursorPosition(
		_pTarget->Position.x,
		_pTarget->Position.y,
		_pTarget->pTexture);
}