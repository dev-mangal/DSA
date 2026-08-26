#include <bits/stdc++.h>
using namespace std;

//every element appears twice, sorted array, find the element that appears once
class Solution{
public:
    int singleNonDuplicate(vector<int> &nums){
        //{1,1,2,3,3,4,4,8,8}
        //handle edge cases first
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        //now we dont have to worry about boundary conditions for mid
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = (low + high)/2;
            //handle unique pair case first
            if(nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) return nums[mid];
            
            //if mid even or odd, and unique element to the right
            if((mid % 2 == 0 && nums[mid + 1] == nums[mid]) || (mid % 2 != 0 && nums[mid - 1] == nums[mid])) low = mid + 1;
            else high = mid - 1;
        }
        return -1; //if no unique element
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << sol.singleNonDuplicate(nums) << endl;
    return 0;
}