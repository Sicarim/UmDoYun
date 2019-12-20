#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/**
	* 12/19 �߰�
	* @brief Collider�� �����ϴ� Manager
	* @details �ݶ��̴��� �����ϸ� �ڵ������� �迭�� �����. ������ ���� �±׸� ���� �迭�� �����Ѵٸ� �߰��� �ϰ�, ���ٸ� ���� ���� �߰��� �Ѵ�.
	*/

	class ColliderManager : public Singleton<ColliderManager>
	{
	private:
		map<string, RECT> m_mapCollider; //�Ϸ��� �±׸� ���� RECT(�ݶ��̴�)�� ����

	public:
		ColliderManager(); //������

		void Insert_Collider(string _tag, RECT _rect); //�ݶ��̴� �ֱ�
		RECT Search_Collider(std::string _tag); //�ݶ��̴� �˻��ϱ�

		~ColliderManager(); //�Ҹ���
	};
}