#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "structItem.cpp"
#include "structBackpack.cpp"

int n, W, num_leaf, num_copy;
std::vector<Item> items;
BackPack answerPack, bestPack;

BackPack branchAndBound(int i, std::vector<Item> *items, BackPack backPack){
    if(backPack.capacity <= 0){
        return backPack;
    }
    if(i == 0){
        if(backPack.capacity - items->at(i).weight >= 0){
            backPack.capacity -= items->at(i).weight;
            backPack.value += items->at(i).value;
            backPack.ids.push_back(i);
        }
        num_leaf++;
        return backPack;
    }
    
    if(backPack.capacity - items->at(i).weight < 0){
        return bestPack;
    }
    else if(backPack.estimatedValue < bestPack.estimatedValue){
            return bestPack;
        }
    else{
        BackPack m1 = backPack;
        m1.capacity -= items->at(i).weight;
        m1.value += items->at(i).value;
        m1.ids.push_back(i);        
        branchAndBound(i-1, items, m1);
        if(backPack.capacity - items->at(i).weight < 0){
            return branchAndBound(i-1, items, backPack);
        }
        if(backPack.estimatedValue < bestPack.estimatedValue){
            return backPack;
        }

        BackPack m2 = branchAndBound(i-1, items, backPack);
        if(m1.capacity <= W && m2.capacity <= W){
            if (m1.value > m2.value){
                return m1;
            }
            else{
                return m2;
            }
        }
        //mudar conferencias
        else if (m1.capacity <= W){
            return m1;
        }
        else if (m2.capacity <= W){
            return m2;
        }
        else {
            return backPack;
        }
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

    answerPack = branchAndBound(n-1, &items, answerPack);

    std::cout << answerPack.value << '\n' << answerPack.weight << '\n';

    return 0;
}