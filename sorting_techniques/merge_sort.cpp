#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //low and high are the first and last index of the array
    void merge_sort(vector<int> &arr, int low, int high){
        //base case
        if(low >= high) return;
        int mid = (low + high)/2;
        merge_sort(arr, low, mid); //left subtree sorted
        merge_sort(arr, mid+1, high); //right subtree sorted
        //left array from low to mid, right from mid+1 to high
        //we take pointers starting from both arrays (left and right) and an empty temp array, then we compare and fill the array accordingly
        merge(arr, low, mid, high); //merge
    }

    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;

        //[low...mid]
        //[mid+1...high]
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        //upper loop breaks when either left or right array gets exhausted, in which case we need to add the leftover elements from right or left arr
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        //now temp is sorted we need to add into arr
        //low is the beginning of the original array, and temp contains the values at the indexes from low, but starts at 0 itself (this happens during the subtree merges not the main one), which is why i - low
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr = {5,12,3,14,19};
    int n = arr.size();
    sol.merge_sort(arr, 0, n-1);
    for(auto it : arr){
        cout << it << endl;
    }
    return 0;
}