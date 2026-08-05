#include <bits/stdc++.h>
using namespace std;

//sort array of 0s, 1s, 2s in place
class Solution{
public:
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i < j){
            while(nums[i] <= pivot && i < high){
                i++;
            }
            while(nums[j] > pivot && j > low){
                j--;
            }
            if(i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    void quicksort(vector<int>& nums, int low, int high){
        if(low < high){
            int p_index = partition(nums, low, high);
            quicksort(nums, low, p_index-1);
            quicksort(nums, p_index+1, high);
        }
    }
    void bubblesort(vector<int> &nums){
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = 0; j < nums.size() - i - 1; j++){
                if(nums[j] > nums[j+1]) swap(nums[j+1], nums[j]);
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.bubblesort(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}