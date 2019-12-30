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
		Astar(); //생성자

		void Serch(Node _start, Node _end); //가장 짧은 길 찾기
		void Heuristic(); //휴리스틱 추정값 계산
		void PrintPath(Node _node); //짧은 길 찾기
		void Clear_Queue(queue<Node>& _q); //큐를 비운다.

		~Astar(); //소멸자
	};
}