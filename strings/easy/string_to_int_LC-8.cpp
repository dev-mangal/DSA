#include <bits/stdc++.h>
using namespace std;

//ignore leading whitespace, only take leading +- into account, ignore leading zeros, stop reading as soon as u encounter a non digit character or a whitespace in between
//round the resulting integer to a 32 bit integer
class Solution{
public:
    //O(n), O(1)
    int myAtoi(string s){
        bool whitespace = true; //false whenever leading whitespace is passed
        bool sign = false;
        bool isneg = false;
        long long num = 0;
        int result = 0;
        //conversion begins when +- or digit encountered
        for(int i = 0; i < s.size(); i++){
            if(isspace(s[i]) && whitespace){
                continue;
            }
            if((s[i] == '+' || s[i] == '-') && !sign){
                whitespace = false;
                sign = true;
                if(s[i] == '-') isneg = true;
                continue;
            }

            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                sign = true;
                whitespace = false;
            }
            else return result;

            if(num > INT32_MAX) return isneg ? INT32_MIN : INT32_MAX;

            result = isneg ? (int) (-num) : num;
            //check if non digit, non leading whitespace, sign encountered already
            if(sign && !isdigit(s[i]) && !whitespace){
                return result;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}