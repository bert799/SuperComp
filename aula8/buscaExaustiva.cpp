#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "structItem.cpp"
#include "structBackpack.cpp"

int n, W;
std::vector<Item> items;
BackPack answerPack;

BackPack exhaustiveSearch(int i, std::vector<Item> *items, BackPack backPack){
    if(backPack.weight >= W){
        return backPack;
    }
    if(i == 0){
        if(items->at(i).weight + backPack.weight <= W){
            backPack.weight += items->at(i).weight;
            backPack.value += items->at(i).value;
            backPack.ids.push_back(i);
        }
        return backPack;
    }
    BackPack m1 = exhaustiveSearch(i-1, items, backPack);
    backPack.weight += items->at(i).weight;
    backPack.value += items->at(i).value;
    backPack.ids.push_back(i);
    BackPack m2 = exhaustiveSearch(i-1, items, backPack);
    if(m1.weight <= W && m2.weight <= W){
        if (m1.value > m2.value){
            return m1;
        }
        else{
            return m2;
        }
    }
    else if (m1.weight <= W){
        return m1;
    }
    else if (m2.weight <= W){
        return m2;
    }
    else {
        return backPack;
    }
}

int main(){
    std::cin >> n >> W;
    for(int i = 0; i < n; i++){
        Item temp_item;
        temp_item.id = i;
        std::cin>>temp_item.weight>>temp_item.value;
        items.push_back(temp_item);
    }

    answerPack = exhaustiveSearch(n-1, &items, answerPack);

    std::cout << answerPack.value << '\n' << answerPack.weight << '\n';

    return 0;
}