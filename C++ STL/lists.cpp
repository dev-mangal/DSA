#include <bits/stdc++.h>
using namespace std;

void explainLists(){
    list<int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4); //{2,4}
    ls.push_front(5); //{5,2,4} //emplace_front
    //rest all functions same as vector
    list<int> :: iterator it = ls.begin();
    cout << *it << endl;
}

int main(){
    explainLists();
}