#include "NodeManager.h"

//������
NodeManager::NodeManager()
{

}

//��� �ʱ�ȭ
void NodeManager::Init_Nodes(int _x, int _y, int _data)
{
	tmp_Node = new Node;
	tmp_Node->set_NodeXY(_x, _y);
	tmp_Node->set_NodeData(_data);
	m_vNode.push_back(tmp_Node);
}

//�̿� �߰�
void NodeManager::add_Neighbors()
{
	int Neighbor_Count = 0;

	for (int i = 0; i < m_vNode.size(); i++)
	{
		Neighbor_Count = 0;

		for (int j = 0; j < m_vNode.size(); j++)
		{
			if (Neighbor_Count != 4)
			{
				if (m_vNode[i]->get_NodeData() != m_vNode[j]->get_NodeData())
				{
					//�� ���� ���̸� ���Ѵ�.
					int MinusValX = abs(m_vNode[i]->get_NodeX() - m_vNode[j]->get_NodeX());
					int MinusValY = abs(m_vNode[i]->get_NodeY() - m_vNode[j]->get_NodeY());

					//�ΰ��� ���� �ʴٸ�,...(�� ���� ���ٸ� �밢���� �����Ƿ� �̿��� �ƴѴ�.
					if (MinusValX < 2 && MinusValY < 2)
					{
						if (MinusValX != MinusValY)
						{
							m_vNode[i]->set_Neighbor(m_vNode[j]);
							Neighbor_Count++;
						}
					}
				}
			}
		}
	}
}

//�Ҹ���
NodeManager::~NodeManager()
{

}
