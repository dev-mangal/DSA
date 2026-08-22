#include <bits/stdc++.h>
using namespace std;

//find the first and last occurrence of target in given sorted array, if not present return [-1,-1] (O(logn))
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        int low = 0;
        int high = nums.size() - 1;
        //find first occurrence by going left and seeing if duplicate exists
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                result[0] = mid; //store potential first occurrence
                high = mid - 1; //go left
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        //find last occurrence by going right
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                result[1] = mid;
                low = mid + 1; //go right
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,13,13,13,20,40};
    int target = 13;
    vector<int> result = sol.searchRange(nums, target);
    cout << result[0] << ' ' << result[1] << endl;
    return 0;
}