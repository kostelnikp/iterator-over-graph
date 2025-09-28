#pragma once
#include <stack>
#include <queue>
#include "./Graph.h"


/// <summary>
/// BFSIterator class - Breadth-first search iterator
/// </summary>
class BFSIterator
{
	private:
		/// <summary>Array of discovered vertexes</summary>
		bool* discovered;
		/// <summary>Queue of of iterator</summary>
		queue<int>* currentQueue;
		/// <summary>Pointer to graph data</summary>
		Graph* graph;
	public:
		BFSIterator(Graph* graph);
		void Reset();
		void Next();
		bool IsEnd();
		int CurrentKey();
};

