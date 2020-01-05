#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"
#include "InputHandler.h"
#include "Node.h"
#include "defines.h"
#include "Tank.h"

//���� �����ϴ� AIManager, ���� �ൿ�� �����Ѵ�.
class AIManager : public Singleton<AIManager>
{
private:
	vector<DoEngine::Object*> m_vEnemy; //���� ����
	vector<DoEngine::Node*> m_vFast_Way;
	float ReTime;
	int Count;
	TCHAR buf[255];

	//���� ������ Ŀ�ǵ� ��ü ����
	DoEngine::Command* tmp_Command;
	vector<DoEngine::Command*> Enemy_behavior;
	DoEngine::Command* m_Command;
	InputHandler m_Input;
public:
	AIManager(); //������

	void Init(); //��ã�� �ʱ�ȭ
	bool Input(); //Ű�Է�
	void Update(float _fETime); //Update�Լ�
	void Draw(); //Draw �Լ�
	void Release(); //Release() �Լ�
	void Find_Way(); //��ã��

	~AIManager(); //�Ҹ���
};