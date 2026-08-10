#include <bits/stdc++.h>
using namespace std;

//Given array, return true if array was originally sorted in non decreasing order and then rotated some x times (including zero)
//Approach : there is only 1 drop point in a correct (sorted and rotated) array, i.e only 1 point where the current element is greater than the next one, use this condition to filter out the correct arrays
class Solution {
public:
    bool check(vector<int>& nums){
        int drop = 0; //number of drop points
        for(int i = 0; i < nums.size(); i++){
            //compare with the next circular element using modulo
            //even for an already sorted array it checks the last element compared to the first one so number of drops still = 1
            //but for [1,1,1] drops = 0 so have to consider that too
            if(nums[i] > nums[(i+1)%nums.size()]) drop++;
        }
        return (drop==1 || drop == 0);
    }
};

int main(){
    Solution sol;

    return 0;
}