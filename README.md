# Iterator Over Graph

A simple C++ project demonstrating how to iterate over a graph using custom **Breadth-First Search (BFS)** and **Depth-First Search (DFS)** iterators. The implementation follows object-oriented principles and cleanly separates graph structure from traversal logic.

---

## 📌 Overview

This project includes:

- A `Graph` class implemented via an adjacency list.
- A `DFSIterator` class for Depth-First Search traversal.
- A `BFSIterator` class for Breadth-First Search traversal.
- A demo driver (`ALGProject.cpp`) for loading a graph from a file and running both traversals.

Both iterators behave similarly to standard C++ iterators, providing clean and modular iteration over graph data.

---

## 🧩 Features

- ✅ Graph structure based on an adjacency list
- 🔁 Custom iterators for BFS and DFS
- 🧠 Clear separation between data and traversal logic
- 🧪 Sample usage and testing via `ALGProject.cpp`
- 📁 Modular design using header/source file separation

---

## ▶️ Usage

1. Compile and run the program (see instructions below).
2. When prompted, enter the path to a graph input file, or press **Enter** to use the default file: `Graf2.txt`.

### 📤 Sample Output
```
Input file (Default Graf2.txt):
Graph visualization:
    [1] -> 2 -> 3
    [2] -> 1 -> 4
    [3] -> 1
    [4] -> 2

DFS: 1 2 4 3
BFS: 1 2 3 4
```

## 📄 Input File Format
The input file must follow this format:
- Line 1: integer N (declared number of vertices; informational)
- Lines 2..: edges as pairs "u v" separated by a single space
- Undirected graph is assumed; each edge u v adds connections u<->v

Example (Graf2.txt):
```
4
1 2
1 3
2 4
```


This defines a graph with 4 vertices and 3 undirected edges:
- 1 ↔ 2  
- 1 ↔ 3  
- 2 ↔ 4
