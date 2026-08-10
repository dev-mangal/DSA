#include <bits/stdc++.h>
using namespace std;

//given a vector, return the indices of two elements whose sum equal to target
class Solution {
public:
    //returns the values themselves
    //can also do using sort and two pointer approach, calculate the sum and if sum > target then reduce the right pointer, if sum < target then increase the left pointer till sum is found and left < right
    vector<int> twoSum2(vector<int>& nums, int target) {
        //this map stores the frequency of the value, not the index
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            //count just returns 1 or 0, doesnt care about the frequency i.e the value mapped to the key
            if(mp.count(need)) return {nums[i], need};
            mp[nums[i]]++;
        }
        return {-1,-1};
    }
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if(mp.count(need)) return {i, mp[need]};
            //do this step after the if condition since if duplicate values like {3,3} then the current element is the second 3 and we need the first 3's index, if this is done before the if then we get the same index twice
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 18;
    vector<int> result = sol.twoSum(nums, target);
    for(auto it : result){
        cout << it << endl;
    }
    return 0;
}