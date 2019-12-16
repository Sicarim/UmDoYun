#pragma once
#include "GlobalDefine.h"

/**
* @Made By Doyun
* ���� �� �� �ִ�! ���� ����!
*/

/**
* @namespace JEngine
* @brief JEngine ���� �����̽�
* @details �̸� �浹�� ���ϱ� ���Ͽ� ���� DoyunEngine�� namespace�Դϴ�.
*/
namespace DoEngine
{
	/**
	* @brief ������ Main�� �����ϴ� Ŭ����
	* @details ������ Main���� �����ϴ� Ŭ���� ������ ������ Ÿ��Ʋ������� ����Ѵ�.
	* @date 2019-11-10
	* @version 0.0.2
	*/

	class EngineMain
	{
	private:
		string m_strTitle; //���� Ÿ��Ʋ
		int m_winSizeX; //������ ������ x
		int m_winSizeY; //������ ������ y
		int Menu;

	public:
		EngineMain(); //default
		EngineMain(string _title, int _cx, int _cy);//������ 

		int StartEngine(HINSTANCE hInstance); //���� ����
		//�Ҹ���
		~EngineMain();
	};
}

