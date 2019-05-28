#include <iostream>
#include <queue>
#include <vector>

int main() {
	int cantidad_nodos = 0, cantidad_aristas = 0;
	std::cin >> cantidad_nodos >> cantidad_aristas;

	std::vector<std::vector<std::pair<int, int>>> Grapho(cantidad_nodos, std::vector<std::pair<int, int>>()); //peso, direccion
	
	for(int i = 0; i < cantidad_aristas; i++) {
		int from, to, weight;
		std::cin >> from >> to >> weight;
		Grapho[from].push_back(std::pair<int, int>(weight, to));
		Grapho[to].push_back(std::pair<int, int>(weight, from));
	}

	int sum = 0;
	std::vector<bool> Visitado(cantidad_nodos, false);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
	
	Visitado[0] = true;
	for(auto& i : Grapho[0]) {
		queue.push(i);
	}

	while(!queue.empty()) {
		std::pair<int, int> arista = queue.top();
		queue.pop();

		if(Visitado[arista.second]) {
			continue;
		}

		for(auto& i : Grapho[arista.second]) {
			if(!Visitado[i.second]) {
				queue.push(i);
			}
		}

		Visitado[arista.second] = true;

		sum += arista.first;
	}

	std::cout << sum << std::endl;
	return 0;
}

