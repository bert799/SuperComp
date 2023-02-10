#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    double mean, std_var, soma, x;
    std::vector<double> vec;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> x;
        vec.push_back(x);
        soma += x;
    }
    mean = soma/n;
    soma = 0.0;
    for(int i = 0; i < n; ++i){
        std::cout << "soma: " << i << '\n'; 
        soma += pow(vec[i] - mean, 2);
    }
    std_var = soma/n;
    std::cout << "mean: " << mean << "\n" << "standard variation: " << std_var <<'\n';
    return 0;
}