#include <bits/stdc++.h>
using namespace std;

void explainMultiSet(){
    //only sorted, can store multiple values
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2); //{1,1,1,2}

    ms.erase(1); //erases all occurrences of 1
    int cnt = ms.count(1);
    ms.erase(ms.find(1)); //ms.find returns iterator to the first occurrence of 1, so we erase the address itself

    auto it = ms.find(1);
    auto it2 = it;
    advance(it2, 2); //it2 now points to the next occurrence address
    ms.erase(it, it2); //erase 2 1's (not 3 since last address not included in range)

    //rest functions same as set
}

void explainUSet(){
    //unique, but elements stored in random order
    unordered_set<int> us;
    //same functions as set, but lower and upper bound dont work
    //all functions generally have TC of O(1)
    //sometimes when collision happens can go to O(N), very rare
}

int main(){
    explainMultiSet();
    explainUSet();
}