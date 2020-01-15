#include "SceneManager.h"
#include "Scene.h"
#include "InputManager.h"
#include "ResourcesManager.h"
#include "UIManager.h"
#include "TimeManager.h"

namespace DoEngine
{
	SceneManager* SceneManager::s_this = NULL;

	//������
	SceneManager::SceneManager()
	{
		//Init ���� false�� �ʱ�ȭ
		m_bInit = false;
	}

	void SceneManager::Init(HWND hWnd, int win_cx, int win_cy)
	{
		m_hWnd = hWnd;
		m_iWinCX = win_cx;
		m_iWinCY = win_cy;

		::RECT rcClient, rcWindow;
		GetClientRect(hWnd, &rcClient); //������ ȭ�� ���ݰ����� ��ġ������ ��ȯ
		GetWindowRect(hWnd, &rcWindow); //������ Ŭ���̾�Ʈ �����翡���� ��ǥ�� ��ȯ

		int CXFrame = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		int CYFrame = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		MoveWindow(hWnd, 0, 0, win_cx + CXFrame, win_cy + CYFrame, true); //�������� ��ġ�� ũ�⸦ ���ÿ� ����

		HDC hdc = GetDC(m_hWnd);

		//������ ũ�⿡ ���߾ BackDC�� ����(���� ���۸�)
		DoEngine::ResourcesManager::get_Instance()->InitBack(hdc, m_iWinCX, m_iWinCY);
		DoEngine::InputManager::get_Instance()->Init(hWnd); //hWnd�� �޾ƿ´�

		//������ ����
		ReleaseDC(m_hWnd, hdc);

		//���� ���� �� 0��°(����ȭ��)���� ���� ù��°�� TitleScene
		m_curScene = m_vecScene[0];

		m_curScene->Init(m_hWnd);
	}

	//�� ����ϱ�
	void SceneManager::RegistScene(Scene* Reg)
	{
		m_vecScene.push_back(Reg);
	}

	//���������� �����ϴ� Update�Լ�
	bool SceneManager::Update()
	{
		if (!DoEngine::TimeManager::get_Instance()->Update())
		{
			return false;
		}

		//InputManager ����, Ű�� ���°��� ��� �����Ѵ�.
		DoEngine::InputManager::get_Instance()->Update();
		//UIManager ����, UI�� ���°��� ��� ���� �Ѵ�.
		DoEngine::UIManager::get_Instance()->Update();

		//���� �ð��� �Է¹޾� ���� ���� Ű�Է��� �����Ѵ�.
		if (m_curScene->Input(DoEngine::TimeManager::get_Instance()->get_ElipseTime()))
		{
			return true;
		}

		//���� Scene�̹Ƿ� TitleScene�� �̵�, TileScene�� ���°��� ��� �����Ѵ�
		m_curScene->Update(DoEngine::TimeManager::get_Instance()->get_ElipseTime());

		HDC hdc = GetDC(m_hWnd);
		//h_MemDC�� ��� �׸��� hdc�� �׸���
		DoEngine::ResourcesManager::get_Instance()->DrawBack(hdc);
		m_curScene->Draw(hdc);
		DoEngine::UIManager::get_Instance()->Draw();
		ReleaseDC(m_hWnd, hdc);

		return false;
	}

	//Scene�� ����� ������ ����
	void SceneManager::Release()
	{
		for (auto iter = m_vecScene.begin(); iter != m_vecScene.end();)
		{
			Scene* pDelete = *iter;
			pDelete->Release(); //������ ����
			iter++;
			SAFE_DELETE(pDelete);
		}

		SAFE_DELETE(s_this);
	}

	//�� �ҷ�����
	void SceneManager::LoadScene(int _sceneindex)
	{
		//UI�� �����Ѵ�.
		UIManager::get_Instance()->ReleaseUI();
		m_lastScene = m_curScene; //������� ���� ���� ��´�.
		m_curScene = m_vecScene[_sceneindex]; //���Ϳ� ��� ���� ������� ��´�

		m_lastScene->Release(); //�������� �����Ѵ�
		m_curScene->Init(m_hWnd); //���� ���� �ʱ�ȭ�Ѵ�.
	}

	//�Ҹ���
	SceneManager::~SceneManager()
	{

	}
}