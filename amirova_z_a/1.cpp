#include <iostream>
#include <cmath>

int main(){
	double eps = 0.0001;
	double summa = 0;
	for (int j = 0.1; j <= 1; j += 0.05) {
		if (summa) {
			std::cout << summa << " " << j;
			summa += summa**(2*j);
			std::cout << " " << summa << '\n';
		}
		else {
			break;
		}
	}
}
