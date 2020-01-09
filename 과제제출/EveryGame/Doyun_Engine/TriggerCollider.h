#pragma once
#pragma once
#include "GlobalDefine.h"
#include "POINT.h"

namespace DoEngine
{
	/**
	* @brief Trigger�� �����ϴ� Collider
	* @details Trigger�� �����Ѵ�. Collider��ü�� ����� ���ÿ� �ʱ�ȭ�� �ϰ� �Ǹ� ColliderManager�� Collider�� ��ϵȴ�. ���� �ݵ�� �±� ������ �ʼ�
	*/

	class TriggerCollider
	{
	private:
		TCHAR buf[255];
		RECT m_Rect;
		RECT tmp_Rect;
		string m_Tag;
		int HitState;
		int Hit_dir;
		bool isHitCheck, isBeforeHit, isDelete;
		int m_left, m_top, m_right, m_bottom;

		//�׸��� �׸� �귯��
		HPEN m_Collider;
		HPEN m_oldCollider;

		HBRUSH brush_Collider;
		HBRUSH brush_oldCollider;

	public:
		TriggerCollider(); //������

		void Init_Collider(string _tag, int _left, int _top, int _right, int _bottom, int _leftsize, int _topsize); //�ݶ��̴� ���� ����
		bool Draw_Collider(string _tag); //�ݶ��̴� ���� �׸���
		RECT get_Collider(string _tag); //�ݶ��̴� ���� ����

		int isCollider(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollider(vector<string> _tags); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollider(string _tag, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		bool isCollider(vector<string> _tags, int _state); //�ݶ��̴��� �浹 ���� �׸���(�ۿ��� ���� �ε�ĥ��)(overloading)
		int HitDir_Check(RECT _rc); //��� ���⿡�� �⵿�ߴ°�??
		void DeleteCollider(); //�ݶ��̴� �����ϱ�

		bool isInCollider(string _tag); //�ݶ��̴��� �浹 ���� �׸���(�ȿ��� ������ ���ϰ� �Ҷ�)

		int get_HitDir(); //�浹 ���� ����

		~TriggerCollider(); //�Ҹ���
	};
}