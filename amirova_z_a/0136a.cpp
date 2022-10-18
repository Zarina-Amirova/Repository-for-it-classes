#include <iostream>
#include <vector>
 
int main()
{
	int n, p = 0;
	std::cin >> n;
	std::vector<int> ps(n);
	for (int i = 0; i < n; i += 1) {
		std::cin >> p;
		ps[p - 1] = i + 1;
	}
	for (int j = 0; j < n; j += 1) {
		std::cout << ps[j] << std::endl;
	}
}
