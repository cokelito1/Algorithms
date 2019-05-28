#include <iostream>
#include <vector>
#include <queue>

bool bfs(std::vector<std::vector<int>> graph) {
	int current = 0;

	std::vector<bool> visitado(graph.size(), false);
	std::queue<int> queue;
	queue.push(current);
	
	while(!queue.empty()) {
		int current_node = queue.front();
		queue.pop();

		visitado[current_node] = true;

		for(auto i : graph[current_node]) {
			if(!visitado[i]) {
				queue.push(i);
			}
		}
	}

	return true;
}

int main() {
	int cantidad_nodos = 0, cantidad_aristas = 0;
	std::cin >> cantidad_nodos >> cantidad_aristas;

	std::vector<std::vector<int>> graph(cantidad_nodos, std::vector<int>());
	for(int i = 0; i < cantidad_aristas; i++) {
		int from, to;
		std::cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(graph);

	return 0;
}
