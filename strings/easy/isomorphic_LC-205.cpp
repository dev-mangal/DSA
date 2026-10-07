#include <bits/stdc++.h>
using namespace std;

//two strings are isomorphic if char in s can be replaced to get t, like egg and add are, f11 b23 arent since 1 cant be both mapped to 2 and 3 simultaneously
//assume they have same length
//same character from different strings can be mapped differently, ex "paper" and "title" true, so here paper e is mapped to l, but title e is mapped to r, so we need two maps instead of one, one for s to t mapping and one for t to s mapping
class Solution{
public:
    //O(n)
    bool isIsomorphic(string s, string t){
        if(s.length() != t.length()) return false;
        //we map characters from both strings and store them in hashmap, then check their occurrences
        unordered_map<char, char> mps;
        unordered_map<char, char> mpt;
        for(int i = 0; i < s.size(); i++){
            //this checks if mapping already exists and current character is not equal to that mapping then isomorphism is not possible.
            //we need to check in both directions, since we need to prevent two char from s mapping to same char in t, like for abc to add we need to prevent b->d and c->d together
            if(mps.count(s[i]) && mps[s[i]] != t[i]) return false;
            if(mpt.count(t[i]) && mpt[t[i]] != s[i]) return false;
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return true;
    }
};

int main(){
    Solution sol;
    
    return 0;
}