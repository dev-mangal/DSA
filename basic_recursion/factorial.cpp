#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getFactorial(int N){
        if(N == 0 || N == 1) return 1;
        return N*getFactorial(N-1);
    }
};

int main(){
    Solution sol;
    int n = 5;
    int result = sol.getFactorial(n);
    cout << result << endl;
    return 0;
}