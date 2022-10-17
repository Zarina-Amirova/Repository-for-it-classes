#include <iostream>
 
int main() {
    int w=0;
    std::cin >> w;
    int n=w/5;
    if (0==w%5){
        std::cout << n;
    }
    else {
        std::cout <<n+1;
    }
}
