#include <bits/stdc++.h>
using namespace std;

//find the subarray with the maximum sum and return the sum
//also print the subarray
class Solution{
public:
    //approach : using prefix sum
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        int min_prefix = 0;
        int min_index = -1; //index at which min prefix sum is updated 
        int start_index = 0;
        int end_index = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; //current sum
            if(sum - min_prefix > max_sum){
                max_sum = sum - min_prefix;
                //actual subarray starts from 1 index right of the prefix sum subtracted to get the max sum
                start_index = min_index + 1; 
                end_index = i;
            }
            if(sum < min_prefix){
                min_prefix = sum;
                min_index = i;
            }
        }
        for(int i = start_index; i <= end_index; i++){
            cout << nums[i] << endl;
        }
        cout << endl;
        return max_sum;
    }

    //keep track of current sum and maximum sum, whenever sum < 0 that means we dont need to include that element in the subarray since it decreases the sum, so set sum = 0
    //basically checks if the change in sum is making the sum < 0 or not, if not then keep the subarray otherwise take a new one
    //whenever sum < 0 that means adding it to future elements of subarray wont be beneficial so we reset the sum and start a new subarray
    int kadane_algo(vector<int> &nums){
        int sum = 0;
        int max_sum = INT_MIN;
        int start_index = 0;
        int ans_end = 0;
        int ans_start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum == 0) start_index = i; //sum is always zero whenever we start a subarray
            sum += nums[i];
            if(max_sum < sum){
                max_sum = sum;
                ans_start = start_index; //without this line it will fail for all negative case since start index is updated every time sum resets to zero, so it will store the last index, but we need the index where max sum was updated
                ans_end = i;
            }
            if(sum < 0) sum = 0; //reset the sum for future iteration
        }
        for(int i = ans_start; i <= ans_end; i++){
            cout << nums[i] << endl;
        }
        cout << endl;
        return max_sum;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-5,-4,-1,-7,-8};
    cout << sol.kadane_algo(nums) << endl;
    return 0;
}