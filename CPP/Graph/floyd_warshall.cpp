#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<int>> floyd_warshall(std::vector<std::vector<int>> graph) {
	auto result = graph;
	for(int i = 0; i < result.size(); i++) {
		result[i][i] = 0;
	}

	for(int i = 0; i < graph.size(); i++) {
		for(int j = 0; j < graph.size(); j++) {
			for(int w = 0; w < graph.size(); w++) {
				int new_weight = graph[i][j] + graph[j][w];
				if(result[i][w] > new_weight) {
					result[i][w] = new_weight;
				}
			}
		}
	}

	return result;
}

int main() {
	int cantidad_nodos, cantidad_aristas;
	std::cin >> cantidad_nodos >> cantidad_aristas;

	std::vector<std::vector<int>> graph(cantidad_nodos, std::vector<int>(cantidad_nodos, 9999));
	for(int i = 0; i < cantidad_aristas; i++) {
		int from, to, weight;
		std::cin >> from >> to >> weight;

		graph[from][to] = weight;
		graph[to][from] = weight;
	}

	auto result = floyd_warshall(graph);
	for(int i = 0; i < cantidad_nodos; i++) {
		for(int j = 0; j < cantidad_nodos; j++) {
			if(result[i][j] == 9999) {
				std::cout << "N/A" << " ";
				continue;	
			}
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
