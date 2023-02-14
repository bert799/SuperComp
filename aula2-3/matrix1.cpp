#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    double xa, ya, dist;
    std::vector<double> x, y, v;
    
    std::cin >> n;

    std::vector<double> vect(n, 0);
    std::vector<std::vector<double>> matrix(n, vect);

    for(int i = 0; i < n; ++i){
        std::cin >> xa >> ya;
        std::cout << xa << ' '<< ya << '\n';
        x.push_back(xa);
        y.push_back(ya);
    }
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            double dist = sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
            matrix[i][j] = dist;
            matrix[j][i] = dist;
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; j++){
            std::cout << matrix[i][j] << '\n';
        }
    }
}