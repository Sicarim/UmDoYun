#include "LoseEndScene.h"
#include "GameManager.h"
#include "ResourcesManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "SceneManager.h"

//생성자
LoseEndScene::LoseEndScene()
{

}

//초기화(override)
void LoseEndScene::Init(HWND hWnd)
{
	Select_x = 380;
	Select_y = 330;
	Select_Count = 3;

	//검정색 배경화면 만들기
	m_BlackBG = DoEngine::ResourcesManager::get_Instance()->get_BackGround("BlackBG", 1024, 768);
	//You Die
	DoEngine::UIManager::get_Instance()->AddText("G   A   M   E", 100, 60, 120, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("O V E R", 700, 160, 120, 255, 255, 255, TRANSPARENT, "맑은 고딕");
}

//키입력(override)
bool LoseEndScene::Input(float _fETime)
{

	return false;
}

//Update함수(override)
void LoseEndScene::Update(float _fETime)
{

}

//블럭 갯수 24칸, 2칸 기준 12블럭
//Draw 함수(override)
void LoseEndScene::Draw(HDC hdc)
{
	m_BlackBG->Draw(0, 0);
}

//Release() 함수(override)
void LoseEndScene::Release()
{

}

//소멸자
LoseEndScene::~LoseEndScene()
{

}