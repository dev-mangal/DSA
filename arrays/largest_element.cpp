#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int largest_element(int arr[], int n){
        int max = arr[0];
        for(int i = 0; i < n; i++){
            if(arr[i] > max) max = arr[i];
        }
        return max;
    }
};

int main(){
    Solution sol;
    int arr[] = {2,5,3,31,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = sol.largest_element(arr, n);
    cout << max << endl;
    return 0;
}