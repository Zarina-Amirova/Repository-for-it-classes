#include <iostream>
#include <vector>
#include <algorithm>
 
 
int main() 
{
	int n, x, t;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::cin >> n >> x;
		std::vector <int> a(n);
 
		for (int j = 0; j < n; j += 1) {
			std::cin >> a[j];
		}
		sort(a.begin(), a.end());
		std::vector <int> flag(300);
		for (int i = 0; i < n; i += 1) {
			flag[a[i] - 1] = 1;
		}
		for (int j = 0; j < flag.size(); j += 1) {
			if (flag[j] == 0) {
				flag[j] = 1;
				x -= 1;
			}
			if (x == 0) {
				break;
			}
		}
		for (int j = 0; j < flag.size(); j += 1) {
			if (flag[j] == 0) {
				std::cout << j << std::endl;
				break;
			}
		}
	}
}
