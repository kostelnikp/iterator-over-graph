/**
 * @mainpage Documentation
 * Welcome to documentation of graph iterator.\n
 * 
 * ## First run
 * Press enter for loading default test file Graf2.txt or write your own file location.
 * 
 * ### Classes
 *   - Graph
 *   - DFSIterator
 *   - BFSIterator
 * 
 * ### Test files
 *   - Graf1.txt
 *   - Graf2.txt
 *   - Graf3.txt
 * 
 * @file   ALGProject.cpp
 * @brief  Main file of program with DFS and BFS iterator examples.
 *
 */
#include <iostream>
#include "./Graph.h"
#include "./DFSIterator.h"
#include "./BFSIterator.h"

using namespace std;

int main()
{
    string configFile;
    cout << "Input file (Default Graf2.txt): ";
    getline(cin, configFile);
    configFile = (configFile.empty()) ? "Graf2.txt" : configFile;
    try {
        Graph* graph = new Graph(configFile);
        graph->Print();

        cout << "\nDFS: ";
        DFSIterator* iteratorD = new DFSIterator(graph);
        iteratorD->Reset();
        while (!iteratorD->IsEnd()) {
            cout << iteratorD->CurrentKey() << " ";
            iteratorD->Next();
        }

        cout << "\nBFS: ";
        BFSIterator* iteratorB = new BFSIterator(graph);
        iteratorB->Reset();
        while (!iteratorB->IsEnd()) {
            cout << iteratorB->CurrentKey() << " ";
            iteratorB->Next();
        }
    }
    catch(...){
        cout << "ERROR: Couldn't load the file.";
    }

    cin.get();
    return 0;
}