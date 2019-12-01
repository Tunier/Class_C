#include "Headers.h"


// 전역변수, 씬상태 로고로 초기화
SCENEID SceneState = SCENEIDS_LOGO;



// 씬제어
void SetScene(Object* _pPlayer);

// 플레이어 위치 출력
void SetCursorPosition(float _x, float _y, char* _pTexture);

// 키입력 반응
void InputKey(Object* _pObj);

// 플레이어 이동 방향 결정
void SetDirection(Object* _pObj);

//** Logo 관련 전방선언
void LogoInitialize();
void LogoProgress();
void LogoRender();

//** Menu 관련 전방선언
void MenuInitialize();
void MenuProgress();
void MenuRender();

//** Stage 관련 전방선언
void StageInitialize(Object* _pPlayer);
void StageProgress(Object* _pPlayer);
void StageRender(Object* _pPlayer);

//** Player 관련 전방선언
void PlayerInitialize(Object* _pObj);
void PlayerProgress(Object* _pObj);
void PlayerRender(Object* _pObj);



int main(void)
{
	Object Player;
	
	// 로고, 메뉴, 스테이지 초기화
	LogoInitialize();
	MenuInitialize();
	StageInitialize(&Player);

	// time을 타이머로
	DWORD dwTime = GetTickCount();
	
	// 무한반복문
	while (true)
	{
		// dwTime + 80ms < 타이머 인경우 dwTime을 타이머로 변경
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

// Scene 컨트롤.
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
	// x, y 좌표 관련 라이브러리
	COORD Position = { (SHORT)_x,(SHORT)_y };	
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	printf_s("%s\n", _pTexture);
}

// 누른 화살표키의 ID값을 설정
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
	// 위방향키를 누르면 y가 1이 아닐때 y값을 -1만큼 바꿈
	case ROTATEIDS_UP:
		if (_pObj->Position.y != 1)
			_pObj->Position.y -= 1;
		break;

	// 아래방향키를 누르면 y가 27이 아닐때 y값을 +1만큼 바꿈
	case ROTATEIDS_DOWN:
		if (_pObj->Position.y != 27)
			_pObj->Position.y += 1;
		break;

	// 위방향키를 누르면 x > 2 일때 x값을 -1만큼 바꿈
	case ROTATEIDS_LEFT:
		if (_pObj->Position.x > 2)
			_pObj->Position.x -= 1;
		break;

	// 위방향키를 누르면 x < 116 일때 x값을 +1만큼 바꿈
	case ROTATEIDS_RIGHT:
		if (_pObj->Position.x < 116)
			_pObj->Position.x += 1;
		break;
	}
}

// 초기화 내용관련 코드
void PlayerInitialize(Object* _pObj)
{
	// 플레이어 모양
	_pObj->pTexture = (char*)"■";

	// 플레이어 시작위치는 (59, 15)
	_pObj->Position.x = 59.f;
	_pObj->Position.y = 15.f;

	// 크기는 가로 2(1칸) 세로 1(1칸)
	_pObj->Scale.x = 2.f;
	_pObj->Scale.y = 1.f;

	// 첫 방향을 오른쪽으로
	_pObj->Rotate = 3;

}

// 실행중(러닝타임) 변경되는 사항에 대한 코드
void PlayerProgress(Object* _pObj)
{
	//* 입력받은 키의 형태에 따라 방향을 ID 값으로 설정.
	InputKey(_pObj);
	
	//** 설정된 ID 값으로 실제로 움직일 방향을 정함.
	SetDirection(_pObj);
}

// 화면 출력내용에 대한 코드
void PlayerRender(Object* _pObj)
{
	//** 그리고 마지막으로 해당 좌표에 출력함.
	SetCursorPosition(
		_pObj->Position.x,
		_pObj->Position.y,
		_pObj->pTexture);
	// int형 y 는 0, y < (30 - 1)일때까지, y는 1씩증가)
	for (int y = 0; y < (30 - 1); y++)
	{
		// 만약 y가 0 또는 28일때
		if (y == 0 || y == 28)
			// (0, y)에 "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" 출력
			SetCursorPosition(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		// y가 0 또는 28이 아닐때는 (0, y), (118, y)에 "■" 출력
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

// Logo 실행중 변경, 실행되는 사항들
void LogoProgress()
{
	// '1'키를 눌렀을경우 씬상태를 메뉴로 변경
	if (GetAsyncKeyState('1'))
	{
		SceneState = SCENEIDS_MENU;
	}
}

void LogoRender()
{
	// (57, 15)에 "Logo" 출력
	SetCursorPosition(57, 15, (char*)"Logo");
}


void MenuInitialize()
{

}

void MenuProgress()
{
	// '2'키를 눌렀을경우 씬상태를 스테이지로 변경
	if (GetAsyncKeyState('2'))
	{
		SceneState = SCENEIDS_STAGE;
	}
}

void MenuRender()
{
	// (57, 15)에 "Menu" 출력
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

