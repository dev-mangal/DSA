#include <bits/stdc++.h>
using namespace std;

//using binary exponentiation to find pow(x,n)
//for negative powers, we first take reciprocal of x, then make n positive and same code works
class Solution{
public:
    double myPow(double x, int n){
        //ans is the accumulated result, pow(x,n) == pow(x^2, n/2)
        double ans = 1;
        long long N = n; //we take long long, because for n = INT_MIN, -n would overflow (2^31) (max value is 2^31 - 1)
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        //when n becomes zero we return
        while(N > 0){
            //if n odd we multiply with x
            if(N%2 == 1){
                ans *= x;
                N--;
            }
            //if n even we sq the base and n = n/2
            else{
                x *= x;
                N = N/2;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.myPow(2,10) << endl;
    return 0;
}