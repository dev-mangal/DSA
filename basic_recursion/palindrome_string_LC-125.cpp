#include <bits/stdc++.h>
using namespace std;

//same reversing logic for string
class Solution{
public:
    bool isPalindrome(string s){
        string copy;
        for(char c : s){
            if(isalnum(c)) copy.push_back(tolower(c));
            // c = tolower(c);
            // if(!isalnum(c)) s.erase(remove(s.begin(), s.end(), c), s.end());
        }
        string rev = copy;
        reverse(rev.begin(), rev.end());
        return copy == rev;
    }
};

int main(){
    Solution sol;
    string s = "A  BC b @A";
    bool result = sol.isPalindrome(s);
    cout << boolalpha;
    cout << result << endl;
    return 0;
}