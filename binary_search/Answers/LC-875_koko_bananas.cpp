#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //O(n * max) where n = number of piles
    int brute(vector<int> &piles, int h){
        //vector<int> piles = {30,11,23,4,20};
        //int h = 5;
        //max number of bananas that can be eaten
        int max = 1;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max) max = piles[i];
        }
        //now we have to check for each k if it is enough to finish all piles within h hrs
        //count should be less than equal to h
        for(int k = 1; k <= max; k++){
            int count = 0;
            for(int i = 0; i < piles.size(); i++){
                if(count > h) break;
                //if number of bananas <= k, then count + 1 hr, and continue to next pile
                if(piles[i] <= k){
                    count++;
                    continue;
                }
                if(piles[i] > k){
                    //if piles[i] divisible by k then just return that, otherwise koko takes another hr to finish up the remainder of the bananas
                    count += piles[i] % k == 0 ? piles[i] / k : piles[i] / k + 1;
                }
            }
            if(count <= h) return k;
        }
    }

    //O(nlog(max))
    int minEatingSpeed(vector<int> &piles, int h){
        int max = 1;
        for(auto it : piles){
            if(it > max) max = it;
        }

        //replace the range loop with binary search, rest all remains same
        int low = 1;
        int high = max;
        int ans = 0;
        while(low <= high){
            //k becomes mid here
            int mid = (low + high) / 2;
            long long count = 0;
            for(int i = 0; i < piles.size(); i++){
                //check int overflow
                if(count > h) break;
                //this works for both cases if mid > count or <= count
                //count += piles[i] % mid == 0 ? piles[i] / mid : piles[i] / mid + 1;

                //better formula is this : ceiling division
                count += (piles[i] + mid - 1) / mid;
            }
            if(count > h) low = mid + 1;
            //mid is potential answer, but there could be a lesser value than mid
            if(count <= h){
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    //we have to finish all piles in <= 5 hrs, so maximum bananas that can be eaten per hr is 30, min is 1
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}