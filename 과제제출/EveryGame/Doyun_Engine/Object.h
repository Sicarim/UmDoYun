#pragma once
#include "GlobalDefine.h"
#include "ResourcesManager.h"

namespace DoEngine
{
	/*
	* @brief ���ӿ� ���Ǵ� UnitObject���� �θ� Ŭ����
	* @details ���ӿ� ���Ǵ� Unit���� �θ� Ŭ����(�߿�!!!).�����ؾ� �ϴ� �׸��� ���� ���� �Լ��� ������
		���� - ���� �ʿ��� �޼���鸸 ��Ƶξ���. ������ Composition�ؼ� ����ϱ� �ٶ���. - ������Ʈ ������ �� Ȱ���϶�.
	*/
	class Object
	{
	protected:
		string m_sTag; //�±�(Key, ���� ���� �� ���)
		string m_sName; //�̸�
		vector<string> vec_Trait; //Ư������
	public:
		Object(); //������

		virtual void Init(int _x = 0, int _y = 0) = 0; //�ʱ�ȭ(���� ��ġ �ʱ�ȭ ����)
		virtual bool Input(int _state) = 0; //Ű�Է�
		virtual void Update(float _fETime) = 0; //Update�Լ�
		virtual void Draw() = 0; //Draw �Լ�(overloding)
		virtual void Draw(int _x, int _y) = 0; //Draw �Լ�
		virtual void Release() = 0; //Release() �Լ�

		virtual void set_Info(string _tag);//�±׿� �̸� �Է�
		string get_Name();//�±׿� �̸� �Է�
		string get_Tag();//�±׿� �̸� �Է�

		virtual ~Object(); //�Ҹ���
	};
}