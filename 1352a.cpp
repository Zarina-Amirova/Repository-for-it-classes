#include <iostream>
 
 
int main() {
 
	int k = 0;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
 
		int m = 0;
		std::cin >> m;
		int c = 0;
		int b = 1;
		int m1 = 0;
		m1 = m + m1;
		while (m1 > 0) {
			if (m1 % 10 != 0) {
				c += 1;
			}
			m1 /= 10;
		}
		std::cout << c << std::endl;
 
		while (m > 0) {
			if (m % 10 != 0) {
				std::cout << m % 10 * b << std::endl;
			}
			m /= 10;
			b *= 10;
		}
	}
 
}
