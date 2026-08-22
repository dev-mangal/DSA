#include <bits/stdc++.h>
using namespace std;

//find out how many times array has been rotated right
//again drop point
class Solution{
public:
    int numRot(vector<int> &nums){
        int low = 0;
        int high = nums.size() - 1;
        int drop = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(mid < high && nums[mid + 1] < nums[mid]){
                drop = mid + 1;
                break;
            }
            else if(mid > low && nums[mid - 1] > nums[mid]){
                drop = mid;
                break;
            }
            else{
                if(nums[mid] > nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return drop;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << sol.numRot(nums) << endl;
    return 0;
}