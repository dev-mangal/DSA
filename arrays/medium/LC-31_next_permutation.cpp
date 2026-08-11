#include <bits/stdc++.h>
using namespace std;

//if no next permutation then sort in ascending
class Solution{
public:
    void nextPermutation(vector<int> &nums){
        int pivot = -1;
        for(int i = nums.size() - 1; i >= 1; i--){
            //condition to check ascending order, if found then that element is to be increased since everything to the right of it is in descending
            if(nums[i-1] < nums[i]){
                pivot = i - 1;
                break;
            }
        }
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //find the index of the number to increase to
        int inc_index;
        int inc_el = INT_MAX;
        for(int i = pivot + 1; i < nums.size(); i++){
            if(nums[i] > nums[pivot]){
                //equals is important in the condition since if there are duplicate smallest values larger than pivot, then we need to choose the rightmost one, so we need index of the rightmost one
                if(nums[i] <= inc_el){
                    inc_el = nums[i];
                    inc_index = i;
                }
            }
        }
        //numbers have been swapped, now num_index contains the correct number, just need to reverse the suffix
        swap(nums[inc_index], nums[pivot]);
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,1};
    sol.nextPermutation(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}