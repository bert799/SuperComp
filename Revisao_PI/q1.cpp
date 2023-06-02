#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(){
    int n_cidades, n_centros;
    cin >> n_cidades >> n_centros;
    vector<int> cidades(n_cidades, 0);
    vector<int> centros(n_centros, 0);
    vector<vector<int>> distancias_das_cidades (n_cidades, cidades);
    for (int i = 0; i < n_cidades; i++){
        for (int j = 0; j < n_cidades; j++){
            cin >> distancias_das_cidades[i][j];
        }
    }

    cout << centros[0] << " ";

    int maior_distancia = 0;
    int novo_centro = 0;
    for (int i = 1; i < n_centros; i++){
        for(int j = 0; j < n_cidades; j++){
            if(distancias_das_cidades[centros[i-1]][j] > maior_distancia){
                maior_distancia = distancias_das_cidades[centros[i-1]][j];
                novo_centro = j;
            }
        }
        centros[i] = novo_centro;
        cout << centros[i] << " ";
    }
    cout << endl;

    int min_dist, min_dist_centro = 0;
    for (int i = 0; i < n_cidades; i++){
        min_dist = distancias_das_cidades[i][centros[0]];
        min_dist_centro = centros[0];
        for (int j = 1; j < n_centros; j++){
            if(distancias_das_cidades[i][centros[j]] < min_dist){
                min_dist = distancias_das_cidades[i][centros[j]];
                min_dist_centro = centros[j];
            }
        }
        cout << min_dist_centro << " ";
    }
    cout << endl;

    return 0;
}