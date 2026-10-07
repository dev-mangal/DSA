#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};

int main(){
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    for(auto it : s){
        cout << it << endl;
    }
    return 0;
}