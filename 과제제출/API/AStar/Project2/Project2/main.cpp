#include "defines.h"
#include "Node.h"
#include "AStar.h"

int main()
{
	vector<Node*> m_vNode;
	AStar m_star;

	for (int i = 0; i < 10; i++)
	{
		Node* tmp_Node = new Node;
		m_vNode.push_back(tmp_Node);
	}

	m_vNode[0]->set_NodeXY(0, 0);
	m_vNode[0]->set_NodeData(0);

	m_vNode[1]->set_NodeXY(0, 1);
	m_vNode[1]->set_NodeData(1);

	m_vNode[2]->set_NodeXY(0, 2);
	m_vNode[2]->set_NodeData(2);

	m_vNode[3]->set_NodeXY(1, 0);
	m_vNode[3]->set_NodeData(3);

	m_vNode[4]->set_NodeXY(1, 2);
	m_vNode[4]->set_NodeData(4);

	m_vNode[5]->set_NodeXY(2, 0);
	m_vNode[5]->set_NodeData(5);

	m_vNode[6]->set_NodeXY(2, 1);
	m_vNode[6]->set_NodeData(6);

	m_vNode[7]->set_NodeXY(2, 2);
	m_vNode[7]->set_NodeData(7);

	m_vNode[8]->set_NodeXY(3, 0);
	m_vNode[8]->set_NodeData(8);

	m_vNode[9]->set_NodeXY(3, 2);
	m_vNode[9]->set_NodeData(9);


	m_vNode[0]->set_Neighbor(m_vNode[1]);
	m_vNode[0]->set_Neighbor(m_vNode[3]);

	m_vNode[1]->set_Neighbor(m_vNode[0]);
	m_vNode[1]->set_Neighbor(m_vNode[2]);

	m_vNode[2]->set_Neighbor(m_vNode[1]);
	m_vNode[2]->set_Neighbor(m_vNode[4]);

	m_vNode[3]->set_Neighbor(m_vNode[0]);
	m_vNode[3]->set_Neighbor(m_vNode[5]);

	m_vNode[4]->set_Neighbor(m_vNode[7]);
	m_vNode[4]->set_Neighbor(m_vNode[2]);

	m_vNode[5]->set_Neighbor(m_vNode[8]);
	m_vNode[5]->set_Neighbor(m_vNode[3]);

	m_vNode[6]->set_Neighbor(m_vNode[7]);
	m_vNode[6]->set_Neighbor(m_vNode[5]);

	m_vNode[7]->set_Neighbor(m_vNode[4]);
	m_vNode[7]->set_Neighbor(m_vNode[9]);
	m_vNode[7]->set_Neighbor(m_vNode[6]);

	m_vNode[8]->set_Neighbor(m_vNode[5]);

	m_vNode[9]->set_Neighbor(m_vNode[7]);

	m_star.Serch(m_vNode[9], m_vNode[8]);
	
	//cout << "Hello World!" << endl;

	return 0;
}