#include <bits/stdc++.h>
using namespace std;

//given an array of 1s and 0s, find the max number of consecutive 1s in the array
//approach : keep a count till we have 1s, and a max value, when arr[i] = 0, then equate to max if count >, and reset count
//O(n)
class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int max = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count++;
            if(count > max) max = count;
            if(nums[i] == 0){
                count = 0;
            }
        }
        return max;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,0,0,1,0,1,1,1,1};
    int result = sol.findMaxConsecutiveOnes(nums);
    cout << result << endl;
    return 0;
}