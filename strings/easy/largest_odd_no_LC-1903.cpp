#include <bits/stdc++.h>
using namespace std;

//given a string num representing a large integer, return largest valued odd integer substring, empty string if doesnt exist
class Solution{
public:
    string largestOddNumber(string num){
        int n = num.length() - 1;
        for(int i = n; i >= 0; i--){
            int digit = num[i] - '0'; //convert char to int
            if(digit % 2 != 0){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main(){
    Solution sol;
    
    return 0;
}