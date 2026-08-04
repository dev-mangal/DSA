#include <bits/stdc++.h>
using namespace std;

//move all zeros in the array in-place to the end
// O(N2) and O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int sum = 0;
        bool allzero = true;
        for(auto it : nums){
            if(it != 0) {
                allzero = false;
                break;
            }
        }
        if(allzero) return;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                i--;
                count++;
            }
        }
        for(int i = 0; i < count; i++){
            nums.push_back(0);
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1,0,0,1,0};
    sol.moveZeroes(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}