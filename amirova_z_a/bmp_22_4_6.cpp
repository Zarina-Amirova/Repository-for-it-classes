#include <iostream>
#include <vector>
#include <cmath>


int main() {
	int h, w;
	std::string cw;
	std::cin >> h >> w >> cw;

	//пытаюсь наполнить матрицу
	//for (int i = 1; i <= h; i += 1) {
	//	std::vector <int> m;
	//	for (int j = 1; j <= w; j += 1) {
	//		int a = 1;
	//		m[i] = a;
	//		a += 1;
	//	}
	//}


	//если по часовой идем
	if (cw == "cws") {
		for (int i = 0; i < h * w; i += 1) {
			std::vector <int> m;
			int a = 1;
			m[i] = a;
			a += 1;
			for (int j = 0; j < w; j += 1) {

			}
		}
	}

	//если против часовой идём
	//if (cw == "cwc") {}

}
