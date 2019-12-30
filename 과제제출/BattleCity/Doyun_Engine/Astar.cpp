#include "Astar.h"

namespace DoEngine
{
	//������
	Astar::Astar()
	{
		DistanceBetweenNodes = 1;
	}

	//���� ª�� �� ã��
	void Astar::Serch(Node _start, Node _end)
	{
		Clear_Queue(Open_List); //Open_List�� ����.
		Closed_List.clear(); //Closed_List�� ����.
		gMaps.insert(make_pair(_start, 0)); //HashMap�� �������� 0���� ����
		Open_List.push(_start); //Open_List�� �������� ����.

		//Open_List�� ������� �ʴٸ�
		while (!Open_List.empty())
		{
			Node Current_Node = Open_List.front(); //Open_List�� ���� ù ��带 ��ȯ

			//���� �� ������ ���ٸ� ����
			if (Current_Node.get_equals(_end)) 
			{
				PrintPath(Current_Node);
				return;
			}

			Closed_List.push_back(Open_List.front()); //Open_List�� �� ���� ��带 Closed_List�� �߰�
			Open_List.pop(); //�Ǿ� ��带 ����

			/*list<Node*> tmp_Neighbors = Current_Node.get_Neighbors();
			list<Node*>::iterator iter;*/

			//for (iter = tmp_Neighbors.begin(); iter != tmp_Neighbors.end(); iter++)
			//{
			//	//Node tmp_Node = iter;
			//}
		}
	}

	//�޸���ƽ ������ ���
	void Astar::Heuristic()
	{

	}

	//ª�� �� ã��
	void Astar::PrintPath(Node _node)
	{

	}

	//ť�� ����.
	void Astar::Clear_Queue(queue<Node> &_q)
	{
		queue<Node> empty;
		swap(_q, empty);
	}

	//�Ҹ���
	Astar::~Astar()
	{

	}
}