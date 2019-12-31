#pragma once
#include "DoEngine.h"
#include "Node.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class AStar
	{
	private:
		list<Node*> Open_List;
		list<Node*> Closed_List;
		hash_map<Node*, int> gMaps;
		hash_map<Node*, int> fMaps;
		int DistanceBetweenNodes;

	public:
		AStar(); //������

		void Serch(Node* _start, Node* _end); //���� ª�� �� ã��
		int Heuristic(Node* _node, Node* _goal); //�޸���ƽ ������ ���
		void PrintPath(Node* _node); //ª�� �� ã��
		void Clear_Queue(queue<Node*> _q); //ť�� ����.

		~AStar(); //�Ҹ���
	};
}