#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "MapTool.h"

//생성자
TitleScene::TitleScene()
{

}

//초기화(override)
void TitleScene::Init(HWND hWnd)
{
	m_Command = NULL;
	m_vEnemy.clear();
	m_vEnemy.reserve(MAX_ENEMY);
	//키 등록
	GameManager::get_Instance()->Key_Init();
	//적 만들기
	m_vEnemy = GameManager::get_Instance()->Make_Enemy();
	//플레이어 만들기
	m_pPlayer.Init(300, 500);
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);

	//맵 만들기
	m_Map.MakeMap(W_COUNT, H_COUNT);
	//BitMap등록

	//memset(g_map, 0, sizeof(int) * 13 * 13);

	//위치 선언
	/*for (int i = 0; i < 8; i++)
	{
		vector<int> Element;
		Element.resize(4);
		m_MinePos.push_back(Element);
	}*/

	//m_MinePos.assign(10, vector<int>(20, 0));
	//m_MinePos[2][1] = 1;
}

//키입력(override)
bool TitleScene::Input(float _fETime)
{
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	m_Command = m_Input.CommandInput();

	if (m_Command)
	{
		m_Command->excute(m_pPlayer);
	}

	return false;
}

//Update함수(override)
void TitleScene::Update(float _fETime)
{
	m_pPlayer.Update(_fETime);
	m_vEnemy[1]->Update(_fETime);
}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void TitleScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
	//배경화면 그리기
	m_Map.DrawMap();

	m_vEnemy[1]->Draw();
	m_pPlayer.Draw();
	

	//for (int i = 0; i < 10; i++)
	//{ 
	//	for (int j = 0; j < 20; j++)
	//	{
	//		if (m_MinePos[i][j] == 0)
	//			//Rectangle(hdc, j * WIDTH, i * HEIGHT, (j + 1) * WIDTH, (i + 1) * HEIGHT);
	//			m_pBack->Draw(20 + j * WIDTH, 20 +i * HEIGHT);
	//		else if (m_MinePos[i][j] == 1)
	//			Ellipse(hdc, j * WIDTH, i * HEIGHT, (j + 1) * WIDTH, (i + 1) * HEIGHT);
	//		else if (g_map[i][j] == 2)
	//		{
	//			HBRUSH hBlack = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//			HBRUSH old = (HBRUSH)SelectObject(hdc, hBlack);
	//			Ellipse(hdc, j * WIDTH, i * HEIGHT, (j + 1) * WIDTH, (i + 1) * HEIGHT);
	//			SelectObject(hdc, old);
	//		}
	//	}
	//}
}

//Release() 함수(override)
void TitleScene::Release()
{

}

//소멸자
TitleScene::~TitleScene()
{

}