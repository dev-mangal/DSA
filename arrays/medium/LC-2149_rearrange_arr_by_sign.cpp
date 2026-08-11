#include <bits/stdc++.h>
using namespace std;

//consecutive elements should have opposite signs, original order preserved, start with positive element
//array has equal number of pos and neg elements
class Solution{
public:
    //approach: two new vectors, one containing all positive, one all negative, and just traverse and add
    //O(N), O(N)
    vector<int> rearrangeArray(vector<int> &nums){
        vector<int> pos;
        vector<int> neg;
        vector<int> result;
        for(auto it : nums){
            if(it < 0) neg.push_back(it);
            else pos.push_back(it);
        }
        for(int i = 0; i < nums.size()/2; i++){
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }
        return result;
    }

    //two pointer
    vector<int> rearrangeArray1(vector<int> &nums){
        //we initialize the indexes to where we want the elements to start from, then simply insert the elements found at the correct indices in result array
        int pos = 0;
        int neg = 1;
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                result[pos] = nums[i];
                pos += 2; //alternate
            }
            else{
                result[neg] = nums[i];
                neg += 2;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,1,-2,-5,2,-4};
    vector<int> result = sol.rearrangeArray(nums);
    for(auto it : result){
        cout << it << endl;
    }
    return 0;
}