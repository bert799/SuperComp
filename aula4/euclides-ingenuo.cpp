#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> matriz;

// void calcula_distancias(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
//     int n = x.size();
//     for (int i = 0; i < n; i++) {
//         std::vector<double> linha;
//         for (int j = 0; j < n; j++) {
//             double dx = x[i] - x[j];
//             double dy = y[i] - y[j];
//             linha.push_back((dx*dx + dy*dy));    
//         }
//         mat.push_back(linha);
//     }
// }

void calcula_distancias_otimizado(matriz &mat, std::vector<double> &x, std::vector<double> &y) {
    int n = x.size();
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            mat[i][j] = sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
            mat[j][i] = mat[i][j];
        }
    }
}

int main() {
    matriz mat;
    std::vector<double> x, y;
    int n;
    
    std::cin >> n;

    std::vector<double> vect(n, 0);
    std::vector<std::vector<double>> matrix(n, vect);

    
    x.reserve(n);
    y.reserve(n);
    for (int i = 0; i < n; i++) {
        double xt, yt;
        std::cin >> xt >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    //calcula_distancias(mat, x, y);
    calcula_distancias_otimizado(matrix, x, y);

    return 0;
}