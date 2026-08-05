#include <bits/stdc++.h>
using namespace std;

//two sorted arrays of size m and n, print union of the two in increasing order
//two pointer approach, set, map
class Solution{
public:
    void union_sorted(vector<int> &arr1, int m, vector<int> &arr2, int n){
        set<int> s;
        for(int i = 0; i < m; i++){
            s.insert(arr1[i]);
        }
        for(int i = 0; i < n; i++){
            s.insert(arr2[i]);
        }
        for(auto it : s){
            cout << it << endl;
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {1,2,3,4};
    int m = arr1.size();
    vector<int> arr2 = {2,3,4,6,9};
    int n = arr2.size();
    sol.union_sorted(arr1, m, arr2, n);
    return 0;
}