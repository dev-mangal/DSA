#include <bits/stdc++.h>
using namespace std;

//find the subarray with the maximum sum and return the sum
class Solution{
public:
    //approach : using prefix sum
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;
        int min_prefix = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]; //current sum
            max_sum = max(sum-min_prefix, max_sum);
            min_prefix = min(min_prefix, sum);  
        }
        return max_sum;
    }
};

int main(){
    Solution sol;
    
    return 0;
}