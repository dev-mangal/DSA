#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insertion_sort(int arr[], int n){
        //we cant skip an element here, loop needs to be for whole array
        for(int i = 0; i <= n-1; i++){
            int j = i;
            //start at the new element, compare with element on the left and swap, if no need then while breaks and sorted, but if we swap then j-- as the new element is one index behind now
            // > for descending
            while(j > 0 && arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                j--;
            }
        }
    }
};

int main(){
    Solution sol;
    int arr[] = {9,12,14,15,6,8,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    sol.insertion_sort(arr, n);
    for(auto i : arr){
        cout << i << endl;
    }
    return 0;
}