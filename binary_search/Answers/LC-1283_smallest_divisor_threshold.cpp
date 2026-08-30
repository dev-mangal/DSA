#include <bits/stdc++.h>
using namespace std;

//given nums[], int threshold, positive int divisor, divide the whole array with it and find sum of all divisions, this sum <= threshold, find smallest such divisor
//ceiling division
class Solution{
public:
    //O(n log(max(nums))) where n = nums.size(), not max - min since low = 1
    int smallestDivisor(vector<int> &nums, int threshold){
        //smallest divisor possible is 1, for which sum = sum of entire array, so max possible sum, if this < threshold then 1 is the answer
        //greatest divisor possible as the answer is >= max element, which gives sum = nums.size(), if this > threshold then no answer exists but problem states that answer exists so we ignore this check
        int low = 1; //not min element since 1 is the smallest divisor possible, we dont have to return a number from the array
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = 0;
            for(auto it : nums){
                sum += (it + mid - 1) / mid;
                //if sum > threshold we need bigger divisor
                if(sum > threshold){
                    low = mid + 1;
                    break;
                }
            }
            if(sum <= threshold){
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;
    cout << sol.smallestDivisor(nums, threshold) << endl;
    return 0;
}