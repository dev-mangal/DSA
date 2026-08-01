#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rec_bs(int arr[], int n){
        if(n==1) return; //base case
        bool swapped = false;
        for(int i = 0; i <= n-2; i++){
            if(arr[i+1] < arr[i]) swap(arr[i+1], arr[i]);
            swapped = true;
        }
        if(swapped) return;
        rec_bs(arr, n-1);
    }
};

int main(){
    Solution sol;
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.rec_bs(arr, n);
    for(auto it:arr){
        cout << it << endl;
    }
    return 0;
}