#include "Headers.h"

SCENEID SceneState = SCENEIDS_LOGO;

#define MAX_SIZE_X 60
#define MAX_SIZE_Y 30

int BLOCKAA = NEUTRALITY;
int BLOCKAB = NEUTRALITY;
int BLOCKAC = NEUTRALITY;
int BLOCKBA = NEUTRALITY;
int BLOCKBB = NEUTRALITY;
int BLOCKBC = NEUTRALITY;
int BLOCKCA = NEUTRALITY;
int BLOCKCB = NEUTRALITY;
int BLOCKCC = NEUTRALITY;

int Turn = TRUN_PLAYER1;

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

void MarkPlayer1(Vector* _MarkLocation);
void MarkPlayer2(Vector* _MarkLocation);

int main(void)
{
	Object* Player;
	Object* Board;

	Vector* MarkLocation[9];

	Player = (Object*)malloc(sizeof(Object));
	Board = (Object*)malloc(sizeof(Object));

	for (int i = 0; i < 9; ++i)
		MarkLocation[9] = (Vector*)malloc(sizeof(Vector));

	LogoInitialize();
	MenuInitialize();
	StageInitialize(Player, Board);

	DWORD dwTime = GetTickCount();

	while (true)
	{
		if (dwTime + 150 < GetTickCount())
		{
			dwTime = GetTickCount();

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
		StageRender(_Player, _Board);
		break;

	case SCENEIDS_EXIT:
		exit(NULL);
		break;
	}
}

void gotoxy(int _x, int _y)
{
	COORD pos = { _x, _y };

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
	SetCursorPosition(57, 17, (char*)"Logo");
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
	SetCursorPosition(57, 17, (char*)"Menu");
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

	_Player->Position.x = 30;
	_Player->Position.y = 15;

	_Player->Scale.x = 2;
	_Player->Scale.y = 1;

	_Player->Rotate = ROTATEIDS_NEUTRALITY;
}

void PlayerProgress(Object* _Player)
{
	InputKey(_Player);

	SetDircetion(_Player);

	if (SceneState == SCENEIDS_STAGE)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			if (Turn == TRUN_PLAYER1)
			{
				if (_Player->Position.x == 10)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKAA = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 30;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKAB = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 30;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKAC = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 30;
					}
				}
				else if (_Player->Position.x == 30)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKBA = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 50;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKBB = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 50;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKBC = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.x = 50;
					}
				}
				else if (_Player->Position.x == 50)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKCA = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.y = 15;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKCB = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.y = 25;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKCC = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
						//_Player->Position.y = 15;
					}
				}
			}
			else if (Turn == TRUN_PLAYER2)
			{
				if (_Player->Position.x == 10)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKAA = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 30;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKAB = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 30;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKAC = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 30;
					}
				}
				else if (_Player->Position.x == 30)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKBA = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 50;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKBB = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 50;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKBC = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.x = 50;
					}
				}
				else if (_Player->Position.x == 50)
				{
					if (_Player->Position.y == 5)
					{
						BLOCKCA = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.y = 15;
					}
					else if (_Player->Position.y == 15)
					{
						BLOCKCB = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.y = 25;
					}
					else if (_Player->Position.y == 25)
					{
						BLOCKCC = PLAYER2_MARK;
						Turn = TRUN_PLAYER1;
						//_Player->Position.y = 15;
					}
				}
			}
		}
	}
}




void PlayerRender(Object* _Player)
{
	SetCursorPosition(
		_Player->Position.x,
		_Player->Position.y,
		_Player->pTexture);

	if (BLOCKAA == PLAYER1_MARK)
	{
		
	}
	else if (BLOCKAA == PLAYER2_MARK)
	{
		
	}

	if (BLOCKAB == PLAYER1_MARK)
	{
		
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
		if (y == 0 || y == 10 || y == 20 || y == MAX_SIZE_Y)
			SetCursorPosition(0, y, (char*)"¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
		else
		{
			SetCursorPosition(0, y, (char*)"¡á");
			SetCursorPosition(20, y, (char*)"¡á");
			SetCursorPosition(40, y, (char*)"¡á");
			SetCursorPosition((MAX_SIZE_X), y, (char*)"¡á");
		}
	}
}

void MarkPlayer1(Vector* _MarkLocation[])
{
	for (int i = 0; i < 9; ++i)
	{
		_MarkLocation[i] =
	}

		
	
	gotoxy(8 + 20 * XLocation, 3 * YLocation);
	printf_s("%s", "¡á¡á¡á");

	for (int y = 4; y < 6 + 1; ++y)
	{
		for (int x = 6; x < 14 + 1; ++x)
		{
			if (x == 6 || x == 14)
			{
				SetCursorPosition(x, y, (char*)"¡á");
			}
		}
	}

	gotoxy(8, 7);
	printf_s("%s", "¡á¡á¡á");
}

void MarkPlayer2(Vector* _MarkLocation[])
{
	gotoxy(6, 3);
	printf_s("%s", "¡á      ¡á");

	gotoxy(8, 4);
	printf_s("%s", "¡á  ¡á");

	gotoxy(10, 5);
	printf_s("%s", "¡á");

	gotoxy(8, 6);
	printf_s("%s", "¡á  ¡á");

	gotoxy(6, 7);
	printf_s("%s", "¡á      ¡á");
}