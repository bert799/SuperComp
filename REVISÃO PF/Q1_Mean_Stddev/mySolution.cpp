#include <omp.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include <random>
#include <vector>

int main(){
    // standard deviation
    float stddev = 0; 
    // mean
    float mean = 0;
    // number of elements
    int N = 0;
    std::cin >> N;
    // number of threads
    int NUM_THREADS = 2;
    // array of random numbers
    int arr[N];
    // sum of elements
    int sum = 0;
    // variance
    float variance = 0;
    // Random seed generator
    std::random_device generator;
    // Random engine for each thread
    std::vector<std::default_random_engine> engines;
    for (int i = 0, n = NUM_THREADS; i < n; i++) {
        engines.emplace_back(std::default_random_engine(generator()));
    }
    std::uniform_int_distribution<int> num_distro(1,999);
    // Set num_threads for experiment
    omp_set_num_threads(NUM_THREADS);
    // Parallel for to generate random numbers in array
    #pragma omp parallel for
    for(int i = 0; i<N; i++){
        std::default_random_engine& g = engines[omp_get_thread_num()];
        arr[i] = num_distro(g);
    }
    // Parallel sum
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i<N; i++){
        sum += arr[i];
    }
    mean = ((float)sum) / ((float)N);
    // Parallel variance
    #pragma omp parallel for reduction(+:variance)
    for (int i = 0; i<N; i++){
        float dif = arr[i] - mean;
        variance += dif*dif;
    }
    stddev = sqrt(variance/N);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Stddev: " << stddev << std::endl;
    return 0;
}