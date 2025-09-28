#pragma once
#include <queue>
#include <stack>

#include "./Graph.h"

/// <summary>
/// DFSIterator class - Depth-first search iterator
/// </summary>
class DFSIterator
{
	private:
		/// <summary>Array of discovered vertexes</summary>
		bool* discovered;
		/// <summary>Stack of iterator</summary>
		stack<int>* currentStack;
		/// <summary>Pointer to graph data</summary>
		Graph* graph;
	public:
		DFSIterator(Graph* graph);
		void Reset();
		void Next();
		bool IsEnd();
		int CurrentKey();
};

