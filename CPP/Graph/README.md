#Graph Algorithms

## Usage
All the Graph algorithms have the input as node quantity then 
edge quantity followed by a list of edge in the form of 
from to <weight>. Weight is optional as is only needed on weighted
graph algorithms.

### Prim Algorithm
Prim algorithm is useful to get the minimum spanning tree, it has a complexity
of O(E + log V) with a fibonacci heap.

### Dijkstra Algorithm
The Dijkstra algorithm is useful to get the shortest path from a node to another, it has
a complexity of O(E log V)

### Floyd-Warshall Algorithm
The Floyd-Warshall algorithm is useful to get all the shortest path between any node in a
graph, it has a complexity of O(V<sup>3</sup>)

### Depth First Search (DFS)
The dfs algorithm is useful to search a graph following all the path, it has
a complexity of O(V).

### Breath First Search (BFS)
The dfs algorithm is useful to search a graph following all the adjacent vertex
on a graph, it has a complexity of O(V)
