#include <iostream>
#include <vector>

int main() {
	int t, a, b, s;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::cin >> a >> b;
		s = a + b;
		std::vector<int> pal(s);
		for (int j = 0; j < t; j += 1) {
			std::cin >> pal[j];
		}
	}
}
