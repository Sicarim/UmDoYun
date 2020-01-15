#include "Node.h"

namespace DoEngine
{
	//생성자
	Node::Node()
	{
		m_Parent = NULL;
		m_Neighbors.clear();
		pos_x = 0;
		pos_y = 0;
		Node_Data = 0;
	}

	//노드 번호 삽입
	void Node::set_NodeData(int _num)
	{
		Node_Data = _num;
	}

	//노드 좌표 삽입
	void Node::set_NodeXY(int _x, int _y)
	{
		pos_x = _x;
		pos_y = _y;
	}

	//이웃 추가
	void Node::set_Neighbor(Node* _node)
	{
		m_Neighbors.push_back(_node);
	}

	//노드의 부모, 즉 자신과 이어지는 전 노드
	void Node::set_Parent(Node* _parent)
	{
		m_Parent = _parent;
	}

	//노트 번호 리턴
	int Node::get_NodeData()
	{
		return Node_Data;
	}

	//이웃들을 리턴
	list<Node*> Node::get_Neighbors()
	{
		return m_Neighbors;
	}

	//노드 좌표 삽입(y)
	int Node::get_NodeX()
	{
		return pos_x;
	}

	//노드 좌표 리턴(x)
	int Node::get_NodeY()
	{
		return pos_y;
	}

	//부모 노드 리턴
	Node* Node::get_Parent()
	{
		return m_Parent;
	}

	//노드가 같은가
	bool Node::get_equals(Node* _node)
	{
		return pos_x == _node->get_NodeX() && pos_y == _node->get_NodeY();
	}

	//노드 찾기
	bool Node::get_NodeSerch(int _x, int _y)
	{
		return pos_x == _x && pos_y == _y;
	}

	//노드의 부모 비우기
	void Node::Release_NodeParent()
	{
		m_Parent = NULL;
	}

	//소멸자
	Node::~Node()
	{

	}
}