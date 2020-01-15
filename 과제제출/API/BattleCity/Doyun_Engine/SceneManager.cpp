#include "SceneManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "ResourcesManager.h"
#include "UIManager.h"
#include "TimeManager.h"

namespace DoEngine
{
	SceneManager* SceneManager::s_this = NULL;

	//생성자
	SceneManager::SceneManager()
	{
		//Init 여부 false로 초기화
		m_bInit = false;
	}

	void SceneManager::Init(HWND hWnd, int win_cx, int win_cy)
	{
		m_hWnd = hWnd;
		m_iWinCX = win_cx;
		m_iWinCY = win_cy;

		::RECT rcClient, rcWindow;
		GetClientRect(hWnd, &rcClient); //윈도우 화면 좌쵸값으로 위치정보를 반환
		GetWindowRect(hWnd, &rcWindow); //윈도우 클라이언트 영역사에서의 좌표값 반환

		int CXFrame = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		int CYFrame = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		MoveWindow(hWnd, 0, 0, win_cx + CXFrame, win_cy + CYFrame, true); //윈도우의 위치와 크기를 동시에 변경

		HDC hdc = GetDC(m_hWnd);

		//윈도우 크기에 맞추어서 BackDC를 생성(더블 버퍼링)
		DoEngine::ResourcesManager::get_Instance()->InitBack(hdc, m_iWinCX, m_iWinCY);
		DoEngine::InputManager::get_Instance()->Init(hWnd); //hWnd를 받아온다

		//데이터 삭제
		ReleaseDC(m_hWnd, hdc);

		//현재 씬은 은 0번째(시작화면)으로 고정 첫번째는 TitleScene
		m_curScene = m_vecScene[0];

		m_curScene->Init(m_hWnd);
	}

	//씬 등록하기
	void SceneManager::RegistScene(Scene* Reg)
	{
		m_vecScene.push_back(Reg);
	}

	//지속적으로 갱신하는 Update함수
	bool SceneManager::Update()
	{
		if (!DoEngine::TimeManager::get_Instance()->Update())
		{
			return false;
		}

		//InputManager 갱신, 키의 상태값을 계속 참조한다.
		DoEngine::InputManager::get_Instance()->Update();
		//UIManager 갱신, UI의 상태값을 계속 참조 한다.
		DoEngine::UIManager::get_Instance()->Update();

		//현재 시간을 입력받아 현재 씬의 키입력을 관리한다.
		if (m_curScene->Input(DoEngine::TimeManager::get_Instance()->get_ElipseTime()))
		{
			return true;
		}

		//현재 Scene이므로 TitleScene로 이동, TileScene의 상태값을 계속 참조한다
		m_curScene->Update(DoEngine::TimeManager::get_Instance()->get_ElipseTime());

		HDC hdc = GetDC(m_hWnd);
		//h_MemDC의 모든 그림은 hdc에 그린다
		DoEngine::ResourcesManager::get_Instance()->DrawBack(hdc);
		m_curScene->Draw(hdc);
		DoEngine::UIManager::get_Instance()->Draw();
		ReleaseDC(m_hWnd, hdc);

		return false;
	}

	//Scene에 저장된 데이터 삭제
	void SceneManager::Release()
	{
		for (auto iter = m_vecScene.begin(); iter != m_vecScene.end();)
		{
			Scene* pDelete = *iter;
			pDelete->Release(); //데이터 삭제
			iter++;
			SAFE_DELETE(pDelete);
		}

		SAFE_DELETE(s_this);
	}

	//씬 불러오기
	void SceneManager::LoadScene(int _sceneindex)
	{
		//UI를 삭제한다.
		UIManager::get_Instance()->ReleaseUI();
		m_lastScene = m_curScene; //현재씬을 이전 씬에 담는다.
		m_curScene = m_vecScene[_sceneindex]; //벡터에 담긴 씬을 현재씬에 담는다

		m_lastScene->Release(); //이전씬을 삭제한다
		m_curScene->Init(m_hWnd); //현재 씬을 초기화한다.
	}

	//소멸자
	SceneManager::~SceneManager()
	{

	}
}