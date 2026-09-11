#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //O(n3 * log(number of unique triplets)), O(2 * number of unique triplets)
    //log(no of unique triplets) since insertion in set checks if the element already exists (so it checks whether a pair exists) which takes logn time
    vector<vector<int>> brute(vector<int> &nums){
        vector<vector<int>> result;
        set<vector<int>> s;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[k] + nums[j] + nums[i] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp); //O(log(number of unique triplets))
                    }
                }
            }
        }
        result = {s.begin(), s.end()};
        return result;
    }

    //we use same approach as brute, but instead of using 3rd loop, we use twosum approach, insert elements using set and then check whether required number inside the set
    //O(n2 * log(uniqe triplets)),O(2 * unique triplets + n)
    vector<vector<int>> better(vector<int> &nums){
        set<vector<int>> st;
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++){
            set<int> hashset;
            for(int j = i + 1; j < nums.size(); j++){
                int need = -(nums[i] + nums[j]);
                if(hashset.find(need) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], need};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); //O(log(number of unique triplets))
                }
                hashset.insert(nums[j]);
            }
        }
        result = {st.begin(), st.end()};
        return result;
    }

    //O(n2 + nlogn), O(1) (excluding space taken to store result)
    //we have 2 loops, outer loop to iterate thru elements, then inner loop uses 2 sum to check if target is met
    vector<vector<int>> threeSum(vector<int> &nums){
        int target = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); //O(nlogn)
        //now for each element, we will check using two pointer approach, if the sum is greater than zero then we go left, if less than zero then we go right
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1;
            int right = nums.size() - 1;
            //skip duplicates for first element in the triplet
            if(i > 0 && nums[i] == nums[i-1]) continue;
            //use two pointer to find sum in the remaining array
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if(sum < target) left++;
                else right--;
            }
        }
        return  result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}