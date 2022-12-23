#include <iostream>


const double eps = 1e-6;
int main() {
	double x, y;
	int k_in = 0, k_out = 0;
	while (std::cin >> x >> y) {
		bool circle = (x * x + y * y <= 1),
			space = circle && ((-1 - eps <= x && x <= 0 + eps && 0 - eps <= y && y <= 1 + eps) || (x <= 1 + eps && 0 - eps <= x && -1 - eps <= y && 0 + eps >= y)),
			lines = space && ((y - x >= 1  || y-x<=-1));
		if (lines) {
			k_in += 1;
		}
		else { 
			k_out += 1; 
		}
	}
	std::cout << k_in << " " << k_out<<"\n";
	//std::cout <<  k_in / (k_in + k_out);
}
