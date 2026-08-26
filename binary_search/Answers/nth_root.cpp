#include <bits/stdc++.h>
using namespace std;

//return the nth root of num, if exists, otherwise return -1 (n > 0 and integer roots)
//O(log(num) * log(n)), O(1)
//if use for loop to calculate power then O(nlog(num))
class Solution{
public:
    int comparePower(int mid, int num, int n){
        int ans = 1;
        while(n > 0){
            if(n % 2 == 1){
                if(ans > num/mid) return 0; //check if multiplication causes overflow and stop before actually multiplying
                ans *= mid;
                n--;
            }
            else{
                if(mid > num/mid) return 0;
                mid *= mid;
                n /= 2;
            }
        }
        if(ans == num) return 1;
        if(ans < num) return 2;
        return 0;
    }

    int nthRoot(int num, int n){
        int low = 1;
        int high = num;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int midN = comparePower(mid, num, n);
            if(midN == 1) return mid;
            else if(midN == 2) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    cout << sol.nthRoot(27,3) << endl;
    return 0;
}