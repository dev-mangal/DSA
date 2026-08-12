#include <bits/stdc++.h>
using namespace std;

//if no next permutation then sort in ascending
class Solution{
public:
    void nextPermutation(vector<int> &nums){
        int pivot = -1;
        for(int i = nums.size() - 1; i >= 1; i--){
            //condition to check ascending order, if found then that element is to be increased (pivot) since everything to the right of it is in descending
            if(nums[i-1] < nums[i]){
                pivot = i - 1;
                break;
            }
        }
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //no need for min logic, since all elements to right of pivot in descending, so from the right just find the one greater than pivot to get the rightmost greater than pivot
        for(int i = nums.size() - 1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        //numbers have been swapped, now pivot contains the correct number, just need to reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,3,3};
    sol.nextPermutation(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}