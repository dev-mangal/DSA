#include <bits/stdc++.h>
using namespace std;

//find the minimum element of a rotated sorted array
class Solution{
public:
    //approach : just find the drop point bruh
    int findMin(vector<int> &nums){
        int low = 0;
        int high = nums.size() - 1;
        int drop = 0;
        //if nums sorted then this loop doesnt run so drop remains 0 i.e first element
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid < high && nums[mid] > nums[mid + 1]){
                drop = mid + 1;
                break;
            }
            else if(mid > low && nums[mid-1] > nums[mid]){
                drop = mid;
                break;
            }
            //mid in sorted part of array
            else{
                if(nums[mid] > nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return nums[drop];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << endl;
    return 0;
}