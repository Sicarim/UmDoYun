#include "Astar.h"

namespace DoEngine
{
	//생성자
	Astar::Astar()
	{
		DistanceBetweenNodes = 1;
	}

	//가장 짧은 길 찾기
	void Astar::Serch(Node _start, Node _end)
	{
		Clear_Queue(Open_List); //Open_List를 비운다.
		Closed_List.clear(); //Closed_List를 비운다.
		gMaps.insert(make_pair(_start, 0)); //HashMap에 시작점을 0으로 삽입
		Open_List.push(_start); //Open_List에 시작점을 삽입.

		//Open_List가 비어있지 않다면
		while (!Open_List.empty())
		{
			Node Current_Node = Open_List.front(); //Open_List의 제일 첫 노드를 반환

			//만약 골 지점과 같다면 리턴
			if (Current_Node.get_equals(_end)) 
			{
				PrintPath(Current_Node);
				return;
			}

			Closed_List.push_back(Open_List.front()); //Open_List의 맨 앞의 노드를 Closed_List에 추가
			Open_List.pop(); //맨앞 노드를 삭제

			/*list<Node*> tmp_Neighbors = Current_Node.get_Neighbors();
			list<Node*>::iterator iter;*/

			//for (iter = tmp_Neighbors.begin(); iter != tmp_Neighbors.end(); iter++)
			//{
			//	//Node tmp_Node = iter;
			//}
		}
	}

	//휴리스틱 추정값 계산
	void Astar::Heuristic()
	{

	}

	//짧은 길 찾기
	void Astar::PrintPath(Node _node)
	{

	}

	//큐를 비운다.
	void Astar::Clear_Queue(queue<Node> &_q)
	{
		queue<Node> empty;
		swap(_q, empty);
	}

	//소멸자
	Astar::~Astar()
	{

	}
}