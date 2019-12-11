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
int Match = NOT_YET;

int AIBlock = 4;

void SetScene(Object* _Player, Object* _Board);

void gotoxy(int x, int y);
void SetCursorPosition(int _x, int _y, char* _pTexture);
void InputKey(Object* _pObj);
void SetDircetion(Object* _pObj);

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
		MenuProgress(_Player, _Board);
		MenuRender();
		break;

	case SCENEIDS_STAGE_PVP:
		StageProgress(_Player, _Board);
		StageRender(_Player, _Board);
		break;

	case SCENEIDS_STAGE_PVE:
		AIProgress();
		AIRender();
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

void MenuProgress(Object* _Player, Object* _Board)
{
	if (GetAsyncKeyState('2'))
	{
		SceneState = SCENEIDS_STAGE_PVP;
		StageInitialize(_Player, _Board);
	}
}

void MenuRender()
{
	SetCursorPosition(57, 17, (char*)"Menu");
}

void StageInitialize(Object* _Player, Object* _Board)
{
	for (int i = 0; i < 32; ++i)
	{
		if (GetAsyncKeyState(VK_UP)) {}
		if (GetAsyncKeyState(VK_DOWN)) {}
		if (GetAsyncKeyState(VK_LEFT)) {}
		if (GetAsyncKeyState(VK_RIGHT)) {}
		if (GetAsyncKeyState(VK_SPACE)) {}
	}

	PlayerInitialize(_Player);
	BoardInitialize(_Board);
}

void StageProgress(Object* _Player, Object* _Board)
{
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
					if (BLOCKAA == NEUTRALITY)
					{
						BLOCKAA = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 30;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKAB == NEUTRALITY)
					{
						BLOCKAB = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 30;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKAC == NEUTRALITY)
					{
						BLOCKAC = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 30;
				}
			}
			else if (_Player->Position.x == 30)
			{
				if (_Player->Position.y == 5)
				{
					if (BLOCKBA == NEUTRALITY)
					{
						BLOCKBA = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 50;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKBB == NEUTRALITY)
					{
						BLOCKBB = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 50;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKBC == NEUTRALITY)
					{
						BLOCKBC = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.x = 50;
				}
			}
			else if (_Player->Position.x == 50)
			{
				if (_Player->Position.y == 5)
				{
					if (BLOCKCA == NEUTRALITY)
					{
						BLOCKCA = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.y = 15;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKCB == NEUTRALITY)
					{
						BLOCKCB = PLAYER1_MARK;
					}
					Turn = TRUN_PLAYER2;
					//_Player->Position.y = 25;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKCC == NEUTRALITY)
					{
						BLOCKCC = PLAYER1_MARK;
					}
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
					if (BLOCKAA == NEUTRALITY)
					{
						BLOCKAA = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 30;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKAB == NEUTRALITY)
					{
						BLOCKAB = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 30;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKAC == NEUTRALITY)
					{
						BLOCKAC = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 30;
				}
			}
			else if (_Player->Position.x == 30)
			{
				if (_Player->Position.y == 5)
				{
					if (BLOCKBA == NEUTRALITY)
					{
						BLOCKBA = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 50;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKBB == NEUTRALITY)
					{
						BLOCKBB = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 50;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKBC == NEUTRALITY)
					{
						BLOCKBC = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.x = 50;
				}
			}
			else if (_Player->Position.x == 50)
			{
				if (_Player->Position.y == 5)
				{
					if (BLOCKCA == NEUTRALITY)
					{
						BLOCKCA = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.y = 15;
				}
				else if (_Player->Position.y == 15)
				{
					if (BLOCKCB == NEUTRALITY)
					{
						BLOCKCB = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.y = 25;
				}
				else if (_Player->Position.y == 25)
				{
					if (BLOCKCC == NEUTRALITY)
					{
						BLOCKCC = PLAYER2_MARK;
					}
					Turn = TRUN_PLAYER1;
					//_Player->Position.y = 15;
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
}

void BoardInitialize(Object* _Board)
{
	BLOCKAA = NEUTRALITY;
	BLOCKAB = NEUTRALITY;
	BLOCKAC = NEUTRALITY;
	BLOCKBA = NEUTRALITY;
	BLOCKBB = NEUTRALITY;
	BLOCKBC = NEUTRALITY;
	BLOCKCA = NEUTRALITY;
	BLOCKCB = NEUTRALITY;
	BLOCKCC = NEUTRALITY;

	Turn = TRUN_PLAYER1;
	Match = NOT_YET;
}

void BoardProgress(Object* _Board)
{
	//** 플레이어1 승리판정
	if (BLOCKAA == PLAYER1_MARK)
	{
		if (BLOCKAB == PLAYER1_MARK)
		{
			if (BLOCKAC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (BLOCKBA == PLAYER1_MARK)
		{
			if (BLOCKCA == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (BLOCKBB == PLAYER1_MARK)
		{
			if (BLOCKCC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (BLOCKBA == PLAYER1_MARK)
	{
		if (BLOCKBB == PLAYER1_MARK)
		{
			if (BLOCKBC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (BLOCKCA == PLAYER1_MARK)
	{
		if (BLOCKCB == PLAYER1_MARK)
		{
			if (BLOCKCC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
		else if (BLOCKBB == PLAYER1_MARK)
		{
			if (BLOCKAC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (BLOCKAB == PLAYER1_MARK)
	{
		if (BLOCKBB == PLAYER1_MARK)
		{
			if (BLOCKCB == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}
	if (BLOCKAC == PLAYER1_MARK)
	{
		if (BLOCKBC == PLAYER1_MARK)
		{
			if (BLOCKCC == PLAYER1_MARK)
				Match = PLAYER1_WIN;
		}
	}

	//**** 이하 플레이어2 승리 판정
	if (BLOCKAA == PLAYER2_MARK)
	{
		if (BLOCKAB == PLAYER2_MARK)
		{
			if (BLOCKAC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (BLOCKBA == PLAYER2_MARK)
		{
			if (BLOCKCA == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (BLOCKBB == PLAYER2_MARK)
		{
			if (BLOCKCC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (BLOCKBA == PLAYER2_MARK)
	{
		if (BLOCKBB == PLAYER2_MARK)
		{
			if (BLOCKBC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (BLOCKCA == PLAYER2_MARK)
	{
		if (BLOCKCB == PLAYER2_MARK)
		{
			if (BLOCKCC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
		else if (BLOCKBB == PLAYER2_MARK)
		{
			if (BLOCKAC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (BLOCKAB == PLAYER2_MARK)
	{
		if (BLOCKBB == PLAYER2_MARK)
		{
			if (BLOCKCB == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
	}
	if (BLOCKAC == PLAYER2_MARK)
	{
		if (BLOCKBC == PLAYER2_MARK)
		{
			if (BLOCKCC == PLAYER2_MARK)
				Match = PLAYER2_WIN;
		}
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
		if (BLOCKAA == PLAYER1_MARK)
		{
			MarkPlayer1(0, 0);
		}
		else if (BLOCKAA == PLAYER2_MARK)
		{
			MarkPlayer2(0, 0);
		}
		if (BLOCKAB == PLAYER1_MARK)
		{
			MarkPlayer1(0, 1);
		}
		else if (BLOCKAB == PLAYER2_MARK)
		{
			MarkPlayer2(0, 1);
		}
		if (BLOCKAC == PLAYER1_MARK)
		{
			MarkPlayer1(0, 2);
		}
		else if (BLOCKAC == PLAYER2_MARK)
		{
			MarkPlayer2(0, 2);
		}

		if (BLOCKBA == PLAYER1_MARK)
		{
			MarkPlayer1(1, 0);
		}
		else if (BLOCKBA == PLAYER2_MARK)
		{
			MarkPlayer2(1, 0);
		}
		if (BLOCKBB == PLAYER1_MARK)
		{
			MarkPlayer1(1, 1);
		}
		else if (BLOCKBB == PLAYER2_MARK)
		{
			MarkPlayer2(1, 1);
		}
		if (BLOCKBC == PLAYER1_MARK)
		{
			MarkPlayer1(1, 2);
		}
		else if (BLOCKBC == PLAYER2_MARK)
		{
			MarkPlayer2(1, 2);
		}

		if (BLOCKCA == PLAYER1_MARK)
		{
			MarkPlayer1(2, 0);
		}
		else if (BLOCKCA == PLAYER2_MARK)
		{
			MarkPlayer2(2, 0);
		}
		if (BLOCKCB == PLAYER1_MARK)
		{
			MarkPlayer1(2, 1);
		}
		else if (BLOCKCB == PLAYER2_MARK)
		{
			MarkPlayer2(2, 1);
		}
		if (BLOCKCC == PLAYER1_MARK)
		{
			MarkPlayer1(2, 2);
		}
		else if (BLOCKCC == PLAYER2_MARK)
		{
			MarkPlayer2(2, 2);
		}
	}
	if (Match == PLAYER1_WIN)
	{
		system("cls");
		SetCursorPosition(57, 17, (char*)"Player1 Win!");
		SetCursorPosition(57, 18, (char*)"게임을 종료하려면 ESC키를, 매뉴로 가시려면 3키를 누르세요.");
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
			SceneState = SCENEIDS_EXIT;
		else if (GetAsyncKeyState('3'))
			SceneState = SCENEIDS_MENU;
	}
	else if (Match == PLAYER2_WIN)
	{
		system("cls");
		SetCursorPosition(57, 17, (char*)"Player2 Win!");
		SetCursorPosition(57, 18, (char*)"게임을 종료하려면 ESC키를, 매뉴로 가시려면 3키를 누르세요.");
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
			SceneState = SCENEIDS_EXIT;
		else if (GetAsyncKeyState('3'))
			SceneState = SCENEIDS_MENU;
	}
}

void AIInitialize()
{
	
}

void AIProgress()
{
	Block[0].Efficiency = 500;
	Block[1].Efficiency = 200;
	Block[2].Efficiency = 500;
	Block[3].Efficiency = 200;
	Block[4].Efficiency = 1000;
	Block[5].Efficiency = 200;
	Block[6].Efficiency = 500;
	Block[7].Efficiency = 200;
	Block[8].Efficiency = 500;

	Block[0].ID = 0;
	Block[1].ID = 1;
	Block[2].ID = 2;
	Block[3].ID = 3;
	Block[4].ID = 4;
	Block[5].ID = 5;
	Block[6].ID = 6;
	Block[7].ID = 7;
	Block[8].ID = 8;

	int EfficiencyMaximum = 0;
	
	if (BLOCKAA == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 10000;
		Block[1].Efficiency -= 100;
		Block[2].Efficiency -= 100;
		Block[3].Efficiency -= 100;
		Block[6].Efficiency -= 100;
		Block[8].Efficiency -= 100;
	}
	if (BLOCKAB == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 100;
		Block[3].Efficiency -= 10000;
		Block[5].Efficiency -= 100;
		Block[6].Efficiency -= 100;		
	}
	if (BLOCKAC == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 100;
		Block[2].Efficiency -= 100;
		Block[3].Efficiency -= 100;
		Block[6].Efficiency -= 10000;
		Block[7].Efficiency -= 100;
		Block[8].Efficiency -= 100;
	}
	if (BLOCKBA == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 100;
		Block[1].Efficiency -= 10000;
		Block[2].Efficiency -= 100;
		Block[7].Efficiency -= 100;
	}
	if (BLOCKBB == PLAYER1_MARK)
	{
		Block[4].Efficiency -= 10000;
	}
	if (BLOCKBC == PLAYER1_MARK)
	{
		Block[1].Efficiency -= 100;
		Block[6].Efficiency -= 100;
		Block[7].Efficiency -= 10000;
		Block[8].Efficiency -= 100;
	}
	if (BLOCKCA == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 100;
		Block[1].Efficiency -= 100;
		Block[2].Efficiency -= 10000;
		Block[5].Efficiency -= 100;
		Block[6].Efficiency -= 100;
		Block[8].Efficiency -= 100;
	}
	if (BLOCKCB == PLAYER1_MARK)
	{
		Block[2].Efficiency -= 100;
		Block[3].Efficiency -= 100;
		Block[5].Efficiency -= 10000;
		Block[8].Efficiency -= 100;
	}
	if (BLOCKCC == PLAYER1_MARK)
	{
		Block[0].Efficiency -= 100;
		Block[2].Efficiency -= 100;
		Block[5].Efficiency -= 100;
		Block[6].Efficiency -= 100;
		Block[7].Efficiency -= 100;
		Block[8].Efficiency -= 10000;
	}

	if (EfficiencyMaximum < Block[0].Efficiency)
	{
		AIBlock = Block[0].ID;
	}
	if (EfficiencyMaximum < Block[1].Efficiency)
	{
		AIBlock = Block[1].ID;
	}
	if (EfficiencyMaximum < Block[2].Efficiency)
	{
		AIBlock = Block[2].ID;
	}
	if (EfficiencyMaximum < Block[3].Efficiency)
	{
		AIBlock = Block[3].ID;
	}
	if (EfficiencyMaximum < Block[4].Efficiency)
	{
		AIBlock = Block[4].ID;
	}
	if (EfficiencyMaximum < Block[5].Efficiency)
	{
		AIBlock = Block[5].ID;
	}
	if (EfficiencyMaximum < Block[6].Efficiency)
	{
		AIBlock = Block[6].ID;
	}
	if (EfficiencyMaximum < Block[7].Efficiency)
	{
		AIBlock = Block[7].ID;
	}
	if (EfficiencyMaximum < Block[8].Efficiency)
	{
		AIBlock = Block[8].ID;
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
	{
		for (int x = MarkLocation[MarkLocationX].x - 2; x < MarkLocation[MarkLocationX].x + 7; ++x)
		{
			if (x == MarkLocation[MarkLocationX].x - 2 || x == MarkLocation[MarkLocationX].x + 6)
			{
				SetCursorPosition(x, y, (char*)"■");
			}
		}
	}

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