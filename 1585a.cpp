#include <iostream>
#include <vector>

int main() 
{
	int n;
	std::cin >> n;
	int hight = 1;
		std::vector <int> a(n);
		for (int j = 0; j < n; j += 1) {
			std::cin >> a[j];
			if (a[0] == 1) { hight += 1; };
		}
		for (int j = 0; j < 2; j++) {
			if ((a[j] != a[j + 1]) and (a[j] == 1)) {
				hight += 1;
			};
			if ((a[j] != a[j + 1]) and (a[j] == 0)) {
				hight += 0;
			};
			if (a[j] == a[j + 1] and (a[j] == 1)) {
				hight += 5;
			};
			if (a[j] == a[j + 1] and (a[j] == 0)) {
				hight = -1;
			};
			if (a[j+1] == 1) { hight += 1; };
		};
	std::cout << hight;
}
