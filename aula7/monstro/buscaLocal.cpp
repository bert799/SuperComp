#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "structItem.cpp"

std::default_random_engine generator(time(NULL));
std::binomial_distribution<int> random_distribution(1,0.5);

int make_knapsack(int n, int max_weight, int *T, double *weight, double *value, std::vector<int> *answer, std::vector<item> items){
    for (int i = 0; i < n; i++){
    int chosen = random_distribution(generator);
        if (items[i].weight<= max_weight && chosen == 1){
            *T += 1;
            answer->push_back(items[i].id);
            max_weight -= items[i].weight;
            *weight += items[i].weight;
            *value += items[i].value;
        }
    }
    for (int i = 0; i < n; i++){
        if (items[i].weight<= max_weight){
            *T += 1;
            answer->push_back(items[i].id);
            max_weight -= items[i].weight;
            *weight += items[i].weight;
            *value += items[i].value;
        }
    }
    return 0;
}

int main(){
    int n, max_weight, T, temp_T;
    double weight, value, temp_value, temp_weight;
    std::vector<item> items;
    std::vector<int> answer, temp_answer;
    int N = 100;

    std::cin >> n >> max_weight;
    for(int i = 0; i < n; i++){
        item temp_item;
        temp_item.id = i;
        std::cin>>temp_item.weight>>temp_item.value;
        items.push_back(temp_item);
    }

    T = 0;
    value = 0;
    for(int i = 0; i < N; i++){
        make_knapsack(n, max_weight, &temp_T, &temp_weight, &temp_value, &temp_answer, items);
        if (value < temp_value){
            //answer = temp_answer;
            T = temp_T;
            value = temp_value;
            weight = temp_weight;
        }
    }  
    std::cout<<weight<< ' '<< value << ' ' << '0' <<'\n';
    for(int i =0; i < T; i++){
        std::cout<<answer[i]<<' ';
    }
    std::cout<<'\n';

    return 0;
}