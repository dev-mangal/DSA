#include <bits/stdc++.h>
using namespace std;

//low mid high, change high and low acc to if arr[mid] == target or > or < 
//O(logn), O(1)
class Solution{
public:
    int search(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        //if high < low then element not found
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1; //means element is to the right of mid so remove left side search space
            else high = mid - 1;
        }
        return -1; //when element not found
    }

    //recursive definition
    int search_rec(vector<int> &nums, int target, int low, int high){
        if(high < low) return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return search_rec(nums, target, mid + 1, high);
        else return search_rec(nums, target, low, mid - 1);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,5,7,9,13};
    cout << sol.search(nums, 6) << endl;
    cout << sol.search_rec(nums, 6, 0, nums.size() - 1) << endl;
    return 0;
}