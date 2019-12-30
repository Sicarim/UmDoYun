#pragma once
#include "DoEngine.h"
#include "Node.h"
#include "GlobalDefine.h"

namespace DoEngine
{
	class NodeManager : public Singleton<NodeManager>
	{
	private:
		vector<DoEngine::Node*> m_vNode; //노드 집합체
		Node* tmp_Node; //Node를 담을 임시 노드
	public:
		NodeManager(); //생성자

		void Init_Nodes(int _x = 0, int _y = 0, int _data = 0); //노드 초기화
		void add_Neighbors(); //이웃 추가

		~NodeManager(); //소멸자
	};
}