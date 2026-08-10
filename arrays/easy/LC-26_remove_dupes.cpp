#include <bits/stdc++.h>
using namespace std;

//given a non decreasing sorted array, remove duplicates in-place preserving the original order, and return the number of distinct values
class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            //we take a count in i, then for each value after it, we compare, if it is not equal then advance i and update values, if equal then loop skips and then i becomes 2 less than j so duplicate values handled easily
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,2,3,5,5};
    int n = sol.removeDuplicates(arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << n << endl;
    return 0;
}