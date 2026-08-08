#include <bits/stdc++.h>
using namespace std;

//given array of size n-1, range [1,n], find the missing number from this range
//approach : can sort array in nlogn, then using a loop can just find the element
class Solution{
public:
    int partition(vector<int> &arr, int low, int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i < j){
            while(i < high && arr[i] <= pivot){
                i++;
            }
            while(j > low && arr[j] > pivot){
                j--;
            }   
            if(i < j) swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[low]);
        return j;
    }
    void quick_sort(vector<int> &arr, int low, int high){
        if(low < high){
            int p_index = partition(arr, low, high);
            quick_sort(arr, low, p_index-1);
            quick_sort(arr, p_index+1, high);
        }
    }
    int find_missing(vector<int> &arr, int n){
        int range = n+1;
        quick_sort(arr, 0, n-1);
        for(int i = 1; i < range; i++){
            if(arr[i - 1] != i){
                return i;
            }
        }
        if(arr[n-1] != range) return range;
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {6,2,4,5,3,1,7};
    int result = sol.find_missing(arr, arr.size());
    cout << result << endl;
    return 0;
}