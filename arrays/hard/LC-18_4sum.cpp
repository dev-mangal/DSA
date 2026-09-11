#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //O(n3),O(1)
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //add early exit conditions
        int n = nums.size();
        if(n < 4) return ans;

        for(int i = 0; i < n-3; i++){
            //early exit conditions for i, minimum possible sum and max possible sum
            long long minSumI = (long long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if(minSumI > target) break;

            //if max possible sum less than target then skip i since no possible solution for this i
            long long maxSumI = (long long) nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if(maxSumI < target) continue;

            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n-2; j++){
                //early exit conditions for j
                long long minSumJ = (long long) nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if(minSumJ > target) break;
                
                long long maxSumJ = (long long) nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if(maxSumJ < target) continue;

                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    long long sum = (long long) nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> ans = sol.fourSum(nums, target);
    for(int i = 0; i < ans.size(); i++){
        for(auto j : ans[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}