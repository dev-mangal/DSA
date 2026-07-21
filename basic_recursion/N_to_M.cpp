#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rev_print(int n, int m){
        if(n < m) return;
        cout << n << " ";
        rev_print(n-1, m);
    }
    void print(int m, int n){
        if(m > n) return;
        cout << m << " ";
        print(m + 1, n);
    }
};

int main(){
    Solution sol;
    sol.print(2,5);
    cout << endl;
    sol.rev_print(5,2);
    cout << endl;
    return 0;
}