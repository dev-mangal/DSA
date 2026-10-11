#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //O(n), O(1)
    //otherwise just do using if else bruh
    int romanToInt(string s){
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        //number subtracted for six cases when some roman to the left of other roman, otherwise added, so we go right to left
        // for(int i = s.size() - 1; i > 0; i--){
            
        // }
        // int prev = mp[s[0]]; //stores the previous int value, if this is smaller than the next one then this needs to be subtracted
        // for(int i = 1; i < s.size(); i++){ // i = 3, 4
        //     if(prev < mp[s[i]]){
        //         result += mp[s[i]] - prev;
        //         continue;
        //     }
        //     //handle the last digit if it is normal
        //     else if(i == s.size() - 1){
        //         result += mp[s[i]] + prev;
        //     }
        //     else{
        //         result += prev; //55, 56
        //         prev = mp[s[i]]; //5, 1, 1
        //     }
        // }

        //just add every element and remove it if it needs to be subtracted later bruh by storing it in prev each time
        int prev = mp[s[0]];
        result += prev;
        for(int i = 1; i < s.size(); i++){
            if(prev < mp[s[i]]){
                result += mp[s[i]] - 2*prev;
            }
            else result += mp[s[i]];
            prev = mp[s[i]];
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s = "LVIII";
    int result = sol.romanToInt(s);
    cout << result << endl;
    return 0;
}