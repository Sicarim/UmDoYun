#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class Node
	{
	private:
		Node* m_Parent; //노드의 부모
		list<Node*> m_Neighbors; //노드가 가지고 있는 이웃들
		int pos_x, pos_y; //각각의 노드 좌표
		int Node_Data; //노드의 번호
		
	public:
		Node(); //생성자

		void set_NodeData(int _num); //노드 번호 삽입
		void set_NodeXY(int _x, int _y); //노드 좌표 삽입
		void set_Neighbor(Node* _node); //이웃 추가
		void set_Parent(Node* _parent); //노드의 부모, 즉 자신과 이어지는 전 노드

		int get_NodeData(); //노트 번호 리턴
		list<Node*> get_Neighbors(); //이웃들을 리턴
		int get_NodeX(); //노드 좌표 삽입(x)
		int get_NodeY(); //노드 좌표 리턴(y)
		Node* get_Parent(); //부모 노드 리턴

		bool get_equals(Node* _node); //노드가 같은가
		
		~Node(); //소멸자
	};
}