#include <bits/stdc++.h>
using namespace std;

//beauty of string is diff bw freq of most frequently occurred char and least frequently occurred char, return sum of beauties of all substrings
//constraint: string contains only lowercase english letters (i.e vector is enough no need for map)
class Solution{
public:
    int beautySum(string s){
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxi = 0;
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                maxi = max(maxi, freq[s[j] - 'a']);
                int mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        mini = min(mini, freq[k]);
                    }
                }
                result += maxi - mini;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}