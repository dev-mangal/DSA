#include <bits/stdc++.h>
using namespace std;

//prices[i] is the price of given stock at ith day, return the maximum profit achievable, if cant then return 0 (buy on a single day, and sell in the future)
class Solution{
public:
    //approach : rolling minimum, save the minimum value and keep iterating, store the max diff
    int maxProfit(vector<int> &prices){
        unordered_map<int, int> mp;
        int max_profit = 0;
        int min_price = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            min_price = min(prices[i], min_price);
            max_profit = max(prices[i] - min_price, max_profit);
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