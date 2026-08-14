#include <bits/stdc++.h>
using namespace std;

//given unsorted array, find the length of the longest consecutive sequence of numbers, they dont have to be adjacent
//brute force : linear search for x+1 for every x in the array, and keep track, wherever loop breaks (x + 1) not found then reset, O(N2), O(1)
class Solution{
public:
    //if x-1 doesnt exist then start a new sequence, and for that number check if x+1, x+2... exist using a while loop, and keep updating count, if x-1 exists then dont do anything, just skip that element
    int longest_seq(vector<int> &nums){
        if(!nums.size()) return 0;
        unordered_set<int> s;
        int longest = 1;
        for(auto it : nums){
            s.insert(it); //O(1)
        }
        //now for every nums[i] whose nums[i] - 1 doesnt exist, check if nums[i] + 1.... in set, and acc keep count
        for(int i = 0; i < nums.size(); i++){
            int count = 1;
            if(s.find(nums[i] - 1) == s.end()){
                int current = nums[i];
                while(s.find(current + 1) != s.end()){
                    count++;
                    current++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longest_seq(nums) << endl;
    return 0;
}