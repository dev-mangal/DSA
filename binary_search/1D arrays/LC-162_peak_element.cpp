#include <bits/stdc++.h>
using namespace std;

//return index of any element strictly greater than both its neighbours, elements outside the array considered -inf
class Solution{
public:
    int findPeakElement(vector<int> &nums){
        int n = nums.size();
        //edge cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        //if nums[mid] < nums[mid + 1], then there must be a peak in the right, since we are going uphill, and if every element increases then the last one would be peak, otherwise somewhere in the middle
        //if nums[mid] > nums[mid + 1], then peak on mid or left, since u reach the first element which may be a peak if going downhill, and if sequence changes somewhere then def a peak between first and mid element
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) return mid;
            else if(nums[mid] > nums[mid + 1]) high = mid;
            else if(nums[mid + 1] > nums[mid]) low = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}