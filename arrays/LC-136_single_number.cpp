#include <bits/stdc++.h>
using namespace std;

//every element appears twice except one, find that element
//using xor simply get the result in O(N), every duplicate element xor = 0
class Solution{
public:
    int singleNumber(vector<int> &nums){
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    int result = sol.singleNumber(nums);
    cout << result << endl;
    return 0;
}