#include "ResourcesManager.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	//������
	ResourcesManager::ResourcesManager()
	{
	}

	//Resource�� BackDC�� �׸���
	void ResourcesManager::InitBack(HDC hdc, int cx, int cy)
	{
		m_pBack = new DoEngine::BitMap();
		m_pBack->InitBack(hdc, cx, cy);
	}

	//Resoureces�� �ش� �׸��� �׸���
	DoEngine::BitMap* ResourcesManager::InitBitmap(std::string strFileName)
	{
		//���� �̸��� ã�´�
		auto iter = m_mapBitmap.find(strFileName);

		if (iter == m_mapBitmap.end())
		{
			//ã�� ���ϸ� ��Ʈ���� ���� ���� ��, map�������� �̷���� �ڷᱸ���� �߰��Ѵ�.
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

	//vector���� ���� �̸��� ���� bmp������ ã�´�. ���ٸ� ���� �����
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

	//�Ҹ���
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

