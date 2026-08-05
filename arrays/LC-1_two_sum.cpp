#include <bits/stdc++.h>
using namespace std;

//given a vector, return the indices of two elements whose sum equal to target
class Solution {
public:
    //basic O(n2) solution
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    num1 = i;
                    num2 = j;
                }
            }
        }
        return {num1, num2};
    }
};

int main(){
    Solution sol;
    
    return 0;
}