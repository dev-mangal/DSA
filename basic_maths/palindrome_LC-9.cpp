#include <bits/stdc++.h>
using namespace std;

//TC = O(logx) where x = input number, SC = O(1)
//can also reverse the no and check if both equal
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        std::string str = std::to_string(x); //O(n) where n = number of digits in x
        int count = str.length();
        int i = 0;
        for(int i = 0; i < count; i++){ //O(n)
            if(str[i] != str[count - i - 1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    int result = s.isPalindrome(121);
    cout << result << endl;
}