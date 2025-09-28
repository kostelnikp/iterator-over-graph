#include "DFSIterator.h"

/// <summary>
/// Constructor for DFSIterator
/// </summary>
/// <param name="graph">Pointer to instance of graph</param>
DFSIterator::DFSIterator(Graph* graph) {
	this->discovered = new bool[graph->GetCount()]{ 0 };
	this->currentStack = new stack<int>;
	this->graph = graph;
	this->discovered[graph->GetMin()] = true;
	this->Reset();
}

/// <summary>
/// Method for resetting position of graph iterator to the smallest vertex
/// </summary>
void DFSIterator::Reset() {
	this->currentStack->push(
		this->graph->GetMin()
	);
}

/// <summary>
/// Method for returning current vertex of graph iterator
/// </summary>
/// <returns>Current vertex</returns>
int DFSIterator::CurrentKey() {
	if (!this->currentStack->empty() ) {
		return this->currentStack->top();
	}
	return -1;
}

/// <summary>
/// Method for checking the end of run of graph iterator
/// </summary>
/// <returns>True if iterator ended</returns>
bool DFSIterator::IsEnd() {
	if (this->currentStack->size() == 0) {
		for (int i = 0; i < this->graph->GetCount(); i++) {
			if (!this->discovered[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}


/// <summary>
/// Method moves current vertex to another vertex
/// </summary>
void DFSIterator::Next() {
	if (this->currentStack->empty()) { // If is stack empty, try to find another undiscovered vertexes
		for (int i = 0; i < this->graph->GetCount(); i++) { // Find another undiscovered vertex
			if (!this->discovered[i]) {
				this->currentStack->push(i);
				break;
			}
		}
	} else { // If isn't stack empty, loop through edges
		this->discovered[this->currentStack->top()] = true; // Mark current vertex as discovered
		vector<int>* current_vertex = this->graph->GetData()->at(
			this->currentStack->top()
		);
		// Find neighbor of current vertex and push it to stack
		for (int i = 0; i < current_vertex->size(); i++) {
			int new_item = current_vertex->at(i);
			if (!this->discovered[new_item]) {
				this->currentStack->push(new_item);
				break;
			}
			// If any new vertex neighbor was not found, go back to previous vertex
			if (i == current_vertex->size() - 1)
			{
				this->currentStack->pop(); // Remove current vertex
				// If is queue empty or vertex is marked as discovered, run again
				if (this->currentStack->empty() || this->discovered[this->currentStack->top()]) {
					this->Next();
				}
			}
		}
	}
}