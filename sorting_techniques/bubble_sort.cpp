#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void bubble_sort(int arr[], int n){
        //n-1 iterations for the whole sorting
        //optimization, if not even a single swap happens in the first outer loop iteration then sorted already
        //O(N) since the inner loop runs N times to check the elements
        for(int i = 0; i < n-1; i++){
            bool swapped = false;
            for(int j = 0; j < n-i-1; j++){
                // < for descending
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
};

int main(){
    Solution sol;
    int arr[] = {13,24,46,20,9,52};
    int arr2[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[n]);
    sol.bubble_sort(arr, n);
    for(auto i : arr){
        cout << i << endl;
    }
    return 0;
}