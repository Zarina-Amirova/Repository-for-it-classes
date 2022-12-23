#include <iostream>
#include <string>

int main() {
	int len1, j, k = 0;
	std::string s1, s2;
	std::cin >> s1 >> s2;
	len1 = s1.length();
	j = s2.length()-1;
	for (int i = len1-1; i >= 0 && j >= 0; i -= 1, j -= 1) {
		if (s1[i] == s2[j]) {
			k += 2;
		}
		else { break; }
	}
	std::cout<<len1+(s2.length())-k;
}
