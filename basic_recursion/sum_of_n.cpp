#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getSum(int n){
        if (n == 1) return 1;
        return n + getSum(n-1);
    }
};

int main(){
    Solution sol;
    int sum = sol.getSum(5);
    cout << sum << endl;
    return 0;
}