#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int partition(vector<int> &arr, int low, int high){
        int pivot = arr[low]; //can be anything
        int i = low;
        int j = high;
        //this loops swaps the elements till we have smth that makes i and j cross each other i.e j < i
        while(i < j){
            //this loop runs till we have the index of the first element greater than pivot
            //just reverse the comparison conditions for descending order
            while(arr[i] <= pivot && i < high){
                i++;
            }
            //index of first element smaller than pivot
            while(arr[j] > pivot && j > low){
                j--;
            }
            //if i and j have not crossed each other then swap
            if(i < j) swap(arr[i], arr[j]);
        }
        //we have the correct position of pivot at j now
        swap(arr[low], arr[j]);
        return j;
    }

    void quick_sort(vector<int> &arr, int low, int high){
        if(low < high){
            //this fxn returns the partition index i.e the index where the pivot is stored
            int p_index = partition(arr, low, high); 
            //recursive call for the right and left arrays, they will return once low == high (single element left)
            quick_sort(arr, low, p_index-1);
            quick_sort(arr, p_index+1, high);
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr = {4,6,2,5,7,9,1,3};
    sol.quick_sort(arr, 0, arr.size() - 1);
    for(auto it:arr){
        cout << it << endl;
    }
    return 0;
}