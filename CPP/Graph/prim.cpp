#include <iostream>
#include <queue>
#include <vector>

/*
 * Idea Prim:
 *   La idea del algoritmo de prim es partir de cualquier vertice
 *   y tomar la arista con el peso minimo, verificar si el vertice
 *   objetivo ya fue visitado en caso de haber sido visitado se pasa
 *   al siguiente vertice, de no haber sido visitado se aplica el mismo
 *   proceso. Una vez visitado todos los nodos se tendra el MST
 *
 *  O(V log V + E log V)
 *
 *
 *  Ejemplo: Encontrar MST en el siguiente grafo con el algoritmo de prim
 *
 *            9
 *            |
 *            v
 *       1 ------- 3
 *       |\ 1    4/|
 *       | \     / |
 * 15 -> | -> 5<-  | <- 23
 *       | /    \  |
 *       |/18  11\ |
 *       2 ------- 4
 *            ^
 *            |
 *            6
 *
 *  Inicio:
 *
 *  |_(1, (1, 5))__|
 *  |_(9, (1, 3))__|  <-- Priority Queue    1    <-- MST
 *  |_(15, (1, 2))_|
 *
 *
 *  |_(4, (5, 3))__|
 *  |_(9, (1, 3))__|
 *  |_(11, (5, 4))_|  <-- Priority Queue      1
 *  |_(15, (1, 2))_|                           \1     <-- MST
 *  |_(18, (5, 2))_|                            \
 *                                               -5
 *
 *  |_(9, (1, 3))__|
 *  |_(11, (5, 4))_|
 *  |_(15, (1, 2))_|  <-- Priority Queue   1      -3
 *  |_(18, (5, 2))_|                        \1  4/      <-- MST
 *  |_(23, (3, 4))_|                         \  /
 *                                            -5
 *
 *  |_(6, (4, 2)__)|
 *  |_(11, (5, 4)_)|
 *  |_(15, (1, 2)_)|  <-- Priority Queue   1      -3
 *  |_(18, (5, 2)_)|                        \1  4/     <-- MST
 *  |_(23, (3, 4)_)|                         \  /
 *                                            -5
 *                                              \11
 *                                               \
 *                                                -4
 *
 *  |_(11, (5, 4)_)|
 *  |_(15, (1, 2)_)|
 *  |_(18, (5, 2)_)|  <-- Priority Queue   1      -3
 *  |_(23, (3, 4)_)|                        \1  4/
 *                                           \  /
 *                                            -5
 *                                              \11
 *                                            6  \
 *                                         2 ------4
 */

std::vector<std::vector<int>> Prim(std::vector<std::vector<std::pair<int, int>>>& Graph) {
  std::vector<bool> Visitado(Graph.size(), false);
  std::vector<std::vector<int>> MST(Graph.size());

  std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<std::pair<int, std::pair<int, int>>>> queue;

	Visitado[0] = true;
	for(auto& i : Graph[0]) {
		std::pair<int, std::pair<int, int>> new_arista;

		new_arista.first = i.first;
		new_arista.second.first = 0;
		new_arista.second.second = i.second;

		queue.push(new_arista);
	}


	int last = 0;
	while(!queue.empty()) {
		std::pair<int, std::pair<int, int>> arista = queue.top();
		queue.pop();

		if(Visitado[arista.second.second]) {
        continue;
		}


		if(arista.second.first != -1) {
			MST[arista.second.first].push_back(arista.second.second);
		}

		for(auto& i : Graph[arista.second.second]) {
			if(!Visitado[i.second]) {
				std::pair<int, std::pair<int, int>> new_arista;
				new_arista.first = i.first;
				new_arista.second.first = arista.second.second;
				new_arista.second.second = i.second;

				queue.push(new_arista);
			}
		}

		Visitado[arista.second.second] = true;
	}

  return MST;
}

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

	auto result = Prim(Grapho);

	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
		std::cout << i << " -> " << result[i][j] << std::endl;
		}
  	}

	return 0;
}

