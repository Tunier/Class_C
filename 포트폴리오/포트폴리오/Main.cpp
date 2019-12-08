#include "Headers.h"

SCENEID SceneState = SCENEIDS_LOGO;

#define MAX_SIZE_X 60
#define MAX_SIZE_Y 30

void SetScene(Object* _Player, Object* _Board);

void gotoxy(int x, int y);
void SetCursorPosition(int _x, int _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDircetion(Object* _pObj);

void LogoInitialize();
void LogoProgress();
void LogoRender();

void MenuInitialize();
void MenuProgress();
void MenuRender();

void StageInitialize(Object* _Player, Object* _Board);
void StageProgress(Object* _Player);
void StageRender(Object* _Player, Object* _Board);

void PlayerInitialize(Object* _Player);
void PlayerProgress(Object* _Player);
void PlayerRender(Object* _Player);

void BoardInitialize(Object* _Board);
void BoardProgress(Object* _Board);
void BoardRender(Object* _Board);


int main(void)
{
	Object* Player;
	Object* Board;

	Player = (Object*)malloc(sizeof(Object));
	Board = (Object*)malloc(sizeof(Object));

	LogoInitialize();
	MenuInitialize();
	StageInitialize(Player, Board);

	DWORD dwTime = GetTickCount64();

	while (true)
	{
		if (dwTime + 500 < GetTickCount64())
		{
			dwTime = GetTickCount64();

			system("cls");

			SetScene(Player, Board);
		}
	}

	
	return 0;
}

void SetScene(Object* _Player, Object* _Board)
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
		StageProgress(_Player);
		//StageRender(_Player, _Board);
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


void SetCursorPosition(int _x, int _y, char* _pTexture)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	printf_s("%s\n", _pTexture);
}

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

void SetDircetion(Object* _pObj)
{
	switch (_pObj->Rotate)
	{
	case ROTATEIDS_UP:
		if (_pObj->Position.y != 5)
			_pObj->Position.y -= 10;
		_pObj->Rotate = ROTATEIDS_NEUTRALITY;
		break;

	case ROTATEIDS_DOWN:
		if (_pObj->Position.y != 25)
			_pObj->Position.y += 10;
		_pObj->Rotate = ROTATEIDS_NEUTRALITY;
		break;

	case ROTATEIDS_LEFT:
		if (_pObj->Position.x != 10)
			_pObj->Position.x -= 20;
		_pObj->Rotate = ROTATEIDS_NEUTRALITY;
		break;

	case ROTATEIDS_RIGHT:
		if (_pObj->Position.x != 50)
			_pObj->Position.x += 20;
		_pObj->Rotate = ROTATEIDS_NEUTRALITY;
		break;
	case ROTATEIDS_NEUTRALITY:
		break;
	}
}

void LogoInitialize()
{

}

void LogoProgress()
{
	if (GetAsyncKeyState('1'))
		SceneState = SCENEIDS_MENU;
}

void LogoRender()
{
	SetCursorPosition(53, 13, (char*)"Logo");
	SetCursorPosition(49, 15, (char*)"Need 2 Players");
}

void MenuInitialize()
{

}

void MenuProgress()
{
	if (GetAsyncKeyState('2'))
		SceneState = SCENEIDS_STAGE;
}

void MenuRender()
{
	SetCursorPosition(57, 15, (char*)"Menu");
}

void StageInitialize(Object* _Player, Object* _Board)
{
	PlayerInitialize(_Player);
	BoardInitialize(_Board);
}

void StageProgress(Object* _Player)
{
	PlayerProgress(_Player);
		
	if (GetAsyncKeyState(VK_ESCAPE))
		SceneState = SCENEIDS_EXIT;
}

void StageRender(Object* _Player, Object* _Board)
{
	PlayerRender(_Player);
	
	BoardRender(_Board);
}

void PlayerInitialize(Object* _Player)
{
	_Player->pTexture = (char*)"__";

	_Player->Position.x = (MAX_SIZE_X / 2);
	_Player->Position.y = (MAX_SIZE_Y / 2);

	_Player->Scale.x = 2;
	_Player->Scale.y = 1;

	_Player->Rotate = 0;
	
	_Player->Turn = TRUN_PLAYER1;
}

void PlayerProgress(Object* _Player)
{
	InputKey(_Player);

	SetDircetion(_Player);
}

void PlayerRender(Object* _Player)
{
	SetCursorPosition(
		_Player->Position.x,
		_Player->Position.y,
		_Player->pTexture);

	if (_Player->Turn == TRUN_PLAYER1)
	{
		if (GetAsyncKeyState(VK_RETURN))
			SetCursorPosition(_Player->Position.x - 3, _Player->Position.y - 1, (char*)"¡á");
	}
}


void BoardInitialize(Object* _Board)
{

}

void BoardProgress(Object* _Board)
{	   
	   
}	   
	   
void BoardRender(Object* _Board)
{
	for (int y = 0; y < MAX_SIZE_Y + 1; y++)
	{
		if (y == 0 || y == 10|| y == 20 || y == MAX_SIZE_Y )
			SetCursorPosition(0, y, (char*)"¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
		else
		{
			SetCursorPosition(0, y, (char*)"¡á");
			SetCursorPosition(20, y, (char*)"¡á");
			SetCursorPosition(40, y, (char*)"¡á");
			SetCursorPosition((MAX_SIZE_X ), y, (char*)"¡á");
		}
	}
}
