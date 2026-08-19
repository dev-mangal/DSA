#include <bits/stdc++.h>
using namespace std;

//return the number of subarrays with sum = k
class Solution{
public:
    //approach : prefix sum, O(N) O(N)
    int subarraySum(vector<int> &nums, int k){
        // unordered_set<int> s; set doesnt work for duplicate prefix sums, since we need to keep a count of them then increase the count by that many times (using map)
        //if a prefix sum repeats itself, then for each sum the subarrays also increase so every time the count of the prefix sum gets added
        unordered_map<int, int> mp; //{sum, count}
        int sum = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == k) result ++;
            int prev_sum = sum - k;
            //if prev sum exists then take its count and add in result
            if(mp.count(prev_sum)) result += mp[prev_sum];
            mp[sum]++;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    int k = 3;
    int result = sol.subarraySum(nums, k);
    cout << result << endl;
    return 0;
}