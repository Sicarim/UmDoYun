#include "NodeManager.h"

//생성자
NodeManager::NodeManager()
{

}

//노드 초기화
void NodeManager::Init_Nodes(int _x, int _y, int _data)
{
	tmp_Node = new Node;
	tmp_Node->set_NodeXY(_x, _y);
	tmp_Node->set_NodeData(_data);
	m_vNode.push_back(tmp_Node);
}

//이웃 추가
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
					//두 값의 차이를 구한다.
					int MinusValX = abs(m_vNode[i]->get_NodeX() - m_vNode[j]->get_NodeX());
					int MinusValY = abs(m_vNode[i]->get_NodeY() - m_vNode[j]->get_NodeY());

					//두값이 같지 않다면,...(두 값이 같다면 대각선상에 있으므로 이웃이 아닌다.
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

//소멸자
NodeManager::~NodeManager()
{

}
