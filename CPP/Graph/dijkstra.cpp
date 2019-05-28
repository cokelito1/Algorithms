#include <iostream>
#include <climits>
#include <vector>
#include <queue>

int dijkstra(std::vector<std::vector<std::pair<int, int>>> graph) {
	std::vector<int> pesos(graph.size(), INT_MAX);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> p_queue;

	p_queue.push(std::pair<int, int>(0, 0));

	while(!p_queue.empty()) {
		int node = p_queue.top().second;
		int peso = p_queue.top().first;
		p_queue.pop();

		for(auto& i : graph[node]) {
			if(pesos[i.second] > peso + i.first) {
				pesos[i.second] = peso + i.first;
				p_queue.push(std::pair<int, int>(peso + i.first, i.second));
			}
		}
	}

	return pesos[graph.size() - 1];
}

int main() {
	int cantidad_nodos = 0, cantidad_aristas = 0;
	std::cin >> cantidad_nodos >> cantidad_aristas;

	std::vector<std::vector<std::pair<int, int>>> graph(cantidad_nodos, std::vector<std::pair<int, int>>());
	for(int i = 0; i < cantidad_aristas; i++) {
		int from, to, weight;
		std::cin >> from >> to >> weight;

		graph[from].push_back(std::pair<int, int>(weight, to));
		graph[to].push_back(std::pair<int, int>(weight, from));
	}

	std::cout << dijkstra(graph) << std::endl;
	return 0;
}
