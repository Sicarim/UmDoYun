#include "GameScene.h"
#include "defines.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "ResourcesManager.h"
#include "GameManager.h"

//������
GameScene::GameScene()
{

}

//�ʱ�ȭ(override)
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
	
	////�� �ʱ�ȭ(���� ���� ���)////
	GameManager::get_Instance()->Init();

	//���ȭ�� ���
	m_pBackDC = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");

	//���� ���
	for (int i = 0; i < MAX_BLOCK; i++)
	{
		wsprintf(buf, "RES\\block_%d.bmp", i);

		tmp_Block = DoEngine::ResourcesManager::get_Instance()->get_Bitmap(buf);
		m_vBlock.push_back(tmp_Block);
	}
}

//Ű �Է�(override)
bool GameScene::Input(float _fETime)
{
	DeleteBlock tmp_delblock;

	////Ű���忡 �´� ��ɾ� ��Ī////
	//ESC�� ������ ����
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	//���콺 ��Ŭ��(Ŭ��)
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

	//���콺 ��Ŭ��(���� �׸���)
	if (DoEngine::InputManager::get_Instance()->isKeyDown(VK_RBUTTON))
	{
		int tmp_x = 0;
		int tmp_y = 0;
		Flag_Check = false;
		Flag_InputCheck = true;

		//���콺 ����Ʈ �� ��������
		m_Rclick = DoEngine::InputManager::get_Instance()->get_MousePoint();
		//���콺 ����Ʈ�� ��ȯ
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

			//���� ������ ���� ����� �ִ��� �˻�
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

			//���ٸ� ��� ����
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
	//������ ������ �� �ð��� ���
	Cur_Sec += _fETime;

	//60�ʰ� ������ 1�� ����
	if (Cur_Sec > TIME_MAX)
	{
		Cur_Min++;
		Cur_Sec = 0;
	}

	//Endȭ������ �Ѿ
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

//Draw�Լ�(Override)
void GameScene::Draw(HDC hdc)
{
	//���ȭ���� �׸���.
	m_pBackDC->Draw(0, 0);
	//Ǯ���� ������ �׸���
	All_Draw();
	//Ǯ�� �׸���
	Draw_FullBlock();

	//��� �׸���
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

	//�ð� ǥ��
	wsprintf(tmp_Time, "%d : %d", (int)Cur_Min, (int)Cur_Sec);
	DoEngine::UIManager::get_Instance()->AddText(tmp_Time, 168, 474, 23, 255, 255, 255, TRANSPARENT, "���� ���");
	wsprintf(tmp_Count, "%d", Mine_Count);
	DoEngine::UIManager::get_Instance()->AddText(tmp_Count, 670, 474, 23, 255, 255, 255, TRANSPARENT, "���� ���");
}

//���� �׸���
void GameScene::Draw_Number(int _x, int _y)
{
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == ONE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[ONE_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == TWO_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[TWO_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == THREE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[THREE_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == FOUR_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[FOUR_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == FIVE_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[FIVE_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == SIX_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[SIX_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == SEVEN_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[SEVEN_BLOCK]);
	}
	//���� �� �׸���
	if (GameManager::get_Instance()->get_UnitPos(_x, _y) == EIGHT_BLOCK)
	{
		Draw_Block(_x, _y, m_vBlock[EIGHT_BLOCK]);
	}
}

//��� �� �׸���
void GameScene::All_Draw()
{
	/*
	MineSize 26 * 26
	*/
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			//��� �׸���
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

			//���� �׸���
			if (GameManager::get_Instance()->get_UnitPos(i, j) == MINE_BLOCK)
			{
				//���� ���
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

//Ǯ�� �׸���
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

//��ó ���ڰ� ���ö����� �����
void GameScene::Draw_Remove(int This_X, int This_Y)
{
	//������ �ʾȿ����� �ν�
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

//�� �׸���
void GameScene::Draw_Block(int _x, int _y, DoEngine::BitMap* _bmp)
{
	_bmp->Draw((_x * STAND_WH) + BLOCKSTART_X, (_y * STAND_WH) + BLOCKSTART_Y);
}

//��Ʈ �� �׸��� 
void GameScene::Hint_Block(float _fETime)
{
	Hint_Num = GameManager::get_Instance()->get_NumTrigger();

	if (Hint_Num != 0)
	{
		for (int i = 0; i < MINE_WIDTH; i++)
		{
			for (int j = 0; j < MINE_HEIGHT; j++)
			{
				//���� �� �׸���
				if (GameManager::get_Instance()->get_UnitPos(i, j) == Hint_Num)
				{
					Draw_Block(i, j, m_vBlock[Hint_Num]);
				}
			}
		}
	}
}

//Release()�Լ� (override)
void GameScene::Release()
{
	m_vBlock.clear();
	m_DelClick.clear();
	m_vMines.clear();
	m_vFlags.clear();
}

//�Ҹ���
GameScene::~GameScene()
{
	Release();
}