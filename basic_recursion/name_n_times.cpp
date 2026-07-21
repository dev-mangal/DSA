#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void getName(int N){
        if (N == 0) return;

        cout << "Dev" << endl;
        getName(N-1);
    }
};

int main(){
    Solution sol;
    sol.getName(5);
    return 0;
}