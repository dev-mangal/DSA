#include <bits/stdc++.h>
using namespace std;

//return index if found, if not then return the index where we should insert to keep it sorted (in O(logn))
class Solution{
public:
    //approach : literally lower bound problem
    int searchInsert(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target) high = mid - 1;
            else low = mid + 1 ;
        }
        return low;
    }
};

int main(){
    Solution sol;
    
    return 0;
}