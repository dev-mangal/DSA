#include <bits/stdc++.h>
using namespace std;

//same reversing logic for string
class Solution{
public:
//TC and SC both O(n) since we create copies of the string

    // bool isPalindrome(string s){
    //     string copy;
    //     for(char c : s){
    //         if(isalnum(c)) copy.push_back(tolower(c));
    //         // c = tolower(c);
    //         // if(!isalnum(c)) s.erase(remove(s.begin(), s.end(), c), s.end());
    //     }
    //     string rev = copy;
    //     reverse(rev.begin(), rev.end());
    //     return copy == rev;
    // }

//Two pointer approach using O(n) and O(1)
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while (i < j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }

            if(!isalnum(s[j])){
                j--;
                continue;
            }

            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "A  BC C @A";
    bool result = sol.isPalindrome(s);
    cout << boolalpha;
    cout << result << endl;
    return 0;
}