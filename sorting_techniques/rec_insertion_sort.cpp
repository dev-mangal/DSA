#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //we simply used recursion for the outer loop and called all the indexes like that
    void rec_ins(int arr[], int i, int n) {
    // Base Case: if index reaches the size, return, m instead of n-1 since the next call needs to return i.e when i = n, not the current one (same logic as using < n instead of n-1 in insertion sort)
    if (i == n) return;

    int j = i;
    // Shift the element to the left while it's smaller than its predecessor
    while (j > 0 && arr[j - 1] > arr[j]) {
        // Swap arr[j] and arr[j-1]
        swap(arr[j-1], arr[j]);
        j--;
    }

    // Recur for the next index
    rec_ins(arr, i + 1, n);
}
};

int main(){
    Solution sol;
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.rec_ins(arr, 0, n);
    for(auto it:arr){
        cout << it << endl;
    }
    return 0;
}