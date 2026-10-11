#include <bits/stdc++.h>
using namespace std;

//tell the max nesting depth of a string ex: (1+(2*3)+((8)/4))+1, 8 is nested inside 3 ()
class Solution{
public:
    int maxDepth(string s){
        int count = 0;
        int result = 0;
        for(auto it : s){
            if(it == '('){
                count++;
                result = max(result, count);
            }
            if(it == ')') count--;
        }
        return result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}