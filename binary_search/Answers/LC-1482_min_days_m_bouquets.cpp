#include <bits/stdc++.h>
using namespace std;

//bloomDay[], ith flower blooms on bloomDay[i], m bouquets using k adjacent flowers, return min number of days to wait
class Solution{
public:
    //O(n log (max(bloomDay))) O(1)
    int minDays(vector<int> &bloomDay, int m, int k){
        //{1,10,3,10,2}, 3, 1
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            int countAdj = 0;
            int numBouq = 0;
            //we dont need to find if for given mid, there exists a number of days lesser than mid, we calculate that using bs
            //here we just find out if for given mid it is possible to make m bouquets in mid days
            for(auto it : bloomDay){
                //number of days to bloom less than mid means one more flower ready
                if(it <= mid){
                    countAdj++;
                }
                else{
                    countAdj = 0;
                }

                //if k adj flowers found then increase bouquet count and reset adj count
                if(countAdj == k){
                    countAdj = 0;
                    numBouq++;
                }
            }
            if(numBouq >= m){
                    ans = min(ans, mid);
                    high = mid - 1;
                }
            else low = mid + 1;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout << sol.minDays(bloomDay, m, k) << endl;
    return 0;
}