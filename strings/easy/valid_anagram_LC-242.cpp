#include <bits/stdc++.h>
using namespace std;

//anagram is when rearranging the char exactly once gives the other string
class Solution{
public:
    //O(N) O(26) (since 26 character fixed lower alphabet letters)
    bool better(string s, string t){
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for(int i = 0; i < s.size(); i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(mps[s[i]] != mpt[s[i]]) return false;
        }
        return true;
    }

    //O(nlogn)
    bool brute(string s, string t){
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;
    }

    //we dont need two maps we can use one map, or even better since character set is fixed we can use one fixed size vector
    //O(n) O(1)
    //if we had unicode characters instead of fixed set, then we cant use vector but map method still works, we just have to decode the unicode characters in some way since some of them take 2 bytes of space etc.., so decode them using an external library into unordered_map<char, int>
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++){
            //we convert alphabets to integers 1-26
            int n = s[i] - 'a';
            int m = t[i] - 'a';
            freq[n] ++;
            freq[m] --;
        }
        //if the frequencies are equal then all elements in the vector should be 0
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    
    return 0;
}