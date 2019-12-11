#include "GameScene.h"
#include "defines.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//생성자
GameScene::GameScene()
{

}

//초기화(override)
void GameScene::Init(HWND hWnd)
{
	TCHAR buf[256];
	Cur_Sec = 0.0f;
	Cur_Min = 0.0f;
	Click_Check = false;
	Time = 0.0f;
	Answer_Count = 0;
	Mine_Count = 0;
	Hint_Num = 0;

	m_DelClick.reserve(480);
	Die = false;
	Flag_Check = false;
	
	////맵 초기화(이중 백터 사용)////
	GameManager::get_Instance()->Init();

	//배경화면 등록
	m_pBackDC = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");

	//상자 등록
	for (int i = 0; i < MAX_BLOCK; i++)
	{
		wsprintf(buf, "RES\\block_%d.bmp", i);

		tmp_Block = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBlock.push_back(tmp_Block);
	}
}

//키 입력(override)
bool GameScene::Input(float _fETime)
{
	DeleteBlock tmp_delblock;

	////키보드에 맞는 명령어 매칭////
	//ESC를 누르면 종료
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//마우스 좌클릭(클릭)
	if (DoEngine::InputManager::get_Instance()->isKeyDown(VK_LBUTTON))
	{
		m_Lclick = DoEngine::InputManager::get_Instance()->get_MousePoint();
		tmp_delblock.Click_x = floor(GameManager::get_Instance()->get_UnitX(m_Lclick.x));
		tmp_delblock.Click_y = floor(GameManager::get_Instance()->get_UnitY(m_Lclick.y));

		if (GameManager::get_Instance()->get_UnitPos(tmp_delblock.Click_x, tmp_delblock.Click_y
		) == MINE_BLOCK)
		{
			Die = true;
		}

		Draw_Remove(tmp_delblock.Click_x, tmp_delblock.Click_y);
	}

	//마우스 우클릭(지뢰 그리기)
	if (DoEngine::InputManager::get_Instance()->isKeyDown(VK_RBUTTON))
	{
		int tmp_x = 0;
		int tmp_y = 0;
		Flag_Check = false;
		Flag_InputCheck = true;

		//마우스 포인트 값 가져오기
		m_Rclick = DoEngine::InputManager::get_Instance()->get_MousePoint();
		//마우스 포인트값 변환
		tmp_x = GameManager::get_Instance()->get_UnitX(m_Rclick.x);
		tmp_y = GameManager::get_Instance()->get_UnitX(m_Rclick.y);

		for (int i = 0; i < m_DelClick.size(); i++)
		{
			if (m_DelClick[i].Click_x == tmp_x && m_DelClick[i].Click_y == tmp_y)
			{
				Flag_InputCheck = false;
			}
		}

		if (Flag_InputCheck)
		{
			for (int i = 0; i < m_vMines.size(); i++)
			{
				if ((tmp_x == m_vMines[i]->get_PosX()) && (tmp_y == m_vMines[i]->get_PosY()))
				{
					Answer_Count++;
					break;
				}
			}

			//먼저 기존에 찍은 깃발이 있는지 검사
			for (auto iter = m_vFlags.begin(); iter != m_vFlags.end();)
			{
				if (((*iter)->get_PosX() == tmp_x) && ((*iter)->get_PosY() == tmp_y))
				{
					iter = m_vFlags.erase(iter);
					Flag_Check = true;
					Mine_Count--;
				}
				else
				{
					++iter;
				}
			}

			//없다면 깃발 생성
			if (!Flag_Check)
			{
				tmp_Flag = new FlagBlock();
				tmp_Flag->Init();
				tmp_Flag->set_Posx(tmp_x);
				tmp_Flag->set_Posy(tmp_y);
				Mine_Count++;

				m_vFlags.push_back(tmp_Flag);
			}
		}
	}

	return false;
}

//Update(override)
void GameScene::Update(float _fETime)
{
	//게임이 시작한 후 시간을 잰다
	Cur_Sec += _fETime;

	//60초가 지나면 1분 증가
	if (Cur_Sec > TIME_MAX)
	{
		Cur_Min++;
		Cur_Sec = 0;
	}

	//End화면으로 넘어감
	if (Answer_Count == MAX_MINE || Die)
	{
		Time += _fETime;

		if (Answer_Count == MAX_MINE)
		{
			GameManager::get_Instance()->set_GameResult(GAME_WIN);
		}
		else
		{
			GameManager::get_Instance()->set_GameResult(GAME_LOSE);
		}

		if (Time >= 2.0f)
		{
			DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_END);
		}
	}
	Hint_Block(_fETime);
}

//Draw함수(Override)
void GameScene::Draw(HDC hdc)
{
	//배경화면을 그린다.
	m_pBackDC->Draw(0, 0);
	//풀블럭을 제외한 그리기
	All_Draw();
	//풀블럭 그리기
	Draw_FullBlock();

	//깃발 그리기
	for (int i = 0; i < m_vFlags.size(); i++)
	{
		m_vFlags[i]->Draw();
	}

	if (Die || GameManager::get_Instance()->get_Trigger() == true)
	{
		for (int i = 0; i < m_vMines.size(); i++)
		{
			m_vMines[i]->Draw();
		}		
	}

	//시간 표시
	wsprintf(tmp_Time, "%d : %d", (int)Cur_Min, (int)Cur_Sec);
	DoEngine::UIManager::get_Instance()->AddText(tmp_Time, 168, 474, 23, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	wsprintf(tmp_Count, "%d", Mine_Count);
	DoEngine::UIManager::get_Instance()->AddText(tmp_Count, 670, 474, 23, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//숫자 그리기
void GameScene::Draw_Number(int _x, int _y)
{
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == ONE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[ONE_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == TWO_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[TWO_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == THREE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[THREE_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == FOUR_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[FOUR_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == FIVE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[FIVE_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == SIX_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[SIX_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == SEVEN_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[SEVEN_BLOCK]);
	}
	//숫자 블럭 그리기
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == EIGHT_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[EIGHT_BLOCK]);
	}
}

//모든 블럭 그리기
void GameScene::All_Draw()
{
	/*
	MineSize 26 * 26
	*/
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			//빈블럭 그리기
			if (GameManager::get_Instance()->get_UnitPos(i, j) == EMPTY_BLOCK)
			{
				if (i == 0 && j == 0)
				{
					m_vBlock[EMPTY_BLOCK]->Draw(BLOCKSTART_X, BLOCKSTART_Y);
				}
				else
				{
					Draw_Block(i, j, m_vBlock[EMPTY_BLOCK]);
				}
			}

			//지뢰 그리기
			if (GameManager::get_Instance()->get_UnitPos(i, j) == MINE_BLOCK)
			{
				//지뢰 등록
				tmp_Mine = new MineBlock();

				tmp_Mine->Init();
				tmp_Mine->set_Posx(i);
				tmp_Mine->set_Posy(j);
				tmp_Mine->Draw(i, j);

				m_vMines.push_back(tmp_Mine);
			}
			Draw_Number(i, j);
		}
	}
}

//풀블럭 그리기
void GameScene::Draw_FullBlock()
{
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			Click_Check = false;

			for (int c = 0; c < m_DelClick.size(); c++)
			{
				if (m_DelClick[c].Click_x == i && m_DelClick[c].Click_y == j)
				{
					Click_Check = true;
				}
			}

			if (!Click_Check)
			{
				if (i == 0 && j == 0)
				{
					m_vBlock[FULL_BLOCK]->Draw(BLOCKSTART_X, BLOCKSTART_Y);
				}

				else
				{
					Draw_Block(i, j, m_vBlock[FULL_BLOCK]);
				}
			}
		}
	}
}

//근처 숫자가 나올때까지 지우기
void GameScene::Draw_Remove(int This_X, int This_Y)
{
	//정해진 맵안에서만 인식
	if ((This_X >= 0 && This_X < MINE_WIDTH) && (This_Y >= 0 && This_Y < MINE_HEIGHT))
	{
		if (GameManager::get_Instance()->get_UnitPos(This_X, This_Y) != MINE_BLOCK)
		{
			for (int i = 0; i < m_DelClick.size(); i++)
			{
				if (m_DelClick[i].Click_x == This_X && m_DelClick[i].Click_y == This_Y)
				{
					return;
				}
			}

			DeleteBlock tmp_delblock;

			tmp_delblock.Click_x = This_X;
			tmp_delblock.Click_y = This_Y;
			m_DelClick.push_back(tmp_delblock);
		}

		if(GameManager::get_Instance()->get_UnitPos(This_X, This_Y) != EMPTY_BLOCK)
		{
			return;
		}
	}
	else
	{
		return;
	}
	Draw_Remove(This_X + 1, This_Y);
	Draw_Remove(This_X, This_Y + 1);
	Draw_Remove(This_X - 1, This_Y);
	Draw_Remove(This_X, This_Y - 1);
}

//블럭 그리기
void GameScene::Draw_Block(int _x, int _y, DoEngine::BitMap* _bmp)
{
	_bmp->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//힌트 블럭 그리기 
void GameScene::Hint_Block(float _fETime)
{
	Hint_Num = GameManager::get_Instance()->get_NumTrigger();

	if (Hint_Num != 0)
	{
		for (int i = 0; i < MINE_WIDTH; i++)
		{
			for (int j = 0; j < MINE_HEIGHT; j++)
			{
				//숫자 블럭 그리기
				if (GameManager::get_Instance()->get_UnitPos(i, j) == Hint_Num)
				{
					Draw_Block(i, j, m_vBlock[Hint_Num]);
				}
			}
		}
	}
}

//Release()함수 (override)
void GameScene::Release()
{
	m_vBlock.clear();
	m_DelClick.clear();
	m_vMines.clear();
	m_vFlags.clear();
}

//소멸자
GameScene::~GameScene()
{
	Release();
}