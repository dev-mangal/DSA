#include <bits/stdc++.h>
using namespace std;

//prices[i] is the price of given stock at ith day, return the maximum profit achievable, if cant then return 0 (buy on a single day, and sell in the future)
class Solution{
public:
    //approach : prefix, basically for every element find the previous minimum element and store the difference, then get max difference
    //either using nested loop or store {index,value} in map and use if condition
    int maxProfit(vector<int> &prices){
        unordered_map<int, int> mp;
        int max_profit = 0;
        int max_value = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j] > prices[i]){
                    max_value = max(prices[j], max_value);
                    max_profit = max(max_value - prices[i], max_profit);
                }
            }
        }
        return max_profit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {2,1,2,0,1};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}