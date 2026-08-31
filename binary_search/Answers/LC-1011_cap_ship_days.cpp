#include <bits/stdc++.h>
using namespace std;

//ith package has weight[i], packages shipped in the order in which they appear in array, return the min capacity of the ship to deliver the packages in 'days' days
class Solution{
public:
    //O(n log(sum(weights) - max(weights)))
    int shipWithinDays(vector<int> &weights, int days){
        //{1,2,3,4,5,6,7,8,9,10} days = 5, capacity would be 15 since {1,2,3,4,5}, {6,7}, {8}, {9}, {10}\
        //min capacity would be the max of the weights, and max would be sum of all weights
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0); //initial value 0, and then sum all from beginning to end
        int ans = INT_MAX;
        while(low <= high){
            int sum = 0;
            //go thru the array and keep adding weights till > capacity, then reset and increase day count, same as koko banana
            int cap = low + (high - low)/2;//28 14
            int countDays = 1;
            for(int i = 0; i < weights.size(); i++){
                sum += weights[i];
                
                if(sum > cap){
                    sum = weights[i]; //5 7 8 9 10
                    countDays++;//1 2 3 4 5 6
                }
            }
            //if count < days, then cap can be lower too, so check for that
            if(countDays <= days){
                ans = min(ans, cap); //28
                high = cap - 1; //27
            }
            else low = cap + 1;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << sol.shipWithinDays(weights, days) << endl;
    return 0;
}