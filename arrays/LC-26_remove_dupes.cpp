#include <bits/stdc++.h>
using namespace std;

//given a non decreasing sorted array, remove duplicates in-place preserving the original order, and return the number of distinct values
class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) nums.erase(nums.begin() + i);
        }
        return nums.size();
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,2,3,5,5};
    int n = sol.removeDuplicates(arr);
    for(auto it : arr){
        cout << it << endl;
    }
    cout << n << endl;
    return 0;
}