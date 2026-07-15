#include <bits/stdc++.h>
using namespace std;

void explainMap(){
    // map<int, pair<int, int>> mp;
    // map<pair<int, int>, int> mp;
    map<int, int> mp;

    // mp[1] = {3,3}; //mp[{3,3}] = 1;
    // //mp.emplace({2,{2,2}}); doesn't work
    // mp.emplace(3, pair<int, int> (1,1)); //can use make_pair instead of pair<int, int>
    // mp.insert({2,{2,2}});

    mp[1] = 5;
    mp.emplace(3,2);
    mp.insert({2,4}); //insert the {key,value} pair directly inside map

    for(auto it : mp){ //in for each loop the it is the element itself, not an iterator so doesnt need deref
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[1] << endl;
    cout << mp[5] << endl; //5 key doesnt exist so it prints 0

    auto it = mp.find(3); //key used as arg in find, not the value
    cout << it->second << endl; //we get value by deref the iterator

    it = mp.find(5); //points to mp.end()

    it = mp.lower_bound(2);
    it = mp.upper_bound(3);

    //swap, size, empty, erase and all same, mp.erase(key) or using iterator range
    //bounds return iterators using keys, and they can be used to print out a certain range using iterators and loop
}

//multimap can have duplicate keys
//unordered map wont be sorted, still unique (O(1) worst case O(N))

int main(){
    explainMap();
}