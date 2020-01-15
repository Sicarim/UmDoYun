#include "StageScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"
#include "MapTool.h"

//생성자
StageScene::StageScene()
{

}

//초기화(override)
void StageScene::Init(HWND hWnd)
{
	curTime = 0.0f;
	curStage = GameManager::get_Instance()->get_NextStage();
	//검정색 배경화면 만들기
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//제목 등록
	wsprintf(buf, "%d STAGE", curStage);
	DoEngine::UIManager::get_Instance()->AddText(buf, 380, 300, 80, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//키입력(override)
bool StageScene::Input(float _fETime)
{
	//종료
	if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update함수(override)
void StageScene::Update(float _fETime)
{
	curTime += _fETime;

	if (curTime > 2.5f)
	{
		wsprintf(buf, "Map\\Stage%d.txt", curStage);
		DoEngine::MapTool::get_Instance()->Make_Stage(buf);
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}
}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void StageScene::Draw(HDC hdc)
{
	//검정 배경화면을 그린다
	m_BlackBG->Draw(0, 0);
}

//Release() 함수(override)
void StageScene::Release()
{

}

//소멸자
StageScene::~StageScene()
{

}