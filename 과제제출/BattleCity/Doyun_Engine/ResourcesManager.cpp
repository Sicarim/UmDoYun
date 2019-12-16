#include "ResourcesManager.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	//생성자
	ResourcesManager::ResourcesManager()
	{
	}

	//Resource에 BackDC를 그린다
	void ResourcesManager::InitBack(HDC hdc, int cx, int cy)
	{
		m_pBack = new DoEngine::BitMap();
		m_pBack->InitBack(hdc, cx, cy);
	}

	//Resoureces에 해당 그림을 그린다
	DoEngine::BitMap* ResourcesManager::InitBitmap(std::string strFileName)
	{
		//파일 이름을 찾는다
		auto iter = m_mapBitmap.find(strFileName);

		if (iter == m_mapBitmap.end())
		{
			//찾지 못하면 비트맵을 새로 생성 후, map형식으로 이루어진 자료구조에 추가한다.
			DoEngine::BitMap* pBitmap = new DoEngine::BitMap();
			pBitmap->Init(m_pBack->GetDC(), strFileName);

			m_mapBitmap.insert(make_pair(strFileName, pBitmap));
			return pBitmap;
		}
		else
		{
			return iter->second;
		}
	}

	HDC ResourcesManager::get_BackDC()
	{
		return m_pBack->GetDC();
	}

	void ResourcesManager::DrawBack(HDC hdc)
	{
		m_pBack->DrawBack(hdc);
	}

	//vector에서 같은 이름을 가진 bmp파일을 찾는다. 없다면 새로 만든다
	DoEngine::BitMap* ResourcesManager::get_Bitmap(std::string strFileName)
	{
		auto iter = m_mapBitmap.find(strFileName);

		if (iter != m_mapBitmap.end())
		{
			return iter->second;
		}
		else
		{
			return InitBitmap(strFileName);
		}
	}

	//소멸자
	ResourcesManager::~ResourcesManager()
	{
		SAFE_DELETE(m_pBack);

		for (auto iter = m_mapBitmap.begin(); iter != m_mapBitmap.end(); iter++)
		{
			auto del = (*iter).second;
			SAFE_DELETE(del);
		}
	}
}

