#include "GameManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

//������
GameManager::GameManager()
{
	srand(time(NULL));
}

//���� Scene���
void GameManager::All_Regist()
{
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	DoEngine::SceneManager::get_Instance()->RegistScene(new EndScene);
}

//��� Ű ���
void GameManager::Key_Init()
{
	//�ϴ� ��� Ű�� ����.
	DoEngine::InputManager::get_Instance()->Clear();
	//Start ��ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//ReStart ��ư ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
	//ESC ��ư(����) ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//���콺 ��Ŭ�� ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LBUTTON);
	//���콺 ��Ŭ�� ���
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RBUTTON);
}

//�� �迭 ����
void GameManager::Init()
{
	m_MineX = 0; //Mine X��ǥ �ʱ�ȭ
	m_MineY = 0; //Mine Y��ǥ �ʱ�ȭ
	GameResult = 0;

	//��ġ ����
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		vector<int> Element;
		Element.resize(MINE_HEIGHT);
		m_MinePos.push_back(Element);
	}

	//0���� �ʱ�ȭ ��Ų��
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			m_MinePos[i][j] = EMPTY_BLOCK;
		}
	}

	//���� �ɱ�
	for (int i = 0; i < MAX_MINE; i++)
	{
		m_MineX = rand() % MINE_WIDTH; //�� 40(���� ũ��)���� ������ ������.
		m_MineY = rand() % MINE_HEIGHT; //�� 17(���� ũ��)���� ������ ������.
		m_MinePos[m_MineX][m_MineY] = MINE_BLOCK;
	}

	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			if (m_MinePos[i][j] != MINE_BLOCK)
			{
				m_MinePos[i][j] = Find_Mine(i, j);
			}
		}
	}
}

//��ó ������ ������ ��Ÿ����
int GameManager::Find_Mine(int _thisx, int _thisy)
{
	int Mine_Count = 0;

	//����
	if (_thisx - 1 >= 0 && m_MinePos[_thisx - 1][_thisy] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//������
	if (_thisx + 1 < MINE_WIDTH && m_MinePos[_thisx + 1][_thisy] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//��
	if (_thisy - 1 >= 0 && m_MinePos[_thisx][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//�Ʒ�
	if (_thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//���� ��
	if (_thisx - 1 >= 0 && _thisy - 1 >= 0 && m_MinePos[_thisx - 1][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//������ ��
	if (_thisx + 1 < MINE_WIDTH && _thisy - 1 >= 0 && m_MinePos[_thisx + 1][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//���� �Ʒ�
	if (_thisx - 1 >= 0 && _thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx - 1][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//������ �Ʒ�
	if (_thisx + 1 < MINE_WIDTH && _thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx + 1][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}

	return Mine_Count;
}

//Unit��ġ ����
int GameManager::get_UnitPos(int _posx, int _posy)
{
	if ((_posx >= 0 && _posx < MINE_WIDTH) && (_posy >= 0 && _posy < MINE_HEIGHT))
	{
		return m_MinePos[_posx][_posy];
	}
}

//����� ��ġ�� ��ȯ(x)
int GameManager::get_UnitX(int _tmp)
{
	return (_tmp - BLOCKSTART_X) / STAND_WH;
}

//����� ��ġ�� ��ȯ(y)
int GameManager::get_UnitY(int _tmp)
{
	return (_tmp - BLOCKSTART_Y) / STAND_WH;
}

//���� ��� ��������
void GameManager::set_GameResult(int _result)
{
	GameResult = _result;
}

//���� ��� ����
int GameManager::get_GameResult()
{
	return GameResult;
}

bool GameManager::get_Trigger()
{
	Trigger = DoEngine::EngineMain::get_MineTrigger();

	return Trigger;
}

void GameManager::set_Trigger(bool _trg)
{
	Trigger = _trg;
	DoEngine::EngineMain::set_MineTrigger(Trigger);
}

int GameManager::get_NumTrigger()
{
	NumTrigger = DoEngine::EngineMain::get_NumTrigger();

	return NumTrigger;
}

void GameManager::set_NumTrigger(int trigger)
{
	NumTrigger = trigger;
	DoEngine::EngineMain::set_NumTrigger(NumTrigger);
}

//�Ҹ���
GameManager::~GameManager()
{

}