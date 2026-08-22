#include <bits/stdc++.h>
using namespace std;

//may contain duplicates, return true if target in nums
class Solution{
public:
    //handle duplicates in the same code
    bool search(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return true;

            // if(nums[mid] == nums[low]) low++;
            // else if(nums[mid] == nums[high]) high--;
            //above code works, we shrink array element by element, but below one is better
            //only ambiguous case is when all 3 equal eg: [3, 3, 1, 2, 3, 3], since we cant know which side is sorted (in case of 2 equal we know that side is sorted eg: [1, 1, 2, 3, 4, 5], which is why using just this condition works)
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            else if(nums[mid] >= nums[low]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else{
                if(target <= nums[high] && target >= nums[mid]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,0,1,1,1};
    int target = 0;
    bool result = sol.search(nums, target);

    if(result) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}