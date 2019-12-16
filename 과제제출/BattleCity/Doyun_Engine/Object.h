#pragma once
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
	* @brief ���ӿ� ���Ǵ� UnitObject���� �θ� Ŭ����
	* @details ���ӿ� ���Ǵ� Unit���� �θ� Ŭ����(�߿�!!!).Scene�����ؾ� �ϴ� �׸��� ���� ���� �Լ��� ������
		����
	*/
	class Object
	{
	protected:
		string m_sTag; //�±�(Key, ���� ���� �� ���)
		string m_sName; //�̸�
		vector<string> vec_Trait; //Ư������
	public:
		Object(); //������

		virtual void Init() = 0; //�ʱ�ȭ
		virtual bool Input(float _fETime) = 0; //Ű�Է�
		virtual void Update(float _fETime) = 0; //Update�Լ�
		virtual void Draw() = 0; //Draw �Լ�(overloding)
		virtual void Draw(int _x, int _y) = 0; //Draw �Լ�
		virtual void Release() = 0; //Release() �Լ�

		void set_Info(string _tag, string _name);//�±׿� �̸� �Է�
		string get_Name();//�±׿� �̸� �Է�
		string get_Tag();//�±׿� �̸� �Է�

		virtual ~Object(); //�Ҹ���
	};
}