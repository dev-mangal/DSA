#include <bits/stdc++.h>
using namespace std;

//break it into primitive parentheses strings and remove each ones outer () then return the string
//balanced ()
//return "" if already primitive i.e ()() etc.
class Solution{
public:
    //O(n), O(n)
    string removeOuterParantheses(string s){
        //remove the first ( encountered, since () are balanced, whenever the count becomes unbalanced after the removal,and we get ), we remove it, and keep doing
        string result = "";
        int count = -1;
        for(int i = 0; i < s.size(); i++){
            //count becomes -1 whenever we have removed an outer pair (), then we reset the count to 0 when we start with a new pair (
            if(s[i] == '(' && count == -1){
                count = 0;
                continue;
            }
            if(s[i] == ')' && count == 0){
                count = -1;
                continue;
            }
            if(s[i] == '('){
                count++;
                result.push_back('(');
            }
            if(s[i] == ')'){
                count--;
                result.push_back(')');
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}