#include <omp.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include <random>
#include <iomanip>

using namespace  std;

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cerr <<
        "***Numero incorreto de argumentos ***\n";
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // Set num_threads for experiment
    omp_set_num_threads(8);

    // Random seed generator
    std::random_device generator;

    // Random engine for each thread
    std::vector<std::default_random_engine> engines;
    for (int i = 0, n = 8; i < n; i++) {
        engines.emplace_back(std::default_random_engine(generator()));
    }
    std::uniform_int_distribution<int> num_distro(0,100);

    //gerar numeros aleatorios
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    #pragma omp parallel for
    for(int i = 0; i<n; i++){
        std::default_random_engine& g = engines[omp_get_thread_num()];
        a[i] = num_distro(g);
        b[i] = num_distro(g);
    }

    //transformacao
    #pragma omp parallel for shared(c)
    for (int i = 0; i < n; i++ ){
        c[i] = m*a[i] + b[i];
    }

    for (int i = 0; i < n; i++ )
        cout << setw(6) << c[i] << " = " 
        << setw(2) << m
        << "*" << setw(5) << a[i]
        << "+" << setw(5) << b[i]
        << endl;
}