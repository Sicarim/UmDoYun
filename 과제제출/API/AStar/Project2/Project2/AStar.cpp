#include "AStar.h"

//생성자
AStar::AStar()
{
	DistanceBetweenNodes = 1;
}

//가장 짧은 길 찾기
void AStar::Serch(Node* _start, Node* _end)
{
	Open_List.clear(); //Open_List를 비운다.
	Closed_List.clear(); //Closed_List를 비운다.

	gMaps.insert(hash_map<Node*, int>::value_type(_start, 0)); //HashMap에 시작점을 0으로 삽입

	//Open_List.push(_start); //Open_List에 시작점을 삽입.
	Open_List.push_back(_start); //Open_List에 시작점을 삽입.

	////Open_List가 비어있지 않다면
	while (!Open_List.empty())
	{
		Node* Current_Node = Open_List.front(); //Open_List의 제일 첫 노드를 반환

		//만약 골 지점과 같다면 리턴
		if (Current_Node->get_equals(_end))
		{
			PrintPath(Current_Node);
			return;
		}

		Closed_List.push_back(Open_List.front()); //Open_List의 맨 앞의 노드를 Closed_List에 추가
		Open_List.pop_front(); //맨앞 노드를 삭제

		list<Node*> tmp_Neighbors = Current_Node->get_Neighbors();
		list<Node*>::iterator Neighbor_iter;

		for (Neighbor_iter = tmp_Neighbors.begin(); Neighbor_iter != tmp_Neighbors.end(); Neighbor_iter++)
		{
			Node* Neighbor = *Neighbor_iter;
			hash_map<Node*, int>::iterator Current_find = gMaps.find(Current_Node);
			hash_map<Node*, int>::iterator gMaps_find = gMaps.find(Neighbor); //gMaps에서 Neighbor찾기
			hash_map<Node*, int>::iterator fMaps_find = fMaps.find(Neighbor); //fMaps에서 Neighbor찾기

			list<Node*>::iterator Closed_iter; //Closed_List Serch를 위한 iterator
			list<Node*>::iterator Open_iter; //Open_List Serch를 위한 iterator

			int gScore = Current_find->second + DistanceBetweenNodes;
			int fScore = gScore + Heuristic(Neighbor, Current_Node); //휴리스틱 추정값 계산
			
			//Closed_List에 Neighbor이 있는지 검사
			Closed_iter = find(Closed_List.begin(), Closed_List.end(), Neighbor);
			//Open_List에 Neighbor이 있는지 검사
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

//휴리스틱 추정값 계산
int AStar::Heuristic(Node* _node, Node* _goal)
{
	int x = _node->get_NodeX() - _goal->get_NodeX();
	int y = _node->get_NodeY() - _goal->get_NodeY();

	return x * x + y * y;
}

//가장 짧은 길을 출력
void AStar::PrintPath(Node* _node)
{
	cout << _node->get_NodeData() << endl;

	while (_node->get_Parent() != NULL) 
	{
		_node = _node->get_Parent();
		cout << _node->get_NodeData() << endl; //경로를 출력
	}
}

//큐를 비운다.
void AStar::Clear_Queue(queue<Node*> _q)
{
	queue<Node*> empty;
	swap(_q, empty);
}

//소멸자
AStar::~AStar()
{

}