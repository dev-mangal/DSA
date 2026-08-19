#include <bits/stdc++.h>
using namespace std;

//given sorted array, return the floor and ceil of target in array, if target present then floor and ceil = target
class Solution{
public:
    //approach : find upper bound and print index and index - 1, if element found simply print twice
    //can also do using reverse of upper bound method, for <=, so if element less than target found, search the right side for another potential answer, for floor, and for ceil it remains the same as upper bound
    void floor_ceil(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                cout << "floor: " << target << ' ' << "ceil: " << target << endl;
                return;
            }
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        //if target greater than all elements then low = arr.size()
        if(low == nums.size()){
            cout << "floor: " << nums[low-1] << ' ' << "ceil: -1" << endl;
            return;
        }
        //if target smaller than all elements then low = 0;
        if(low == 0){
            cout << "floor: -1 " << "ceil: " << nums[low] << endl; 
            return;
        }
        cout << "floor: " << nums[low-1] << ' ' << "ceil: " << nums[low] << endl;
        return;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,4,7,8,10};
    int target = 2;
    sol.floor_ceil(nums, target);
    return 0;
}