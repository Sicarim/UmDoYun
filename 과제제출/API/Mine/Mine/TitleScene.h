#pragma once
#include "GlobalDefine.h"
#include "DoEngine.h"
#include "defines.h" //�������� ��Ƴ�

/*
* @brief ���� ����ȭ��(����)
* @details ���ӿ� ���� �������� �ʱ�ȭ(Ű ���, Ű ��ɾ�)���� �����Ѵ�
*/

//������ Scene�� ��� �޴� TitleScene
class TitleScene : public DoEngine::Scene
{
private:
	DoEngine::BitMap* m_pBack; //BackDC ��Ʈ�� ���

	float m_fTitleX; //Ÿ��Ʋ ũ��(x)
	float m_fTitleY; //Ÿ��Ʋ ũ��(y)

	std::function<bool()> clickEvent; //Ŭ�� �̺�Ʈ

public:
	TitleScene(); //������

	virtual void Init(HWND hWnd); //�ʱ�ȭ �Լ�(override)
	virtual bool Input(float _fETime); //�� Ű�� �´� ��ɾ� �Է�(override)
	virtual void Update(float _fETime); //Update �Լ�(override)
	virtual void Draw(HDC hdc); //�׸��� �Լ�(override)
	virtual void Release(); //���� �Լ�. DC�� BitMap�� �ƴ� ���� ������ ������� �����ų� �����ϴ� �Լ�(�����Ұ�....)(overrride)
	bool OnClick(); //Ŭ���ϸ� true�� ����(override)

	virtual ~TitleScene(); //�Ҹ���
};

