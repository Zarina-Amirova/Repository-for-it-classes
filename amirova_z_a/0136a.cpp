#include <iostream>
#include <vector>

int main()
{
	int n, p = 0;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; i += 1) {
		std::cin >> p;
		p[p - 1] = i + 1;
	}
	for (int j = 0; j < n; j += 1) {
		std::cout << p[j] << std::endl;
	}
}
