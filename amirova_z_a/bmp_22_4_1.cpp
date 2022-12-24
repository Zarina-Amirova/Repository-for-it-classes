#include <iostream>
#include <cmath>

unsigned long long factorial(unsigned long long x) {
	unsigned long long s=1;
	for (int i=1; i <= x; i += 1) {
		s *= i;
	}
	return s;
}

const double eps = 0.0001;
int main() {
	for (double x = 0.1; x <= 1 + eps; x += 0.05) {
		double t = x;
		int i = 0;
		double s = 0;
		while (t >= eps) {
			double pw = (std::pow(x, 2 * i));
			unsigned long long fac = factorial(2 * i);
			t = pw / fac;
			s += t;
			i += 1;
		}
		std::cout << "x " << x << " " << "summa " << s << '\n';
	}
}
