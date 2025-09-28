#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

/// <summary>
///	Graph class - Stores the graph data and other attributes
/// </summary>
class Graph
{
	private:
		/// <summary>Count of vertexes</summary>
		int count;
		/// <summary>Smallest vertex</summary>
		int min;
		/// <summary>Graph data</summary>
		map<int, vector<int>*>* data;
		void loadFromFile(string filename);
		bool AddVertex(int x);
	public:
		Graph(string filename);
		void AddEdge(int x, int y);
		map<int, vector<int>*>* GetData();
		int GetCount();
		int GetMin();
		void Print();
};

