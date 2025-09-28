#include "BFSIterator.h"

/// <summary>
/// Constructor for BFSIterator
/// </summary>
/// <param name="graph">Pointer to instance of graph</param>
BFSIterator::BFSIterator(Graph* graph) {
	this->discovered = new bool[graph->GetCount()]{ false };
	this->currentQueue = new queue<int>;
	this->graph = graph;
	this->discovered[graph->GetMin()] = true;
	this->Reset();
}

/// <summary>
/// Method for resetting position of graph iterator to the smallest vertex
/// </summary>
void BFSIterator::Reset() {
	this->currentQueue->push(
		this->graph->GetMin()
	);
}

/// <summary>
/// Method for returning current vertex of graph iterator
/// </summary>
/// <returns>Current vertex</returns>
int BFSIterator::CurrentKey() {
	if (!this->currentQueue->empty()) {
		return this->currentQueue->front();
	}
	return -1;
}

/// <summary>
/// Method for checking the end of run of graph iterator
/// </summary>
/// <returns>True if iterator ended</returns>
bool BFSIterator::IsEnd() {
	if (this->currentQueue->size() == 0) {
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
void BFSIterator::Next() {
	if (this->currentQueue->empty()) { // If is queue empty, try to find another undiscovered vertexes
		for (int i = 0; i < this->graph->GetCount(); i++) { // Find another undiscovered vertex
			if (!this->discovered[i]) {
				this->currentQueue->push(i);
				break;
			}
		}
	} else { // If isn't queue empty, loop through edges
		this->discovered[this->currentQueue->front()] = true; // Mark current vertex as discovered
		vector<int>* currentVertex = this->graph->GetData()->at(
			this->currentQueue->front()
		);
		this->currentQueue->pop(); // Remove current vertex
		// Find neighbors of current vertex and push them all to queue
		for (int i = 0; i < currentVertex->size(); i++) {
			int neighborVertex = currentVertex->at(i);
			if (!this->discovered[neighborVertex]) {
				this->currentQueue->push(neighborVertex);
			}
		}
		// If is queue empty or vertex is marked as discovered, run again
		if (this->currentQueue->empty() || this->discovered[this->currentQueue->front()]) {
			this->Next();
		}
	}
}
