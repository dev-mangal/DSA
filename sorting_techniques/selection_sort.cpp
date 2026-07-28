#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void selection_sort(int arr[], int n){
        //two loops, one to start a new array, then one to go from that new index to n-1th index
        //swap starts from 0 to n-1 index, then 1 to n-1 .... n-2 to n-1
        //we dont need to go till n-1 for the loop, since the last element will always be the largest one if we have sorted everything before it
        for(int i = 0; i <= n-2 ;i++){
            int mini = i; //assume the minimum element's index is the first index of the unsorted array (i.e starting from 0,then 1 then 2 etc)

            //find min element in the unsorted array
            for(int j = i; j <= n-1; j++){
                // > for descending
                if(arr[j] < arr[mini]){ 
                    mini = j;
                }
            }
            //now we have the minimum element we just need to swap the positions with the current arr[i]
            swap(arr[i], arr[mini]);
        }
    }
};

int main(){
    Solution sol;
    int arr[] = {12, 9, 2, 26, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.selection_sort(arr, n);    
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}