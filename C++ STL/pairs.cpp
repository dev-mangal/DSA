#include <bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int> p = {1,3};
    cout << p.first << " " << p.second << endl;

    //recursive definition to store more than 2 elements
    pair<int, pair<int, string>> p2 = {1 , {2, "hi"}};
    cout << p2.first << p2.second.first << p2.second.second << endl;

    pair<int, int> arr[] = {{1,2}, {3,4}, {4,5}};
    cout << arr[1].first << arr[2].second << '\n';

    for(pair<int, int> p : arr){
        cout << p.first << '\n';
    }
}
int main(){
    explainPair();
}