#include <iostream>
#include <iomanip>      // std::setprecision

int main() {
    int n, p = 1;
    double s = 0.0;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        s += (double) 1 / (p = p << 1);
    }
    std::cout << std::setprecision(15) << s << '\n';
    return 0;
}