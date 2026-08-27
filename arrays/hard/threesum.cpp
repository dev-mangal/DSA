#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //O(n), O(n)
    //we make twosum return the vector containing both elements
    vector<vector<int>> twoSum(vector<int> &nums, int target){
        unordered_map<int, int> mp;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            int need = target - nums[i];
            if(mp.find(need) != mp.end()) result.push_back({nums[i], need});
            mp[nums[i]]++;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int> &nums){
        int target = 0;
        set<vector<int>> s;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            vector<int> triplet = {nums[i]};
            
        }
    }
};

int main(){
    Solution sol;
    
    return 0;
}