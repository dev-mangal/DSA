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
        int min_index = -1;
        int start_index = 0;
        int end_index = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; //current sum
            if(sum - min_prefix > max_sum){
                max_sum = sum - min_prefix;
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
};

int main(){
    Solution sol;
    vector<int> nums = {-5,-4,-1,-7,-8};
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}