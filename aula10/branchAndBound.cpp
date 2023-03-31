#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "structItem.cpp"
#include "structBackpack.cpp"

int n, W, num_leaf, num_copy;
std::vector<Item> items;
BackPack init_pack, bestPack;

void branchAndBound(int i, std::vector<Item> *items, BackPack backPack){
    if(backPack.capacity < 0){
        return;
    }
    if(backPack.estimatedValue < bestPack.value){
        return;
    }
    if (backPack.value > bestPack.value){
        bestPack = backPack;
        num_copy++;
    }
    if(i == 0){
        if(backPack.capacity - items->at(i).weight >= 0){
            backPack.capacity -= items->at(i).weight;
            backPack.value += items->at(i).value;
            backPack.ids.push_back(i);
            if (backPack.value > bestPack.value){
                bestPack = backPack;
                num_copy++;
            }         
        }
        num_leaf++;
        return;
    }
    BackPack m1 = backPack;
    m1.capacity -= items->at(i).weight;
    m1.value += items->at(i).value;
    m1.ids.push_back(i);        
    branchAndBound(i-1, items, m1);

    backPack.estimatedValue -= items->at(i).value;
    branchAndBound(i-1, items, backPack);
}

int main(){
    std::cin >> n >> W;
    for(int i = 0; i < n; i++){
        Item temp_item;
        temp_item.id = i;
        std::cin>>temp_item.weight>>temp_item.value;
        items.push_back(temp_item);
    }

    bestPack.capacity = 0;
    bestPack.value = 0;

    init_pack.capacity = W;
    init_pack.value = 0;
    init_pack.ids = {};
    for (int i = 0; i < n; i++){
        init_pack.estimatedValue += items[i].value;
    }

    branchAndBound(n-1, &items, init_pack);

    std::cout << "value: " << bestPack.value << '\n' << "Peso: " << W - bestPack.capacity << '\n' << "Quantidade de itens na mochila: " << bestPack.ids.size() << '\n' << "num leaf: " << num_leaf << '\n' << "num copy: " << num_copy << '\n';

    return 0;
}