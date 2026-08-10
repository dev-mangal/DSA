#include <bits/stdc++.h>
using namespace std;

//given array, find the number that appears more than n/2 times
class Solution{
public:
    //approach : simply use map and check freq > n/2 return
    //o(n), o(n)
    int majorityElement(vector<int> &nums){
        unordered_map<int, int> mp;
        int result = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second > n / 2) result = it.first;
        }
        return result;
    }

    //count, element; current != element -> count --, current = element -> count ++, count = 0 -> current = element
    //O(N), O(1)
    int moore_voting(vector<int> &nums){
        int n = nums.size();
        int count = 0;
        int element;
        for(int i = 0; i < n; i++){
            if(count == 0){
                count ++;
                element = nums[i];
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        //if it is not guaranteed that majority element exists in the array then need to check
        int count_el = 0;
        for(auto it : nums){
            if(it == element){
                count_el++;
            }
        }
        if(count_el > n/2) return element;
        return 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3};
    cout << sol.moore_voting(nums) << endl; 
    return 0;
}