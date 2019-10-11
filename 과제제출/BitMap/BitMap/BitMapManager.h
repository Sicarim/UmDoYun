#pragma once
#include "Mecro.h"
#include "BitMap.h"
#include "resource.h"

class BitMapManager
{
private:
	static BitMapManager* m_hInstence;
	vector<BitMap> m_Bit;

public:
	static BitMapManager* get_Instence()
	{
		if (m_hInstence == NULL)
		{
			m_hInstence = new BitMapManager();
		}
		return m_hInstence;
	}

	void del_Instence()
	{
		if(m_hInstence != NULL)
		{
			delete m_hInstence;
		}
		m_hInstence = NULL;
	}

	//�ʱ�ȭ
	void Init(HWND hWnd, HINSTANCE _hInst);

	BitMapManager(); //������
	~BitMapManager(); //�Ҹ���

	inline vector<BitMap> get_Bit()
	{
		return m_Bit;
	}
};