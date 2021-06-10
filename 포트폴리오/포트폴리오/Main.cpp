#include "Headers.h"

SCENEID SceneState = SCENEIDS_LOGO;

#define MAX_SIZE_X 60
#define MAX_SIZE_Y 30

int Turn = TRUN_PLAYER1;
int Match = NOT_YET;

int AIBlock = 4;

int MenuState = 0;

void SetScene(Object* _Player, Object* _Board);

void gotoxy(int x, int y);
void SetCursorPosition(int _x, int _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDircetion(Object* _pObj);
void BufferClear();

void LogoInitialize();
void LogoProgress();
void LogoRender();

void MenuInitialize();
void MenuProgress(Object* _Player, Object* _Board);
void MenuRender();

void StageInitialize(Object* _Player, Object* _Board);
void StageProgress(Object* _Player, Object* _Board);
void StageRender(Object* _Player, Object* _Board);

void PlayerInitialize(Object* _Player);
void PlayerProgress(Object* _Player);
void PlayerRender(Object* _Player);

void BoardInitialize(Object* _Board);
void BoardProgress(Object* _Board);
void BoardRender(Object* _Board);

void AIInitialize();
void AIProgress();
void AIRender();

void MarkPlayer1(int MarkLocationX, int MarkLocationY);
void MarkPlayer2(int MarkLocationX, int MarkLocationY);

int main(void)
{
	Object* Player;
	Object* Board;

	Player = (Object*)malloc(sizeof(Object));
	Board = (Object*)malloc(sizeof(Object));

	LogoInitialize();
	MenuInitialize();
	StageInitialize(Player, Board);
	AIInitialize();

	DWORD dwTime = GetTickCount();

	system("mode con:cols=114 lines=24");

	while (true)
	{
		if (dwTime + 150 < GetTickCount())
		{
			dwTime = GetTickCount();

			system("cls");

			SetScene(Player, Board);

			Sleep(30);
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
		if (_kbhit)
		{
			MenuProgress(_Player, _Board);
			MenuRender();
		}
		break;

	case SCENEIDS_STAGE_PVP:
		if (_kbhit)
		{
			StageProgress(_Player, _Board);
			StageRender(_Player, _Board);
		}
		break;

	case SCENEIDS_STAGE_PVE:
		if (_kbhit)
		{
			StageProgress(_Player, _Board);
			AIProgress();
			StageRender(_Player, _Board);
		}
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

void BufferClear()
{
	for (int i = 0; i < 64; ++i)
	{
		if (GetAsyncKeyState(VK_UP)) {}
		if (GetAsyncKeyState(VK_DOWN)) {}
		if (GetAsyncKeyState(VK_LEFT)) {}
		if (GetAsyncKeyState(VK_RIGHT)) {}
		if (GetAsyncKeyState(VK_SPACE)) {}
		if (GetAsyncKeyState(VK_RETURN)) {}
		if (GetAsyncKeyState(VK_ESCAPE)) {}
	}
}

void LogoInitialize()
{

}

void LogoProgress()
{
	LogoInitialize();
	MenuInitialize();
	AIInitialize();

	if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN))
	{
		BufferClear();
		SceneState = SCENEIDS_MENU;
		Sleep(500);
	}
}

void LogoRender()
{
	SetCursorPosition(10, 4,  (char*)"         ,----,                         ,----,                           ,----,");
	SetCursorPosition(10, 5,  (char*)"       ,/   .`|                       ,/   .`|                         ,/   .`|");
	SetCursorPosition(10, 6,  (char*)"     ,`   .'  :                     ,`   .'  :                ,-.    ,`   .'  :");
	SetCursorPosition(10, 7,  (char*)"   ;    ;     / ,--,              ;    ;     /            ,--/ /|  ;    ;     /");
	SetCursorPosition(10, 8,  (char*)" .'___,/    ,',--.'|            .'___,/    ,'           ,--. :/ |.'___,/    ,'  ,---.");
	SetCursorPosition(10, 9,  (char*)" |    :     | |  |,             |    :     |            :  : ' / |    :     |  '   ,'＼");
	SetCursorPosition(10, 10, (char*)" ;    |.';  ; `--'_       ,---. ;    |.';  ;  ,--.--.   |  '  /  ;    |.';  ; /   /   |");
	SetCursorPosition(10, 11, (char*)" `----'  |  | ,' ,'|     /     ＼`----'  |  | /       ＼  '  |  :  `----'  |  |.   ; ,. :");
	SetCursorPosition(10, 12, (char*)"     '   :  ; '  | |    /    / '    '   :  ;.--.  .-. | |  |   ＼     '   :  ;'   | |: :");
	SetCursorPosition(10, 13, (char*)"     |   |  ' |  | :   .    ' /     |   |  ' ＼__＼/: . . '  : |. ＼    |   |  ''   | .; :");
	SetCursorPosition(10, 14, (char*)"     '   :  | '  : |__ '   ; :__    '   :  | ,' .--.; | |  | ' ＼ ＼   '   : || : | ");
	SetCursorPosition(10, 15, (char*)"     ;   |.'  |  | '.'|'   | '.'|   ;   |.' /  /  ,.  | '  : |--'    ;   |.'  ＼   ＼  /");
	SetCursorPosition(10, 16, (char*)"     '---'    ;  :    ;|   :    :   '---'  ;  :   .'   ＼;  |,'       '---'     `----'");
	SetCursorPosition(10, 17, (char*)"              |  ,   /  ＼   ＼  /           |  ,     .-./'--'");
	SetCursorPosition(10, 18, (char*)"               ---`-'    `----'             `--`---'");

	SetCursorPosition(46, 20, (char*)"Press EnterKey");
}

void MenuInitialize()
{
	BufferClear();

	MenuState = 0;

	for (int i = 0; i < 4; ++i)
	{
		Menu[i] = (Texture*)malloc(sizeof(Texture));

		Menu[i]->Position.x = 57;
		Menu[i]->Position.y = 15 + i;

		Menu[i]->Scale.x = 0;
		Menu[i]->Scale.y = 1;
	}

	Menu[0]->Position.x = 53;
	Menu[0]->Position.y = 15 + 1;

	Menu[0]->pTexture = (char*)"▶";
	Menu[1]->pTexture = (char*)"PVP";
	Menu[2]->pTexture = (char*)"PVE";
	Menu[3]->pTexture = (char*)"EXIT";
}

void MenuProgress(Object* _Player, Object* _Board)
{
	BufferClear();

	system("mode con:cols=120 lines=34");

	if (GetAsyncKeyState(VK_UP))
	{
		if (MenuState != 0)
		{
			--MenuState;
			--Menu[0]->Position.y;
		}
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (MenuState != 2)
		{
			++MenuState;
			++Menu[0]->Position.y;
		}
	}

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (MenuState)
		{
		case 0:
			SceneState = SCENEIDS_STAGE_PVP;
			StageInitialize(_Player, _Board);
			break;

		case 1:
			SceneState = SCENEIDS_STAGE_PVE;
			StageInitialize(_Player, _Board);
			break;

		case 2:
			SceneState = SCENEIDS_EXIT;
			break;
		}
	}
}

void MenuRender()
{
	for (int i = 0; i < 4; ++i)
	{
		SetCursorPosition(
			Menu[i]->Position.x,
			Menu[i]->Position.y,
			Menu[i]->pTexture);
	}
}

void StageInitialize(Object* _Player, Object* _Board)
{
	PlayerInitialize(_Player);
	BoardInitialize(_Board);
}

void StageProgress(Object* _Player, Object* _Board)
{
	BufferClear();

	PlayerProgress(_Player);
	BoardProgress(_Board);

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

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (Turn == TRUN_PLAYER1)
		{
			if (_Player->Position.x == 10)
			{
				if (_Player->Position.y == 5)
				{
					if (Block[0][0].State == NEUTRALITY)
					{
						Block[0][0].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 15)
				{
					if (Block[0][1].State == NEUTRALITY)
					{
						Block[0][1].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 25)
				{
					if (Block[0][2].State == NEUTRALITY)
					{
						Block[0][2].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
			}
			else if (_Player->Position.x == 30)
			{
				if (_Player->Position.y == 5)
				{
					if (Block[1][0].State == NEUTRALITY)
					{
						Block[1][0].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 15)
				{
					if (Block[1][1].State == NEUTRALITY)
					{
						Block[1][1].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 25)
				{
					if (Block[1][2].State == NEUTRALITY)
					{
						Block[1][2].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
			}
			else if (_Player->Position.x == 50)
			{
				if (_Player->Position.y == 5)
				{
					if (Block[2][0].State == NEUTRALITY)
					{
						Block[2][0].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 15)
				{
					if (Block[2][1].State == NEUTRALITY)
					{
						Block[2][1].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
				else if (_Player->Position.y == 25)
				{
					if (Block[2][2].State == NEUTRALITY)
					{
						Block[2][2].State = PLAYER1_MARK;
						Turn = TRUN_PLAYER2;
					}
				}
			}
		}
		else if (SceneState == SCENEIDS_STAGE_PVP)
		{
			if (Turn == TRUN_PLAYER2)
			{
				if (_Player->Position.x == 10)
				{
					if (_Player->Position.y == 5)
					{
						if (Block[0][0].State == NEUTRALITY)
						{
							Block[0][0].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 15)
					{
						if (Block[0][1].State == NEUTRALITY)
						{
							Block[0][1].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 25)
					{
						if (Block[0][2].State == NEUTRALITY)
						{
							Block[0][2].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
				}
				else if (_Player->Position.x == 30)
				{
					if (_Player->Position.y == 5)
					{
						if (Block[1][0].State == NEUTRALITY)
						{
							Block[1][0].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 15)
					{
						if (Block[1][1].State == NEUTRALITY)
						{
							Block[1][1].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 25)
					{
						if (Block[1][2].State == NEUTRALITY)
						{
							Block[1][2].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
				}
				else if (_Player->Position.x == 50)
				{
					if (_Player->Position.y == 5)
					{
						if (Block[2][0].State == NEUTRALITY)
						{
							Block[2][0].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 15)
					{
						if (Block[2][1].State == NEUTRALITY)
						{
							Block[2][1].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
					}
					else if (_Player->Position.y == 25)
					{
						if (Block[2][2].State == NEUTRALITY)
						{
							Block[2][2].State = PLAYER2_MARK;
							Turn = TRUN_PLAYER1;
						}
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

	//** 턴 표기
	if (Turn == TRUN_PLAYER1)
	{
		gotoxy(67, 15);
		printf_s("%s", "Turn : Player1");
	}
	else if (Turn == TRUN_PLAYER2)
	{
		gotoxy(67, 15);
		printf_s("%s", "Turn : Player2");
	}
}

void BoardInitialize(Object* _Board)
{
	//** 보드판관련 초기화
	Block[0][0].State = NEUTRALITY;
	Block[0][1].State = NEUTRALITY;
	Block[0][2].State = NEUTRALITY;
	Block[1][0].State = NEUTRALITY;
	Block[1][1].State = NEUTRALITY;
	Block[1][2].State = NEUTRALITY;
	Block[2][0].State = NEUTRALITY;
	Block[2][1].State = NEUTRALITY;
	Block[2][2].State = NEUTRALITY;

	Turn = TRUN_PLAYER1;
	Match = NOT_YET;
}

void BoardProgress(Object* _Board)
{
	//** 플레이어1 승리판정
	if (Block[0][0].State == PLAYER1_MARK)
	{
		if (Block[0][1].State == PLAYER1_MARK)
		{
			if (Block[0][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (Block[1][0].State == PLAYER1_MARK)
		{
			if (Block[2][0].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (Block[1][1].State == PLAYER1_MARK)
		{
			if (Block[2][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (Block[1][0].State == PLAYER1_MARK)
	{
		if (Block[1][1].State == PLAYER1_MARK)
		{
			if (Block[1][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (Block[2][0].State == PLAYER1_MARK)
	{
		if (Block[2][1].State == PLAYER1_MARK)
		{
			if (Block[2][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (Block[1][1].State == PLAYER1_MARK)
		{
			if (Block[0][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (Block[0][1].State == PLAYER1_MARK)
	{
		if (Block[1][1].State == PLAYER1_MARK)
		{
			if (Block[2][1].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (Block[0][2].State == PLAYER1_MARK)
	{
		if (Block[1][2].State == PLAYER1_MARK)
		{
			if (Block[2][2].State == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}

	//**** 이하 플레이어2 승리 판정
	if (Block[0][0].State == PLAYER2_MARK)
	{
		if (Block[0][1].State == PLAYER2_MARK)
		{
			if (Block[0][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (Block[1][0].State == PLAYER2_MARK)
		{
			if (Block[2][0].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (Block[1][1].State == PLAYER2_MARK)
		{
			if (Block[2][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (Block[1][0].State == PLAYER2_MARK)
	{
		if (Block[1][1].State == PLAYER2_MARK)
		{
			if (Block[1][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (Block[2][0].State == PLAYER2_MARK)
	{
		if (Block[2][1].State == PLAYER2_MARK)
		{
			if (Block[2][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (Block[1][1].State == PLAYER2_MARK)
		{
			if (Block[0][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (Block[0][1].State == PLAYER2_MARK)
	{
		if (Block[1][1].State == PLAYER2_MARK)
		{
			if (Block[2][1].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (Block[0][2].State == PLAYER2_MARK)
	{
		if (Block[1][2].State == PLAYER2_MARK)
		{
			if (Block[2][2].State == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}

	//** 이하 무승부 판정
	if (Block[0][0].State == NEUTRALITY) {}
	else if (Block[0][1].State == NEUTRALITY) {}
	else if (Block[0][2].State == NEUTRALITY) {}
	else if (Block[1][0].State == NEUTRALITY) {}
	else if (Block[1][1].State == NEUTRALITY) {}
	else if (Block[1][2].State == NEUTRALITY) {}
	else if (Block[2][0].State == NEUTRALITY) {}
	else if (Block[2][1].State == NEUTRALITY) {}
	else if (Block[2][2].State == NEUTRALITY) {}
	else
	{
		Match = DRAW;
	}
}

void BoardRender(Object* _Board)
{
	for (int y = 0; y < MAX_SIZE_Y + 1; y++)
	{
		if (y == 0 || y == 10 || y == 20 || y == MAX_SIZE_Y)
			SetCursorPosition(0, y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
		else
		{
			SetCursorPosition(0, y, (char*)"■");
			SetCursorPosition(20, y, (char*)"■");
			SetCursorPosition(40, y, (char*)"■");
			SetCursorPosition((MAX_SIZE_X), y, (char*)"■");
		}
	}

	if (SceneState == SCENEIDS_STAGE_PVP)
	{
		if (Block[0][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 0);
		}
		else if (Block[0][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 0);
		}
		if (Block[0][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 1);
		}
		else if (Block[0][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 1);
		}
		if (Block[0][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 2);
		}
		else if (Block[0][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 2);
		}

		if (Block[1][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 0);
		}
		else if (Block[1][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 0);
		}
		if (Block[1][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 1);
		}
		else if (Block[1][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 1);
		}
		if (Block[1][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 2);
		}
		else if (Block[1][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 2);
		}

		if (Block[2][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 0);
		}
		else if (Block[2][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 0);
		}
		if (Block[2][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 1);
		}
		else if (Block[2][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 1);
		}
		if (Block[2][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 2);
		}
		else if (Block[2][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 2);
		}
	}

	if (SceneState == SCENEIDS_STAGE_PVE)
	{
		if (Block[0][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 0);
		}
		else if (Block[0][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 0);
		}
		if (Block[0][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 1);
		}
		else if (Block[0][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 1);
		}
		if (Block[0][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(0, 2);
		}
		else if (Block[0][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(0, 2);
		}

		if (Block[1][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 0);
		}
		else if (Block[1][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 0);
		}
		if (Block[1][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 1);
		}
		else if (Block[1][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 1);
		}
		if (Block[1][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(1, 2);
		}
		else if (Block[1][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(1, 2);
		}

		if (Block[2][0].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 0);
		}
		else if (Block[2][0].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 0);
		}
		if (Block[2][1].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 1);
		}
		else if (Block[2][1].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 1);
		}
		if (Block[2][2].State == PLAYER1_MARK)
		{
			MarkPlayer1(2, 2);
		}
		else if (Block[2][2].State == PLAYER2_MARK)
		{
			MarkPlayer2(2, 2);
		}
	}

	if (Match == PLAYER1_WIN)
	{
		system("cls");
		SetCursorPosition(36, 13, (char*)"Player1 Win!");
		SetCursorPosition(12, 15, (char*)"게임을 종료하려면 ESC키를, 다시 시작하시려면 Enter키를 누르세요.");
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
			SceneState = SCENEIDS_EXIT;
		else if (GetAsyncKeyState(VK_RETURN))
			SceneState = SCENEIDS_MENU;
	}
	else if (Match == PLAYER2_WIN)
	{
		system("cls");
		SetCursorPosition(36, 13, (char*)"Player2 Win!");
		SetCursorPosition(12, 15, (char*)"게임을 종료하려면 ESC키를, 다시 시작하시려면 Enter키를 누르세요.");
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
			SceneState = SCENEIDS_EXIT;
		else if (GetAsyncKeyState(VK_RETURN))
			SceneState = SCENEIDS_MENU;
	}
	else if (Match == DRAW)
	{
		system("cls");
		SetCursorPosition(36, 13, (char*)"Darw!");
		SetCursorPosition(12, 15, (char*)"게임을 종료하려면 ESC키를, 다시 시작하시려면 Enter키를 누르세요.");
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
			SceneState = SCENEIDS_EXIT;
		else if (GetAsyncKeyState(VK_RETURN))
			SceneState = SCENEIDS_MENU;
	}
}

void AIInitialize()
{
	Block[0][0].Efficiency = 502;
	Block[1][0].Efficiency = 201;
	Block[2][0].Efficiency = 501;
	Block[0][1].Efficiency = 200;
	Block[1][1].Efficiency = 1000;
	Block[2][1].Efficiency = 199;
	Block[0][2].Efficiency = 499;
	Block[1][2].Efficiency = 198;
	Block[2][2].Efficiency = 498;

	Block[0][0].ID = 0;
	Block[1][0].ID = 1;
	Block[2][0].ID = 2;
	Block[0][1].ID = 3;
	Block[1][1].ID = 4;
	Block[2][1].ID = 5;
	Block[0][2].ID = 6;
	Block[1][2].ID = 7;
	Block[2][2].ID = 8;
}

void AIProgress()
{
	Block[0][0].Efficiency = 322;
	Block[1][0].Efficiency = 201;
	Block[2][0].Efficiency = 321;
	Block[0][1].Efficiency = 200;
	Block[1][1].Efficiency = 1000;
	Block[2][1].Efficiency = 199;
	Block[0][2].Efficiency = 319;
	Block[1][2].Efficiency = 198;
	Block[2][2].Efficiency = 318;

	Block[0][0].ID = 0;
	Block[1][0].ID = 1;
	Block[2][0].ID = 2;
	Block[0][1].ID = 3;
	Block[1][1].ID = 4;
	Block[2][1].ID = 5;
	Block[0][2].ID = 6;
	Block[1][2].ID = 7;
	Block[2][2].ID = 8;

	if (Block[0][0].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 10000;
		Block[1][0].Efficiency -= 100;
		Block[2][0].Efficiency -= 100;
		Block[0][1].Efficiency -= 100;
		Block[0][2].Efficiency -= 100;
		Block[2][2].Efficiency -= 100;

		if (Block[0][2].State == NEUTRALITY)
		{
			if (Block[0][1].State == PLAYER1_MARK)
			{
				Block[0][2].Efficiency += 10000;
			}
		}
		if (Block[0][1].State == NEUTRALITY)
		{
			if (Block[0][2].State == PLAYER1_MARK)
			{
				Block[0][1].Efficiency += 10000;
			}
		}
	}
	if (Block[0][1].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 100;
		Block[0][1].Efficiency -= 10000;
		Block[2][1].Efficiency -= 100;
		Block[0][2].Efficiency -= 100;

		if (Block[2][1].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER1_MARK)
			{
				Block[2][1].Efficiency += 10000;
			}
		}
	}
	if (Block[0][2].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 100;
		Block[2][0].Efficiency -= 100;
		Block[0][1].Efficiency -= 100;
		Block[0][2].Efficiency -= 10000;
		Block[1][2].Efficiency -= 100;
		Block[2][2].Efficiency -= 100;

		if (Block[0][0].State == NEUTRALITY)
		{
			if (Block[0][1].State == PLAYER1_MARK)
			{
				Block[0][0].Efficiency += 10000;
			}
		}
	}
	if (Block[1][0].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 100;
		Block[1][0].Efficiency -= 10000;
		Block[2][0].Efficiency -= 100;
		Block[1][2].Efficiency -= 100;

		if (Block[1][2].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER1_MARK)
			{
				Block[1][2].Efficiency += 10000;
			}
		}
		if (Block[1][1].State == NEUTRALITY)
		{
			if (Block[1][2].State == PLAYER1_MARK)
			{
				Block[1][1].Efficiency += 10000;
			}
		}
	}
	if (Block[1][1].State == PLAYER1_MARK)
	{
		Block[1][1].Efficiency -= 10000;
	}
	if (Block[1][2].State == PLAYER1_MARK)
	{
		Block[1][0].Efficiency -= 100;
		Block[0][2].Efficiency -= 100;
		Block[1][2].Efficiency -= 10000;
		Block[2][2].Efficiency -= 100;

		if (Block[1][0].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER1_MARK)
			{
				Block[1][0].Efficiency += 10000;
			}
		}
	}
	if (Block[2][0].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 100;
		Block[1][0].Efficiency -= 100;
		Block[2][0].Efficiency -= 10000;
		Block[2][1].Efficiency -= 100;
		Block[0][2].Efficiency -= 100;
		Block[2][2].Efficiency -= 100;

		if (Block[2][2].State == NEUTRALITY)
		{
			if (Block[2][1].State == PLAYER1_MARK)
			{
				Block[2][2].Efficiency += 10000;
			}
		}
		if (Block[2][1].State == NEUTRALITY)
		{
			if (Block[2][2].State == PLAYER1_MARK)
			{
				Block[2][1].Efficiency += 10000;
			}
		}
	}
	if (Block[2][1].State == PLAYER1_MARK)
	{
		Block[2][0].Efficiency -= 100;
		Block[0][1].Efficiency -= 100;
		Block[2][1].Efficiency -= 10000;
		Block[2][2].Efficiency -= 100;

		if (Block[0][1].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER1_MARK)
			{
				Block[0][1].Efficiency += 10000;
			}
		}
	}
	if (Block[2][2].State == PLAYER1_MARK)
	{
		Block[0][0].Efficiency -= 100;
		Block[2][0].Efficiency -= 100;
		Block[2][1].Efficiency -= 100;
		Block[0][2].Efficiency -= 100;
		Block[1][2].Efficiency -= 100;
		Block[2][2].Efficiency -= 10000;

		if (Block[2][0].State == NEUTRALITY)
		{
			if (Block[2][1].State == PLAYER1_MARK)
			{
				Block[2][0].Efficiency += 10000;
			}
		}
	}

	//*** AI승리 알고리즘
	if (Block[0][0].State == PLAYER2_MARK)
	{
		Block[0][0].Efficiency -= 10000;

		if (Block[0][1].State == NEUTRALITY)
		{
			if (Block[0][2].State == PLAYER2_MARK)
			{
				Block[0][1].Efficiency += 20000;
			}
		}

		if (Block[2][2].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[2][2].Efficiency += 20000;
			}
		}
	}
	if (Block[0][1].State == PLAYER2_MARK)
	{
		Block[0][1].Efficiency -= 10000;

		if (Block[2][1].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[2][1].Efficiency += 20000;
			}
		}
	}
	if (Block[0][2].State == PLAYER2_MARK)
	{
		Block[0][2].Efficiency -= 10000;

		if (Block[1][2].State == NEUTRALITY)
		{
			if (Block[2][2].State == PLAYER2_MARK)
			{
				Block[1][2].Efficiency += 20000;
			}
		}
		if (Block[2][2].State == NEUTRALITY)
		{
			if (Block[1][2].State == PLAYER2_MARK)
			{
				Block[2][2].Efficiency += 20000;
			}
		}
	}
	if (Block[1][0].State == PLAYER2_MARK)
	{
		Block[1][0].Efficiency -= 10000;

		if (Block[1][2].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[1][2].Efficiency += 20000;
			}
		}
	}
	if (Block[1][1].State == PLAYER2_MARK)
	{
		Block[1][1].Efficiency -= 10000;
	}
	if (Block[1][2].State == PLAYER2_MARK)
	{
		Block[1][2].Efficiency -= 10000;

		if (Block[1][0].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[1][0].Efficiency += 20000;
			}
		}
	}
	if (Block[2][0].State == PLAYER2_MARK)
	{
		Block[2][0].Efficiency -= 10000;

		if (Block[2][1].State == NEUTRALITY)
		{
			if (Block[2][2].State == PLAYER2_MARK)
			{
				Block[2][1].Efficiency += 20000;
			}
		}

		if (Block[0][2].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[0][2].Efficiency += 20000;
			}
		}
	}
	if (Block[2][1].State == PLAYER2_MARK)
	{
		Block[2][1].Efficiency -= 10000;

		if (Block[0][1].State == NEUTRALITY)
		{
			if (Block[1][1].State == PLAYER2_MARK)
			{
				Block[0][1].Efficiency += 20000;
			}
		}
	}
	if (Block[2][2].State == PLAYER2_MARK)
	{
		Block[2][2].Efficiency -= 10000;
	}

	int EfficiencyMaximum = 0;

	if (EfficiencyMaximum < Block[0][0].Efficiency)
	{
		EfficiencyMaximum = Block[0][0].Efficiency;
		AIBlock = Block[0][0].ID;
	}
	if (EfficiencyMaximum < Block[1][0].Efficiency)
	{
		EfficiencyMaximum = Block[1][0].Efficiency;
		AIBlock = Block[1][0].ID;
	}
	if (EfficiencyMaximum < Block[2][0].Efficiency)
	{
		EfficiencyMaximum = Block[2][0].Efficiency;
		AIBlock = Block[2][0].ID;
	}
	if (EfficiencyMaximum < Block[0][1].Efficiency)
	{
		EfficiencyMaximum = Block[0][1].Efficiency;
		AIBlock = Block[0][1].ID;
	}
	if (EfficiencyMaximum < Block[1][1].Efficiency)
	{
		EfficiencyMaximum = Block[1][1].Efficiency;
		AIBlock = Block[1][1].ID;
	}
	if (EfficiencyMaximum < Block[2][1].Efficiency)
	{
		EfficiencyMaximum = Block[2][1].Efficiency;
		AIBlock = Block[2][1].ID;
	}
	if (EfficiencyMaximum < Block[0][2].Efficiency)
	{
		EfficiencyMaximum = Block[0][2].Efficiency;
		AIBlock = Block[0][2].ID;
	}
	if (EfficiencyMaximum < Block[1][2].Efficiency)
	{
		EfficiencyMaximum = Block[1][2].Efficiency;
		AIBlock = Block[1][2].ID;
	}
	if (EfficiencyMaximum < Block[2][2].Efficiency)
	{
		EfficiencyMaximum = Block[2][2].Efficiency;
		AIBlock = Block[2][2].ID;
	}

	if (Turn == TRUN_PLAYER2)
	{
		switch (AIBlock)
		{
		case 0:
			if (Block[0][0].State == NEUTRALITY)
			{
				Block[0][0].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 3:
			if (Block[0][1].State == NEUTRALITY)
			{
				Block[0][1].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 6:
			if (Block[0][2].State == NEUTRALITY)
			{
				Block[0][2].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 1:
			if (Block[1][0].State == NEUTRALITY)
			{
				Block[1][0].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 4:
			if (Block[1][1].State == NEUTRALITY)
			{
				Block[1][1].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 7:
			if (Block[1][2].State == NEUTRALITY)
			{
				Block[1][2].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 2:
			if (Block[2][0].State == NEUTRALITY)
			{
				Block[2][0].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 5:
			if (Block[2][1].State == NEUTRALITY)
			{
				Block[2][1].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		case 8:
			if (Block[2][2].State == NEUTRALITY)
			{
				Block[2][2].State = PLAYER2_MARK;
			}
			Turn = TRUN_PLAYER1;
			break;
		}
	}
}

void AIRender()
{

}

void MarkPlayer1(int MarkLocationX, int MarkLocationY)
{
	for (int i = 0; i < 3; ++i)
	{
		MarkLocation[i].x = 8 + 20 * i;
		MarkLocation[i].y = 3 + 10 * i;
	}

	gotoxy(MarkLocation[MarkLocationX].x, MarkLocation[MarkLocationY].y);
	printf_s("%s", "■■■");

	for (int y = MarkLocation[MarkLocationY].y + 1; y < MarkLocation[MarkLocationY].y + 4; ++y)
		for (int x = MarkLocation[MarkLocationX].x - 2; x < MarkLocation[MarkLocationX].x + 7; ++x)
			if (x == MarkLocation[MarkLocationX].x - 2 || x == MarkLocation[MarkLocationX].x + 6)
				SetCursorPosition(x, y, (char*)"■");

	gotoxy(MarkLocation[MarkLocationX].x, MarkLocation[MarkLocationY].y + 4);
	printf_s("%s", "■■■");
}

void MarkPlayer2(int MarkLocationX, int MarkLocationY)
{
	for (int i = 0; i < 3; ++i)
	{
		MarkLocation[i].x = 10 + 20 * i;
		MarkLocation[i].y = 5 + 10 * i;
	}

	gotoxy(MarkLocation[MarkLocationX].x - 4, MarkLocation[MarkLocationY].y - 2);
	printf_s("%s", "■      ■");

	gotoxy(MarkLocation[MarkLocationX].x - 2, MarkLocation[MarkLocationY].y - 1);
	printf_s("%s", "■  ■");

	gotoxy(MarkLocation[MarkLocationX].x, MarkLocation[MarkLocationY].y);
	printf_s("%s", "■");

	gotoxy(MarkLocation[MarkLocationX].x - 2, MarkLocation[MarkLocationY].y + 1);
	printf_s("%s", "■  ■");

	gotoxy(MarkLocation[MarkLocationX].x - 4, MarkLocation[MarkLocationY].y + 2);
	printf_s("%s", "■      ■");
}