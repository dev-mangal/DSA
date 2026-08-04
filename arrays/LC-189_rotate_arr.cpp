#include <bits/stdc++.h>
using namespace std;

//rotate given array by k steps to the right
//3 ways
class Solution{
public:
    //make temp array and use rotation formula (using modulo) to get the values at correct places
    //tc = O(N), sc = O(N)
    void rotate1(vector<int>& nums, int k){
        if(nums.empty()) return;
        k %= nums.size();
        vector<int> temp = nums;
        for(int i = 0; i < nums.size(); i++){
            temp[i] = nums[(i+nums.size()-k) % nums.size()]; //i+k for left rot
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = temp[i];
        }
    }

    //reverse the array then reverse particular elements to get desired order using reverse(O(n))
    //reverse[start iterator, end iterator)
    //tc = O(n), sc = O(1)
    void rotate2(vector<int>& nums, int k){
        //nums = {1,2,3,4,5} rotated right by k = 3 => {3,4,5,1,2} left = {4,5,1,2,3}
        if(nums.empty()) return;
        k %= nums.size();
        reverse(nums.begin(), nums.end()); //{5,4,3,2,1}
        reverse(nums.begin(), nums.begin() + k); //{3,4,5,2,1}
        reverse(nums.begin() + k, nums.end()); //{3,4,5,1,2}
    }

    //store the first element in a temp var, then just equate values accordingly in original array and store the temp var value in the last for rotation = 1
    //for k rotations store the first k values then insert them in order at the end
    void rotate3(vector<int> &nums, int k){
        //for {1,2,3,4,5} k = 2 final result = {4,5,1,2,3}
        if(nums.empty()) return;
        k %= nums.size();
        vector<int> temp; //no need for fixed size since we managing that in the loop
        for(int i = 0; i < nums.size() - k; i++){
            temp.push_back(nums[i]); //temp = {1,2,3}
        }
        for(int i = nums.size() - k; i < nums.size(); i++){
            nums[i-nums.size()+k] = nums[i]; //nums[0] = nums[3], nums[1] = nums[4] => nums = {4,5,3,4,5}
        }
        for(int i = k; i < nums.size(); i++){
            nums[i] = temp[i-k];
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    sol.rotate3(nums, 2);
    for(auto it : nums){
        cout << it << endl;
    }
    return 0;
}