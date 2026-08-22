#include <bits/stdc++.h>
using namespace std;

//given sorted arr and x, find occurrences of x
//approach : find first and last, then return difference
class Solution{
public:
    int count_occ(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;
        int last = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        if(first == -1) return 0; //return 0 if target not in nums
        low = 0;
        high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return last - first + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,3,3,3,3,4};
    int target = 4;
    cout << sol.count_occ(nums, target) << endl;;
    return 0;
}