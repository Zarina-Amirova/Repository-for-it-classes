#include <iostream>

int main() {
    int t,n, m, sx, sy, d;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        std::cin >> n >> m >> sx >> sy >> d;
        if (std::min((sx-1),(m-sy))<=d && std::min((sy-1),(n-sx))<=d) {
            std::cout<<-1<<std::endl;
        }
        else{
            std::cout<< n+m-2<<std::endl;
        }
    }
}
