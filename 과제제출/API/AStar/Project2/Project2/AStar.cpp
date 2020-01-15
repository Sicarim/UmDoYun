#include "AStar.h"

//������
AStar::AStar()
{
	DistanceBetweenNodes = 1;
}

//���� ª�� �� ã��
void AStar::Serch(Node* _start, Node* _end)
{
	Open_List.clear(); //Open_List�� ����.
	Closed_List.clear(); //Closed_List�� ����.

	gMaps.insert(hash_map<Node*, int>::value_type(_start, 0)); //HashMap�� �������� 0���� ����

	//Open_List.push(_start); //Open_List�� �������� ����.
	Open_List.push_back(_start); //Open_List�� �������� ����.

	////Open_List�� ������� �ʴٸ�
	while (!Open_List.empty())
	{
		Node* Current_Node = Open_List.front(); //Open_List�� ���� ù ��带 ��ȯ

		//���� �� ������ ���ٸ� ����
		if (Current_Node->get_equals(_end))
		{
			PrintPath(Current_Node);
			return;
		}

		Closed_List.push_back(Open_List.front()); //Open_List�� �� ���� ��带 Closed_List�� �߰�
		Open_List.pop_front(); //�Ǿ� ��带 ����

		list<Node*> tmp_Neighbors = Current_Node->get_Neighbors();
		list<Node*>::iterator Neighbor_iter;

		for (Neighbor_iter = tmp_Neighbors.begin(); Neighbor_iter != tmp_Neighbors.end(); Neighbor_iter++)
		{
			Node* Neighbor = *Neighbor_iter;
			hash_map<Node*, int>::iterator Current_find = gMaps.find(Current_Node);
			hash_map<Node*, int>::iterator gMaps_find = gMaps.find(Neighbor); //gMaps���� Neighborã��
			hash_map<Node*, int>::iterator fMaps_find = fMaps.find(Neighbor); //fMaps���� Neighborã��

			list<Node*>::iterator Closed_iter; //Closed_List Serch�� ���� iterator
			list<Node*>::iterator Open_iter; //Open_List Serch�� ���� iterator

			int gScore = Current_find->second + DistanceBetweenNodes;
			int fScore = gScore + Heuristic(Neighbor, Current_Node); //�޸���ƽ ������ ���
			
			//Closed_List�� Neighbor�� �ִ��� �˻�
			Closed_iter = find(Closed_List.begin(), Closed_List.end(), Neighbor);
			//Open_List�� Neighbor�� �ִ��� �˻�
			Open_iter = find(Open_List.begin(), Open_List.end(), Neighbor);

			if (Closed_iter != Closed_List.end())
			{
				if (gMaps_find->second == NULL)
				{
					gMaps.insert(hash_map<Node*, int>::value_type(Neighbor, gScore));
				}
				if (fMaps_find == fMaps.end())
				{
					fMaps.insert(hash_map<Node*, int>::value_type(Neighbor, fScore));
				}
				if (fScore >= gMaps_find->second)
				{
					continue;
				}
			}

			if (Open_iter == Open_List.end() || fScore < fMaps_find->second)
			{
				Neighbor->set_Parent(Current_Node);
				gMaps.insert(hash_map<Node*, int>::value_type(Neighbor, gScore));
				fMaps.insert(hash_map<Node*, int>::value_type(Neighbor, fScore));

				if (Open_iter == Open_List.end())
				{
					Open_List.push_back(Neighbor);
				}
			}
		}
	}
	cout << "Fail....." << endl;
}

//�޸���ƽ ������ ���
int AStar::Heuristic(Node* _node, Node* _goal)
{
	int x = _node->get_NodeX() - _goal->get_NodeX();
	int y = _node->get_NodeY() - _goal->get_NodeY();

	return x * x + y * y;
}

//���� ª�� ���� ���
void AStar::PrintPath(Node* _node)
{
	cout << _node->get_NodeData() << endl;

	while (_node->get_Parent() != NULL) 
	{
		_node = _node->get_Parent();
		cout << _node->get_NodeData() << endl; //��θ� ���
	}
}

//ť�� ����.
void AStar::Clear_Queue(queue<Node*> _q)
{
	queue<Node*> empty;
	swap(_q, empty);
}

//�Ҹ���
AStar::~AStar()
{

}