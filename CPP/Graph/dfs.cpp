#include <iostream>
#include <vector>

bool dfs(std::vector<std::vector<int>> graph, std::vector<bool>& visitado, int current) {
	visitado[current] = true;

	for(auto i : graph[current]) {
		if(!visitado[i]) {
			dfs(graph, visitado, i);
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

	std::vector<bool> visitados(cantidad_nodos, false);
	dfs(graph, visitados, 0);

	return 0;
}
