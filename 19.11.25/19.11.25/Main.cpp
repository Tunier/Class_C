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

//=> 씬을 설정함.
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


//=> _x, _y 좌표에 _pTexture 를 출력함.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	printf_s("%s\n", _pTexture);
}


//=> 입력받은 화살표키의 ID값을 설정함.   (enum ROTATEIDS 원형 참고)
void InputKey(Object* _pObj)
{
	if (GetAsyncKeyState(VK_UP)) //** 위쪽방향 화살표키를 눌럿을때 
		if (_pObj->Rotate != ROTATEIDS_DOWN)	//** 현재 방향이 아래쪽 방향이 아닐때에만
			_pObj->Rotate = ROTATEIDS_UP;	//** 위쪽 방향키을 입력받을수 있다.

	if (GetAsyncKeyState(VK_DOWN)) //** 아래쪽방향 화살표키를 눌럿을때 
		if (_pObj->Rotate != ROTATEIDS_UP)	//** 현재 방향이 위쪽 방향이 아닐때에만
			_pObj->Rotate = ROTATEIDS_DOWN;	//** 아래쪽 방향키을 입력받을수 있다.

	if (GetAsyncKeyState(VK_LEFT))	//** 왼쪽방향 화살표키를 눌럿을때 
		if (_pObj->Rotate != ROTATEIDS_RIGHT)	//** 현재 방향이 오른쪽 방향이 아닐때에만
			_pObj->Rotate = ROTATEIDS_LEFT;	//** 왼쪽 방향키을 입력받을수 있다.

	if (GetAsyncKeyState(VK_RIGHT))	//** 오른쪽방향 화살표키를 눌럿을때 
		if (_pObj->Rotate != ROTATEIDS_LEFT)	//** 현재 방향이 왼쪽 방향이 아닐때에만
			_pObj->Rotate = ROTATEIDS_RIGHT;	//** 오른쪽 방향키을 입력받을수 있다.
}


//=> 방향을 변경할 객체의 정보를 받아 실제로 움직일 방향을 설정함.
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

//=> 두개의 오브젝트가 충돌했는지 확인.
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


//=> Logo 초기화 내용을 작성함.
void LogoInitialize()
{

}

//=> Logo 변경사항에대한 코드를 작성함.
void LogoProgress()
{
	if (GetAsyncKeyState('1'))
		SceneState = SCENEIDS_MENU;
}

//=> Logo 출력내용에대한 코드를 작성함.
void LogoRender()
{
	SetCursorPosition(57, 15, (char*)"Logo");
}

//=> Menu 초기화 내용을 작성함.
void MenuInitialize()
{

}

//=> Menu 변경사항에대한 코드를 작성함.
void MenuProgress()
{
	if (GetAsyncKeyState('2'))
		SceneState = SCENEIDS_STAGE;
}

//=> Menu 출력내용에대한 코드를 작성함.
void MenuRender()
{
	SetCursorPosition(57, 15, (char*)"Menu");
}

//=> Stage 초기화 내용을 작성함.
void StageInitialize(Object* _Player[], Object* _Target)
{
	PlayerInitialize(_Player);
	TargetInitialize(_Target);
}


//=> Stage 변경사항에대한 코드를 작성함.
void StageProgress(Object* _Player[], Object* _Target)
{
	PlayerProgress(_Player);
	TargetProgress(_Target);

	//** 충돌 확인.
	Collision(_Player, _Target);

	if (GetAsyncKeyState(VK_SPACE))
		PlayerInitialize(_Player);

	if (GetAsyncKeyState(VK_ESCAPE))
		SceneState = SCENEIDS_EXIT;
}

//=> Stage 출력내용에대한 코드를 작성함.
void StageRender(Object* _Player[], Object* _Target)
{
	//** Target 을 우선출력하고...
	TargetRender(_Target);

	//** Player 를 나중에 출력하여 Target의 출력물을 덮어버림. (Player와 Target을 같은 위치에 출력할때 플레이어가 보이게 하기위함.)
	PlayerRender(_Player);
}

//=> 초기화 내용을 작성함.
void PlayerInitialize(Object* _Player[])
{
	//** 길이가 0 인 상태라면...
	if (Length == HEAD)
	{
		//** Head 부분을 아래 내용으로 초기화 함.
		_Player[HEAD]->pTexture = (char*)"■";

		_Player[HEAD]->Position.x = (MAX_SIZE_X / 2);
		_Player[HEAD]->Position.y = (MAX_SIZE_Y / 2);

		_Player[HEAD]->Scale.x = 2.f;
		_Player[HEAD]->Scale.y = 1.f;

		_Player[HEAD]->Rotate = 0;
	}
	else
	{
		//** Head 부분을 제외한 나머지 부분을 꼬리로 보고 꼬리부분을 초기화 함.
		_Player[Length]->pTexture = (char*)"□";

		//** 현재 꼬리위치의 앞에있는 꼬리 방향을 받아 초기화 함.
		_Player[Length]->Rotate = _Player[Length - 1]->Rotate;

		//** 앞에있는 꼬리를 따라 
		switch (_Player[Length]->Rotate)
		{
		case ROTATEIDS_UP:
			//** UP 방향이면 아래쪽으로..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y + 1;
			break;

		case ROTATEIDS_DOWN:
			//** DOWN 방향이면 위쪽으로..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y - 1;
			break;

		case ROTATEIDS_LEFT:
			//** LEFT 방향이면 오른쪽으로..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x + 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;

		case ROTATEIDS_RIGHT:
			//** RIGHT 방향이면 왼쪽으로..
			_Player[Length]->Position.x = _Player[Length - 1]->Position.x - 2;
			_Player[Length]->Position.y = _Player[Length - 1]->Position.y;
			break;
		}
		//** 초기화 함.


		//** 크기값 설정.
		_Player[Length]->Scale.x = 2.f;
		_Player[Length]->Scale.y = 1.f;
	}

	//** 꼬리를 증가시켜줌.
	++Length;
}


//=> 변경사항에대한 코드를 작성함.
void PlayerProgress(Object* _Player[])
{
	//* 입력받은 키의 형태에 따라 방향을 ID 값으로 설정함.
	InputKey(_Player[0]);

	//** 앞에있는 꼬리를 뒤에있는 꼬리가 계속 따라다닐수 있도록 설정.
	for (int i = (Length - 1); i > HEAD; --i)
	{
		//** 앞에있는 꼬리의 정보를 뒤에있는 꼬리에게 전달하는데 전달 방식을 거꾸로 설정함.
		//** (앞으로부터 전달하면 기존에 있던 데이터가 사라지기 때문..)

		//** 거꾸로 오다보면 Index 가 0 일때에는 Head 부분이기 때문에 제외시켜줌. 
		if (i != HEAD)
		{
			_Player[i]->Rotate = _Player[i - 1]->Rotate;

			_Player[i]->Position.x = _Player[i - 1]->Position.x;
			_Player[i]->Position.y = _Player[i - 1]->Position.y;
		}
	}

	//** 설정된 ID 값으로 실제로 움직일 방향을 설정함.
	SetDircetion(_Player[0]);
}


//=> 출력내용에대한 코드를 작성함.
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
			SetCursorPosition(0.f, (float)y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		else
		{
			SetCursorPosition(0.f, (float)y, (char*)"■");
			SetCursorPosition((MAX_SIZE_X - 2), (float)y, (char*)"■");
		}
	}
	gotoxy(0, 0);
	printf_s("%s %d", (char*)"Score : ", Score);		
}


//=> Target 초기화 내용을 작성함.
void TargetInitialize(Object* _pTarget)
{
	_pTarget->Position.x = rand() % (MAX_SIZE_X - 5) + 3;
	_pTarget->Position.y = rand() % (MAX_SIZE_Y - 3) + 1;

	_pTarget->pTexture = (char*)"☆";

	_pTarget->Scale.x = 2;
	_pTarget->Scale.y = 1;

	_pTarget->Rotate = 0;
}

//=> Target 변경사항에대한 코드를 작성함.
void TargetProgress(Object* _pTarget)
{

}

//=> Target 출력내용에대한 코드를 작성함.
void TargetRender(Object* _pTarget)
{
	SetCursorPosition(
		_pTarget->Position.x,
		_pTarget->Position.y,
		_pTarget->pTexture);
}