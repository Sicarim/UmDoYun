#pragma once
#include "DoEngine.h"
#include "Node.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class Astar
	{
	private:
		queue<Node> Open_List;
		list<Node> Closed_List;
		hash_map<Node, int> gMaps;
		hash_map<Node, int> fMaps;
		int DistanceBetweenNodes;

	public:
		Astar(); //������

		void Serch(Node _start, Node _end); //���� ª�� �� ã��
		void Heuristic(); //�޸���ƽ ������ ���
		void PrintPath(Node _node); //ª�� �� ã��
		void Clear_Queue(queue<Node>& _q); //ť�� ����.

		~Astar(); //�Ҹ���
	};
}