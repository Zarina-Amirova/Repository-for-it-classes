#include "Exams.h"
#include <iostream>
#include <vector>
#include<algorithm>

int main()
{
	int len_a;
	std::cin >> len_a;

	std::vector<int> a(len_a);
	for (int i = 0; i < len_a; i += 1) {
		std::cin >> a[i];
	}

	sort(a.begin(), a.end());

	int l_g = 0;
	int r_g = len_a-1;
	int mid;
	bool flag = false;
	int key;
	std::cin >> key;

	while ((l_g <= r_g) && (flag != true)) {
		mid = (l_g + r_g) / 2;
		if (a[mid] == key)  flag = true;
		if (a[mid] > key)  r_g = mid - 1;
		else l_g = mid + 1;
	}
	if (flag) std::cout << key << " " << mid;
	else std::cout << "**** *****";
}
