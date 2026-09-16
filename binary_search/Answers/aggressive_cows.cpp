#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxMinDistance(vector<int> &arr, int k){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1;
        int high = arr[n - 1] - arr[0];
        if(k < 2) return high;
        if(k > 2) return -1;
        int ans = INT_MAX;
        while(low <= high){
            int cow_count = 1;
            //minimum distance between cows, if arr[i] - arr[i-1] >= mid then cow can be placed
            int mid = low + (high - low)/2; 
            //the last stall where a cow was placed, we start with the first stall since that way we can place the maximum number of cows for a given mid
            int last_cow = 0; 
            for(int i = 1; i < n; i++){
                if(arr[i] - arr[last_cow] >= mid){
                    cow_count++;
                    last_cow = i;
                }
            }
            //means mid is valid answer, if cow_count > k then go right we can increase distance
            if(cow_count >= k){
                ans = min(ans, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    
    return 0;
}