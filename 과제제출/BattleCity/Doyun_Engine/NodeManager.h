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
		void Reset_Parents(); //노드들의 부모를 모두 삭제
		Node* get_Node(int _x, int _y); //노드를 리턴 (인자값으로 좌표값을 넣어줘야함)

		~NodeManager(); //소멸자
	};
}