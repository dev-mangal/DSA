#include <bits/stdc++.h>
using namespace std;

//find sqrt of a number or the floor of sqrt using bs
class Solution{
public:
    int sqrtNo(int num){
        int low = 1;
        int high = num;
        int ans = 1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(mid * mid <= num){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int num = 28;
    cout << sol.sqrtNo(num) << endl;
    return 0;
}