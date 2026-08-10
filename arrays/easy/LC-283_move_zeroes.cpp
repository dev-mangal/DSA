#include <bits/stdc++.h>
using namespace std;

//move all zeros in the array in-place to the end
//two pointer approach O(N) and O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        //find the first zero and initialize j to its index
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
        //for the remaining array to the right of zero, when we find a non zero element we swap the values
        //then increment BOTH i and j by 1, j will still point to a zero, cuz if i moved by more than one that meant the element in between is also zero (like in {1,0,2,0,0,3}) so the logic still works
        for(int i = j+1; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,0,3,2,0,0,4,5,1};
    sol.moveZeroes(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}