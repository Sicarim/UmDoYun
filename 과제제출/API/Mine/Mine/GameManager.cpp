#include "GameManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "EndScene.h"

//생성자
GameManager::GameManager()
{
	srand(time(NULL));
}

//게임 Scene등록
void GameManager::All_Regist()
{
	DoEngine::SceneManager::get_Instance()->RegistScene(new TitleScene);
	DoEngine::SceneManager::get_Instance()->RegistScene(new GameScene);
	DoEngine::SceneManager::get_Instance()->RegistScene(new EndScene);
}

//모든 키 등록
void GameManager::Key_Init()
{
	//일단 모든 키를 비운다.
	DoEngine::InputManager::get_Instance()->Clear();
	//Start 버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_S);
	//ReStart 버튼 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(BUTTON_X);
	//ESC 버튼(종료) 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_ESCAPE);
	//마우스 좌클릭 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_LBUTTON);
	//마우스 우클릭 등록
	DoEngine::InputManager::get_Instance()->RegistKeyCode(VK_RBUTTON);
}

//맵 배열 선언
void GameManager::Init()
{
	m_MineX = 0; //Mine X좌표 초기화
	m_MineY = 0; //Mine Y좌표 초기화
	GameResult = 0;

	//위치 선언
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		vector<int> Element;
		Element.resize(MINE_HEIGHT);
		m_MinePos.push_back(Element);
	}

	//0으로 초기화 시킨다
	for (int i = 0; i < MINE_WIDTH; i++)
	{
		for (int j = 0; j < MINE_HEIGHT; j++)
		{
			m_MinePos[i][j] = EMPTY_BLOCK;
		}
	}

	//지뢰 심기
	for (int i = 0; i < MAX_MINE; i++)
	{
		m_MineX = rand() % MINE_WIDTH; //총 40(가로 크기)까지 랜덤을 돌린다.
		m_MineY = rand() % MINE_HEIGHT; //총 17(세로 크기)까지 랜덤을 돌린다.
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

//근처 지뢰의 갯수를 나타낸다
int GameManager::Find_Mine(int _thisx, int _thisy)
{
	int Mine_Count = 0;

	//왼쪽
	if (_thisx - 1 >= 0 && m_MinePos[_thisx - 1][_thisy] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//오른쪽
	if (_thisx + 1 < MINE_WIDTH && m_MinePos[_thisx + 1][_thisy] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//위
	if (_thisy - 1 >= 0 && m_MinePos[_thisx][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//아래
	if (_thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//왼쪽 위
	if (_thisx - 1 >= 0 && _thisy - 1 >= 0 && m_MinePos[_thisx - 1][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//오른쪽 위
	if (_thisx + 1 < MINE_WIDTH && _thisy - 1 >= 0 && m_MinePos[_thisx + 1][_thisy - 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//왼쪽 아래
	if (_thisx - 1 >= 0 && _thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx - 1][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}
	//오른쪽 아래
	if (_thisx + 1 < MINE_WIDTH && _thisy + 1 < MINE_HEIGHT && m_MinePos[_thisx + 1][_thisy + 1] == MINE_BLOCK)
	{
		Mine_Count++;
	}

	return Mine_Count;
}

//Unit위치 리턴
int GameManager::get_UnitPos(int _posx, int _posy)
{
	if ((_posx >= 0 && _posx < MINE_WIDTH) && (_posy >= 0 && _posy < MINE_HEIGHT))
	{
		return m_MinePos[_posx][_posy];
	}
}

//행렬의 위치를 반환(x)
int GameManager::get_UnitX(int _tmp)
{
	return (_tmp - BLOCKSTART_X) / STAND_WH;
}

//행렬의 위치를 반환(y)
int GameManager::get_UnitY(int _tmp)
{
	return (_tmp - BLOCKSTART_Y) / STAND_WH;
}

//게임 결과 가져오기
void GameManager::set_GameResult(int _result)
{
	GameResult = _result;
}

//게임 결과 리턴
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

//소멸자
GameManager::~GameManager()
{

}