#pragma once
#include "DoEngine.h"
#include "Node.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class NodeManager : public Singleton<NodeManager>
	{
	private:
		vector<DoEngine::Node*> m_vNode; //��� ����ü
		Node* tmp_Node; //Node�� ���� �ӽ� ���
	public:
		NodeManager(); //������

		void Init_Nodes(int _x = 0, int _y = 0, int _data = 0); //��� �ʱ�ȭ
		void add_Neighbors(); //�̿� �߰�

		~NodeManager(); //�Ҹ���
	};
}