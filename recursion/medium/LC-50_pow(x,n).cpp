#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //doesnt work TLE or stack overflow
    double brute(double x, int n){
        long long exp = n;
        if (exp == 0) return 1.0;
        if (exp < 0) {
            return (1 / x) * brute(x, exp + 1);
        }
        return x * brute(x, exp - 1);
    }

    //O(logn), O(logn) since 1 recursive call
    double myPow(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n < 0){
            long long m = -n; //prevents overflow for INT_MIN
            return 1/myPow(x, m);
        }
        if(n % 2 != 0){
            return x * myPow(x, n-1);
        }
        if(n % 2 == 0){
            double res = myPow(x, n/2);
            return res * res;
        }
        return 1;
    }
};

int main(){
    Solution sol;
    cout << sol.myPow(2, 100) << endl;
    return 0;
}