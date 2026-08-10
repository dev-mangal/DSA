#include <bits/stdc++.h>
using namespace std;

//sort array of 0s, 1s, 2s in-place
//optimal, tc O(n) and sc O(1) (in-place), using dnf (dutch national flag) algorithm
//can also just count 0 1 and 2 individually and overwrite the array in-place
class Solution{
public:
    //0 to low - 1 = 0; low to mid - 1 = 1; mid to high = unsorted; high + 1 to n-1 = 2
    void sortColors(vector<int>& nums){
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}