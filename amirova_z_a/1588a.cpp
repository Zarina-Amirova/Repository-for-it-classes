#include <iostream>
#include <vector>

int main()
{
	int t, n, hight = 0;
	std::cin >> t;
	for (int j = 0; j < n; j += 1) {
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i += 1) {
			std::cin >> a[i];
		}
		hight = 1;
		for (int i = 1; i < n; i += 1) {
			if (a[i] == a[i-1]) {
				if (a[i] == 1) {
					hight += 5;
				}
				else {
					hight = -1;
					break;
				}
			}
			else if (a[i] == 1 && a[i - 1] == 0) {
				hight += 1;
			}
		}
		if (a[0] == 1 && hight != -1) {
			hight += 1;
		}
		std::cout << hight << std::endl;
		hight = 1;
	}

}
