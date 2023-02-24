#include <iostream>
#include <vector>
#include <algorithm>
#include "structItem.cpp"

int n, max_weight, T;
double weight, value;
std::vector<item> items;

std::vector<int> answer;

bool compareValueDecreasing(item i1, item i2)
{
    return (i1.value > i2.value);
}

int main(){
    std::cin >> n >> max_weight;
    for(int i = 0; i < n; i++){
        item temp_item;
        temp_item.id = i;
        std::cin>>temp_item.weight>>temp_item.value;
        items.push_back(temp_item);
    }
    std::sort(items.begin(), items.end(), compareValueDecreasing);
    for (int i = 0; i < n; i++){
        if (items[i].weight<= max_weight){
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