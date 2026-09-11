#include <bits/stdc++.h>
using namespace std;

//find number of subarrays with xor of all elements = target
class Solution{
public:
    int brute(vector<int> &nums, int target){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int res = nums[i];
            if(nums[i] == target) count++;
            for(int j = i + 1; j < nums.size(); j++){
                res = res ^ nums[j];
                if(res == target) count++;
            }
        }
        return count;
    }

    //using prefix
    int numSubArr(vector<int> &nums, int target){
        unordered_map<int, int> mp;
        int count = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
            if(res == target) count++;
            int need = res ^ target;
            if(mp.count(need)) count += mp[need];
            mp[res]++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,2,2,6,4};
    int target = 6;
    cout << sol.numSubArr(nums, target) << endl;
    return 0;
}