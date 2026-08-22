#include <bits/stdc++.h>
using namespace std;

//array can be possibly left rotated, find target
class Solution{
public:
    //approach : find drop point using linear search, then use binary (O(n + logn)))
    int brute(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int drop = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                drop = i;
                break;
            }
        }
        if(nums[0] == target) return 0;
        if(drop != -1){
            if(nums[drop+1] == target) return drop+1;
        }
        //check if target in left side of drop point
        if(nums[0] < target){
            if(drop != -1) high = drop;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
        if(nums[drop + 1] < target){
            if(drop != -1) low = drop + 1;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }

    //optimal, O(logn)
    //approach : same thing but find drop point using binary search
    int search(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int drop = -1;

        while(low <= high){
            int mid = (low + high)/2;
            if(mid < high && nums[mid + 1] < nums[mid]){
                drop = mid;
                break;
            }
            else if(mid > low && nums[mid - 1] > nums[mid]){
                drop = mid-1;
                break;
            }
            //this means mid itself is in a sorted part of the array
            else {
                //if drop in right side of array, then nums[mid] > nums[high], otherwise in left side
                if(nums[mid] > nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        low = 0;
        high = nums.size() - 1;

        //check if the target is between 0 and drop, or between drop and high, or not even in the array
        if(drop != -1){
            if(nums[0] <= target && target <= nums[drop]){
                high = drop;
            }
            else if(nums[drop + 1] <= target && target <= nums[nums.size() - 1]){
                low = drop + 1;
            }
            else return -1;
        }
       
        //run bs for that part of the array where the target is
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    //most optimal, no need to find drop point, just check if right or left part of array is sorted (including the middle element), since one of them must be sorted, then check where target lies and do bs
    int optimal(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;

            //outer if checks which side is sorted, then inside that side it checks if target is there using nested if, then discards one of the half, and it repeatedly discards such halfs to find the target
            //check if left side sorted
            if(nums[mid] >= nums[low]){
                //check if target lies in left half
                if(nums[mid] >= target && target >= nums[low]){
                    high = mid - 1;
                }
                //else search in right half
                else low = mid + 1;
            }
            else{
                //check target lies in sorted right half
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = -1;
    cout << sol.brute(nums, target) << endl;
    return 0;
}