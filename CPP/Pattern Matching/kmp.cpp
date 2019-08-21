#include <iostream>
#include <vector>
#include <string>

std::vector<int> GenerateDFA(const std::string& pattern) {
	std::vector<int> dfa(pattern.size());

	int x = 0;
	dfa[0] = 0;

	for(int i = 1; i < pattern.size(); i++) {
		if(pattern[i] == pattern[x]) {
			dfa[i] = dfa[x];
			x++;
		} else {
			dfa[i] = x + 1;
			x = dfa[x];
		}
	}

	return dfa;
}

int main() {
	std::string pattern = "";
	std::cin >> pattern;
	auto dfa = GenerateDFA(pattern);

	int state = 0;

	std::string to_match = "";
	std::cin >> to_match;

	int where = 0;
	bool did_found = false;
	for(auto i : to_match) {
		if(state == pattern.size()) {
			did_found = true;
			break;
		}

		if(i == pattern[state]) {
			state++;
		} else {
			state = dfa[state];
		}
		where++;
	}

	if(did_found) {
		where -= pattern.size();
		for(int i = 0; i < to_match.size(); i++) {
			if(i == where) {
				std::cout << "\033[31m";
			} else if(i == where + pattern.size()) {
				std::cout << "\033[0m";
			}

			std::cout << to_match[i];
		}

		std::cout << std::endl;
	}

	return 0;
}
