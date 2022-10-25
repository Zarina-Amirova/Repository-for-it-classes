#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int t, n, v, k=1, m=0;
    std::cin >> t;
    for (int d = 0; d < t; d += 1) {
        std::cin >> n;
        v = pow(2, n);
        std::vector<int> a(n);
        for (int s = 0; s < n; s += 1) {
            std::cin >> a[s];
            k *= a[s];
        }
        if (k % v == 0) {
            std::cout << 0 << std::endl;
        }
        else {
            for (int i = 0; i < n; i += 1) {
                k /= a[i];
                a[i] = a[i] * i;
                k *= a[i];
                m += 1;
                if (k % v == 0) { break; }
                else { continue; }
            }
            if (k % v != 0) {
                std::cout << -1 << std::endl;
            }
        }
        std::cout << m;
    }
}
