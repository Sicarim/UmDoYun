#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	/*
		@brief ������Ʈ Ǯ�� �ٷ�� ���� Ŭ���� ����
		@details �ʱ� ��ü�� �Ҵ��س���, �ʿ��Ҷ� ��������, �ʿ䰡 ���ٸ� ��ȯ�Ѵ�.
		�ʱ� �Ҵ��� �� �Ҵ��� �� ���ٸ� �׶� ���� �����.
	*/
	template <typename T>
	class ObjectPool
	{
	private:
		//Object Pool�� ����ϱ� ���� Data����
		list<T*> m_Datas;

	public:
		ObjectPool(); //������

		T* get_Data(); //Data ����
		void Return_Data(T* _data); //�� ����ߴٸ� �ڷḦ ����

		~ObjectPool(); //�Ҹ���
	};
}