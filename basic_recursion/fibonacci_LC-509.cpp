#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //given n, get F(n) (0 based indexing F(0) = 0), recursion method
    //TC = O(2^n) SC = O(n), 2^n as two function calls made and the number of calls grow exponentially as n increases (check using recursive tree)
    int getFib(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int fn = getFib(n-1) + getFib(n-2);
        return fn;
    }

    //optimal method O(n) 
    int fib(int n) {
        if(n<=1) return n; //for printing sequence, just use cout instead of return everywhere
        int a,b=0,c=1; //b is the second last number, and c is the last one, a is the current number
        for(int i=2;i<=n;i++){
            a=b+c;
            b=c;
            c=a;
        }
        return a;
    }
};

int main(){
    Solution sol;
    int n = 4;
    cout << sol.getFib(n) << endl;
    return 0;
}