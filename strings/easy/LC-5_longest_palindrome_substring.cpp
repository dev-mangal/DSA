#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //palindrome expands from the center, if it has odd length then middle char is center, even length then two in the middle are center, consider both cases separately
    //O(n2), O(1)
    string longestPalindrome(string s){
        int maxLen = 0;
        int start;
        for(int i = 0; i < s.size(); i++){
            //odd
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size()){
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            //breaks when left != right so we need substring from left+1, right-1
            if(right-left-1 > maxLen){
                maxLen = right-left-1;
                start = left+1;
            }

            //even
            left = i;
            right = i+1;
            while(left >= 0 && right < s.size()){
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            if(right-left-1 > maxLen){
                maxLen = right-left-1;
                start = left+1;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    Solution sol;
    string s = "babad";
    string result = sol.longestPalindrome(s);
    cout << result << endl;
    return 0;
}