#include "Headers.h"



SCENEID SceneState = SCENEIDS_LOGO;



void SetScene(Object* _pPlayer);

void SetCursorPosition(float _x, float _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDirection(Object* _pObj);

//** Logo
void LogoInitialize();
void LogoProgress();
void LogoRender();

//** Menu
void MenuInitialize();
void MenuProgress();
void MenuRender();

//** Stage
void StageInitialize(Object* _pPlayer);
void StageProgress(Object* _pPlayer);
void StageRender(Object* _pPlayer);

//** Player
void PlayerInitialize(Object* _pObj);
void PlayerProgress(Object* _pObj);
void PlayerRender(Object* _pObj);



int main(void)
{
	Object Player;
		
	LogoInitialize();
	MenuInitialize();
	StageInitialize(&Player);

	DWORD dwTime = GetTickCount();
	
	while (true)
	{
		if (dwTime + 80 < GetTickCount())
		{
			dwTime = GetTickCount();

			//** 화면을 모두 지움
			system("cls");
						
			SetScene(&Player);
		}
	}
	   	  
	return 0;
}

// 
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


//** _x, _y 좌표에 _pTexture 을 출력함.
void SetCursorPosition(float _x, float _y, char* _pTexture)
{
	COORD Position = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	printf_s("%s\n", _pTexture);
}

//=> 입력받은 화살표키의 ID값을 설정함.   (enum ROTATEIDS 원형 참고)
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
	//** 설정된 ID 값으로 실제로 움직일 방향을 설정함.
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

// 초기화 내용관련 코드
void PlayerInitialize(Object* _pObj)
{
	_pObj->pTexture = (char*)"■";

	_pObj->Position.x = 59.f;
	_pObj->Position.y = 15.f;

	_pObj->Scale.x = 2.f;
	_pObj->Scale.y = 1.f;

	_pObj->Rotate = 3;

}

// 실행중 변경되는 사항에 대한 코드
void PlayerProgress(Object* _pObj)
{
	//* 입력받은 키의 형태에 따라 방향을 ID 값으로 설정.
	InputKey(_pObj);
	
	//** 설정된 ID 값으로 실제로 움직일 방향을 정함.
	SetDirection(_pObj);
}

// 출력내용에 대한 코드
void PlayerRender(Object* _pObj)
{
	//** 그리고 마지막으로 해당 좌표에 출력함.
	SetCursorPosition(
		_pObj->Position.x,
		_pObj->Position.y,
		_pObj->pTexture);

	for (int y = 0; y < (30 - 1); y++)
	{
		if (y == 0 || y == 28)
			SetCursorPosition(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		else
		{
			SetCursorPosition(0, y, (char*)"■");
			SetCursorPosition(118, y, (char*)"■");
		}
	}
	/*
	for (int y = 0; y < (30 - 1); y++)
	{
		for (int x = 0; x < (120 - 1); x+=2)
		{
			if (y == 0 || y == 28)
				SetCursorPosition(x, y, (char*)"■");
			else
			{
				SetCursorPosition(0, y, (char*)"■");
				SetCursorPosition(118, y, (char*)"■");
			}
		}
	}
	*/
}

// cpu 데이터 처리 병목현상 검색

// Logo 초기화
void LogoInitialize()
{

}

// 로고 실행중 변경사항
void LogoProgress()
{
	if (GetAsyncKeyState('1'))
	{
		SceneState = SCENEIDS_MENU;
	}
}

void LogoRender()
{
	SetCursorPosition(57, 15, (char*)"Logo");
}


void MenuInitialize()
{

}

void MenuProgress()
{
	if (GetAsyncKeyState('2'))
	{
		SceneState = SCENEIDS_STAGE;
	}
}

void MenuRender()
{
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

