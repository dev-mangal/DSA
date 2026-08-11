#include <bits/stdc++.h>
using namespace std;

//consecutive elements should have opposite signs, original order preserved, start with positive element
//array has equal number of pos and neg elements
class Solution{
public:
    //approach: two new vectors, one containing all positive, one all negative, and just traverse and add
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