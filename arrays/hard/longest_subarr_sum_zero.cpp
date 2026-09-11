#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //using prefix sum
    //O(n), O(n)
    int longSubArr(vector<int> &nums){
        unordered_map<int, int> mp;
        int sum = 0;
        int length = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == 0) length = max(length, i + 1); //handles the case of {1,-1}
            if(mp.find(sum) != mp.end()) length = max(length, i - mp[sum]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return length;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {9,-3,3,-1,6,-5};
    cout << sol.longSubArr(nums) << endl;
    return 0;
}