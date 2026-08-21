#include <bits/stdc++.h>
using namespace std;

//find the number of elements appearing more than n/3 times
//at most 2 elements appearing more than n/3 times
class Solution{
public:
    vector<int> brute(vector<int> &nums){
        int majority = nums.size() / 3;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            for(int j = i; j < nums.size(); j++){
                if(nums[j] == nums[i]) cnt++;
            }
            if(cnt > majority && count(result.begin(), result.end(), nums[i]) == 0) result.push_back(nums[i]);
        }
        return result;
    }
    //better would be using a map to store elements and freq, O(nlogn) and O(n)
    
    //we do count++ -- and element = arr[i] when count = 0 for n/2 (moore majority algo)
    //try similar here using 2 counts and elements
    //we cancel out 3 distinct elements, not when current = one of the candidates
    vector<int> majorityElement(vector<int> &nums){
        vector<int> result;
        int cnt1 = 0;
        int cnt2 = 0;
        int element1 = 0;
        int element2 = 0;
        //only decrease counts when current not equal to either candidate
        for(int i = 0; i < nums.size(); i++){
            int current = nums[i];
            if(current == element1) cnt1++;
            else if(current == element2) cnt2++;
            else if(cnt1 == 0){
                element1 = current;
                cnt1++;
            }
            else if(cnt2 == 0){
                element2 = current;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //verify if their counts actually > n/3
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element1) cnt1++;
            else if(nums[i] == element2) cnt2++;
        }
        if(cnt1 > nums.size() / 3) result.push_back(element1);
        if(cnt2 > nums.size() / 3) result.push_back(element2);

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,3,1,1,1,2,2,2};
    vector<int> result = sol.majorityElement(nums);
    for(auto it : result) cout << it << endl;
    return 0;
}