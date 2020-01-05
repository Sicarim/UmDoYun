#include "TitleScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "MapTool.h"

//생성자
TitleScene::TitleScene()
{
	
}

//초기화(override)
void TitleScene::Init(HWND hWnd)
{
	Select_x = 380;
	Select_y = 330;
	Select_Count = 3;

	//검정색 배경화면 만들기
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//키 등록
	GameManager::get_Instance()->Key_Init();
	//그림 그리기
	tmp_bit = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\tank_right_00.bmp");
	//제목 등록
	DoEngine::UIManager::get_Instance()->AddText("B   A   T   T   L   E", 100, 60, 120, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("C I T Y", 700, 160, 80, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("REMASTER", 720, 220, 40, 150, 75, 0, TRANSPARENT, "맑은 고딕");

	//스테이지
	DoEngine::UIManager::get_Instance()->AddText("1 S T A G E", 420, 320, 40, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("2 S T A G E", 420, 380, 40, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	//불러오기
	DoEngine::UIManager::get_Instance()->AddText("L O A D", 420, 440, 40, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	//엄콧!
	DoEngine::UIManager::get_Instance()->AddText("U M C O T", 380, 520, 60, 255, 127, 0, TRANSPARENT, "맑은 고딕");
	//만든 날짜
	DoEngine::UIManager::get_Instance()->AddText("ⓒ  2019 2020 UMCO LTD ", 240, 660, 60, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//키입력(override)
bool TitleScene::Input(float _fETime)
{
	//종료
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_UP))
	{
		if (Select_Count < 3)
		{
			Select_y -= 60;
			Select_Count++;
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_DOWN))
	{
		if (Select_Count > 1)
		{
			Select_y += 60;
			Select_Count--;
		}
	}

	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_RETURN))
	{
		//맵 만들기
		DoEngine::MapTool::get_Instance()->Init(W_COUNT, H_COUNT, "RES\\block00.bmp", COL_SIZE + 0.1f, COL_SIZE + 0.1f, NO_WALL);

		if (Select_Count == 3)
		{
			wsprintf(buf, "Map\\Stage1.txt");
			DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		}
		else if (Select_Count == 2)
		{
			wsprintf(buf, "Map\\Stage2.txt");
			DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		}
		else if (Select_Count == 1)
		{

		}
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}


	return false;
}

//Update함수(override)
void TitleScene::Update(float _fETime)
{
	
}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void TitleScene::Draw(HDC hdc)
{	
	m_BlackBG->Draw(0, 0);

	tmp_bit->Draw(Select_x, Select_y);
}

//Release() 함수(override)
void TitleScene::Release()
{

}

//소멸자
TitleScene::~TitleScene()
{

}