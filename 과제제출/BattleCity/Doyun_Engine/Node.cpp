#include "Node.h"

namespace DoEngine
{
	//������
	Node::Node()
	{
		m_Parent = NULL;
		m_Neighbors.clear();
		pos_x = 0;
		pos_y = 0;
		Node_Data = 0;
	}

	//��� ��ȣ ����
	void Node::set_NodeData(int _num)
	{
		Node_Data = _num;
	}

	//��� ��ǥ ����
	void Node::set_NodeXY(int _x, int _y)
	{
		pos_x = _x;
		pos_y = _y;
	}

	//�̿� �߰�
	void Node::set_Neighbor(Node* _node)
	{
		m_Neighbors.push_back(_node);
	}

	//����� �θ�, �� �ڽŰ� �̾����� �� ���
	void Node::set_Parent(Node* _parent)
	{
		m_Parent = _parent;
	}

	//��Ʈ ��ȣ ����
	int Node::get_NodeData()
	{
		return Node_Data;
	}

	//�̿����� ����
	list<Node*> Node::get_Neighbors()
	{
		return m_Neighbors;
	}

	//��� ��ǥ ����(y)
	int Node::get_NodeX()
	{
		return pos_x;
	}

	//��� ��ǥ ����(x)
	int Node::get_NodeY()
	{
		return pos_y;
	}

	//�θ� ��� ����
	Node* Node::get_Parent()
	{
		return m_Parent;
	}

	//��尡 ������
	bool Node::get_equals(Node* _node)
	{
		return pos_x == _node->get_NodeX() && pos_y == _node->get_NodeY();
	}

	//��� ã��
	bool Node::get_NodeSerch(int _x, int _y)
	{
		return pos_x == _x && pos_y == _y;
	}

	//����� �θ� ����
	void Node::Release_NodeParent()
	{
		m_Parent = NULL;
	}

	//�Ҹ���
	Node::~Node()
	{

	}
}