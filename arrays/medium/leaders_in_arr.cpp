#include <bits/stdc++.h>
using namespace std;

//rightmost element is always a leader, then all the elements which are greater or equal to all the elements to their right are leaders
//eg : [10,22,12,3,0,6] 22 12 and 6 are leaders
class Solution{
public:
    //approach : rolling minimum, store the max value from the right and simply compare current value
    //O(N) and O(1) since we are only using a constant amount of extra space
    vector<int> leaders(vector<int> &nums){
        if(nums.empty()) return nums;
        int max_el = nums[nums.size() - 1];
        vector<int> result = {max_el};
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] >= max_el){
                result.push_back(nums[i]);
                max_el = nums[i];
            }
        }
        //if output needed in right to left order just reverse result
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {10,22,12,3,0,};
    vector<int> result = sol.leaders(nums);
    for(auto it : result){
        cout << it << endl;
    }
    return 0;
}