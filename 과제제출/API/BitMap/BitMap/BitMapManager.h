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

	//초기화
	void Init(HWND hWnd, HINSTANCE _hInst);

	BitMapManager(); //생성자
	~BitMapManager(); //소멸자

	inline vector<BitMap> get_Bit()
	{
		return m_Bit;
	}
};