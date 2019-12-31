#pragma once
#include "DoEngine.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class Node
	{
	private:
		Node* m_Parent; //����� �θ�
		list<Node*> m_Neighbors; //��尡 ������ �ִ� �̿���
		int pos_x, pos_y; //������ ��� ��ǥ
		int Node_Data; //����� ��ȣ
		
	public:
		Node(); //������

		void set_NodeData(int _num); //��� ��ȣ ����
		void set_NodeXY(int _x, int _y); //��� ��ǥ ����
		void set_Neighbor(Node* _node); //�̿� �߰�
		void set_Parent(Node* _parent); //����� �θ�, �� �ڽŰ� �̾����� �� ���

		int get_NodeData(); //��Ʈ ��ȣ ����
		list<Node*> get_Neighbors(); //�̿����� ����
		int get_NodeX(); //��� ��ǥ ����(x)
		int get_NodeY(); //��� ��ǥ ����(y)
		Node* get_Parent(); //�θ� ��� ����

		bool get_equals(Node* _node); //��尡 ������
		
		~Node(); //�Ҹ���
	};
}