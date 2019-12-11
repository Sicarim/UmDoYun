#include "TitleScene.h" //TitleScene 선언
#include "InputManager.h" //InputManager(키 등록등....)선언
#include "SceneManager.h" //Scene에서 관리되기 때문에 SceneManager선언
#include "UIManager.h" //UI도 써야하니까..
#include "ResourcesManager.h" //그림도 띄워야 하니까
#include "GameManager.h"

//생성자
TitleScene::TitleScene()
{
	m_fTitleX = MAX_WITDH;
	m_fTitleY = MAX_HEIGHT;
}

//초기화 함수(override)
void TitleScene::Init(HWND hWnd)
{
	//키 등록
	GameManager::get_Instance()->Key_Init();

	//배경화면 찾기 만약 찾는 bmp파일이 없다면 새로 생성(Init)한다
	m_pBack = DoEngine::ResourcesManager::get_Instance()->get_Bitmap("RES\\back.bmp");
	//글자를 적는다
	DoEngine::UIManager::get_Instance()->AddText("Mine Serch", 370, 100, 50, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("Please Press 'S'", 360, 300, 40, 255, 255, 255, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("Made by Doyun", 400, 400, 20, 255, 255, 0, TRANSPARENT, "맑은 고딕");
	DoEngine::UIManager::get_Instance()->AddText("Using DoEngine", 420, 420, 10, 255, 255, 0, TRANSPARENT, "맑은 고딕");
}

//각 키에 맞는 명령어 입력(override)
bool TitleScene::Input(float _fETime)
{
	//S를 누르면 GameScene으로 넘어간다
	if (DoEngine::InputManager::get_Instance()->isKeyUp(BUTTON_S))
	{
		DoEngine::SceneManager::get_Instance()->LoadScene(SCENE_INDEX_GAME);
	}
	//ESC를 누르면 종료
	else if (DoEngine::InputManager::get_Instance()->isKeyUp(VK_ESCAPE))
	{
		return true;
	}

	return false;
}

//Update 함수(override)
void TitleScene::Update(float _fETime)
{

}

//그리기 함수(override)
void TitleScene::Draw(HDC hdc)
{
	//0,0에 그려라
	m_pBack->DrawBitblt(0, 0);
}

//삭제 함수. DC나 BitMap이 아닌 변수 값등을 원래대로 돌리거나 삭제하는 함수(주의할것....)(overrride)
void TitleScene::Release()
{

}

//클릭하면 true를 리턴(override)s
bool TitleScene::OnClick()
{
	return true;
}


//소멸자
TitleScene::~TitleScene()
{

}