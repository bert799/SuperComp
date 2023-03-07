#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "structItem.cpp"

std::default_random_engine generator(10);
std::binomial_distribution<int> random_distribution(1,0.5);

int n, max_weight, T;
double weight, value;
std::vector<item> items;

std::vector<int> answer;

int main(){
    std::cin >> n >> max_weight;
    for(int i = 0; i < n; i++){
        item temp_item;
        temp_item.id = i;
        std::cin>>temp_item.weight>>temp_item.value;
        items.push_back(temp_item);
    }
    for (int i = 0; i < n; i++){
        int chosen = random_distribution(generator);
        if (items[i].weight<= max_weight && chosen == 1){
            T++;
            answer.push_back(items[i].id);
            max_weight -= items[i].weight;
            weight += items[i].weight;
            value += items[i].value;
        }
    }
    std::cout<<weight<< ' '<< value << ' ' << '0' <<'\n';
    for(int i =0; i < T; i++){
        std::cout<<answer[i]<<' ';
    }
    std::cout<<'\n';

    return 0;
}