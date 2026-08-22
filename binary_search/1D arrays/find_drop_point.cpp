#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findDrop(vector<int> &nums){
        int low = 0;
        int high = nums.size() - 1;
        int drop = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid < high && nums[mid] > nums[mid + 1]){
                drop = mid;
                break;
            }
            else if(mid > low && nums[mid-1] > nums[mid]){
                drop = mid - 1;
                break;
            }
            //mid in sorted part of array
            else{
                if(nums[mid] > nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return drop;
    }

    //better method, no need to compare adjacent values, just find if drop point to right or left of mid and when low = high that index is the drop point
    int findDrop2(vector<int> &nums){
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[high]) low = mid + 1;
            //if drop not on right of mid, then smallest element either at mid or on its left
            else high = mid;
        }
        //finds the min element i.e just after the drop
        return low;
    }
};

int main(){
    Solution sol;
    
    return 0;
}