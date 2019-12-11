#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	* @brief ���ӿ� ���Ǵ� Scene���� �θ� Ŭ����
	* @details ���ӿ� ���Ǵ� Scene���� �θ� Ŭ����(�߿�!!!).Scene�����ؾ� �ϴ� �׸��� ���� ���� �Լ��� ������ ����
	*/

	class Scene
	{
	public:
		Scene(); //������

		virtual void Init(HWND hWnd) = 0; //�ʱ�ȭ
		virtual bool Input(float _fETime) = 0; //Ű�Է�
		virtual void Update(float _fETime) = 0; //Update�Լ�
		virtual void Draw(HDC hdc) = 0; //Draw �Լ�
		virtual void Release() = 0; //Release() �Լ�

		virtual ~Scene(); //�Ҹ���
	};
}

