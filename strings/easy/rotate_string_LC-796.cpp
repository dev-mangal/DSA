#include <bits/stdc++.h>
using namespace std;

//one shift means taking leftmost char and placing it on the end, return true if goal can be achieved by a certain number of shifts
class Solution{
public:
    bool rotateString(string s, string goal){
        if(s.length() != goal.length()) return false;
        int n = s.size();
        //find the index where char of s matches goal[0], then we check if rotating works
        for(int i = 0; i < n; i++){
            if(s[i] == goal[0]){
                string rotated = s.substr(i, n) + s.substr(0, i);
                if(rotated == goal) return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s = "abcde";
    string goal = "bcdea";
    bool result = sol.rotateString(s, goal);
    if(result) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}