#include <bits/stdc++.h>
using namespace std;

//we can start from 2 upto sqrt(N) and if a number is a divisor we return false instantly
class Solution{
public:
    bool isPrime(int N){
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int N = 1;
    bool result = sol.isPrime(N);
    cout << result << endl;
    return 0;
}