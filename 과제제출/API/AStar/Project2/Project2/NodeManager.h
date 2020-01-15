#pragma once
#include "defines.h"
#include "Node.h"

class NodeManager
{
private:
	vector<Node*> m_vNode; //��� ����ü
	Node* tmp_Node; //Node�� ���� �ӽ� ���

public:
	NodeManager(); //������

	void Init_Nodes(int _x = 0, int _y = 0, int _data = 0); //��� �ʱ�ȭ
	void add_Neighbors(); //�̿� �߰�

	~NodeManager(); //�Ҹ���
};
