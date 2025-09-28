#include "Graph.h"
#include <algorithm> 
#include <stdexcept> 


/// <summary>
/// Constructor for Graph
/// </summary>
/// <param name="filename">Filename with path of graph config file</param>
Graph::Graph(string filename) {
    this->count = 0;
    this->min = -1;
    this->data = nullptr;
    this->loadFromFile(filename);
}

/// <summary>
/// Method for loading graph from config file
/// </summary>
/// <param name="filename">Filename with path of graph config file</param>
void Graph::loadFromFile(string filename) {
    string line;
    ifstream file;

    file.open(filename);
    if (file.is_open()) {
        getline(file, line);
        this->count = stoi(line);
        this->data = new map<int, vector<int>*>[count];
        while (getline(file, line)) {
            string first = line.substr(0, line.find(" "));
            string second = line.substr(line.find(" "));
            this->AddEdge(stoi(first), stoi(second));
        }
    } else {
        throw std::runtime_error("ERROR: Couldn't load the file.");
    }
    file.close();
}

/// <summary>
/// Method for adding new vertex into graph
/// </summary>
/// <param name="x">Vertex number</param>
/// <returns>True if vertex was added successfully</returns>
bool Graph::AddVertex(int x) {
    if (data->find(x) == data->end()) {
        // Update the smallest vertex
        this->min = (this->min == -1) ? x : this->min;
        this->min = (x < this->min) ? x : this->min;
        data->insert(
            pair<int, vector<int>*>(x, new vector<int>)
        );
        return true;
    }
    return false;
}

/// <summary>
/// Method for creating edge between two vertexes
/// </summary>
/// <param name="x">First vertex</param>
/// <param name="y">Second vertex</param>
void Graph::AddEdge(int x, int y)
{
    // Add vertex if doesn't exist
    this->AddVertex(x);
    this->AddVertex(y);
    // Find position of element greater than new value to keep edges of vertex sorted
    auto index_x = upper_bound(
        this->data->at(y)->cbegin(),
        this->data->at(y)->cend(),
        x
    );
    auto index_y = upper_bound(
        this->data->at(x)->cbegin(), 
        this->data->at(x)->cend(), 
        y
    );
    // Make connection by adding edge at position before returned position
    this->data->at(x)->insert(index_y, y);
    this->data->at(y)->insert(index_x, x);
}

/// <summary>
/// Method for returning count of vertexes
/// </summary>
/// <returns>Count of vertexes</returns>
int Graph::GetCount() {
    return this->count;
}

/// <summary>
/// Method for returning the smallest vertex
/// </summary>
/// <returns>The smallest vertex</returns>
int Graph::GetMin(){
    return this->min;
}

/// <summary>
/// Method for returning pointer to graph data
/// </summary>
/// <returns>Pointer to graph data</returns>
map<int, vector<int>*>* Graph::GetData() {
    return this->data;
}

/// <summary>
/// Method for printing graph visualization
/// </summary>
void Graph::Print() {
    cout << "Graph visualization: \n";
    for (map<int, vector<int>*>::iterator i = this->data->begin(); i != this->data->end(); i++)
    {
        cout << "\t[" << i->first << "]";
        for (int j = 0; j < i->second->size(); j++) {
            cout << " -> " << i->second->at(j);
        }
        printf("\n");
    }
}