#include <bits/stdc++.h>
using namespace std;

//sort the string in decreasing order of the frequency of characters
class Solution{
public:
    string frequencySort(string s){
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        //the anonymous function (lambda comparator) takes two pairs and compares them based on what we say
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        //the vector is now sorted, we just need to attach it into a string
        string result = "";
        for(auto &it : vec){
            result.append(it.second, it.first);
        }
        return result;
    }
};

int main(){
    Solution sol;
    
    return 0;
}