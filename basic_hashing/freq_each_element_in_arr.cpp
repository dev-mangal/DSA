#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void countFreq(int arr[], int n){
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            cout << it.first << "->" << it.second << endl;
        }
    }
};

int main(){
    Solution sol;
    int arr[] = {5, 2, 3, 5, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.countFreq(arr, n);
    return 0;
}