#include <bits/stdc++.h>
using namespace std;

//given array of strings, find the longest common prefix (substring that each string STARTS with)
class Solution{
public:
    //O(n3) worst case, since find also takes O(n) worst case, and number of strings = number of chars in first string also gives n2 so total n3
    string brute(vector<string> &strs){
        //assume first string = prefix, check other ones using s.find(prefix) == 1, and keep reducing character count
        //check if first letter of each string same only then prefix can be common
        for(auto it : strs){
            if(strs[0][0] != it[0]) return "";
        }
        string prefix = strs[0];
        while(prefix != ""){
            bool prefix_found = true;
            for(auto it : strs){
                if(it.find(prefix) != 0){
                    prefix_found = false;
                    break;
                }
            }
            if(prefix_found) return prefix;
            else{
                prefix.pop_back();
            }
        }
        return prefix;
    }

    string longestCommonPrefix(vector<string> &strs){
        //find the shortest string and take as prefix
        string prefix = strs[0];
        for(auto it : strs){
            if(it.size() < prefix.size()) prefix = it;
        }
        //now we compare prefix with each string and shorten it as we go
        for(auto it : strs){
            for(int i = 0; i < prefix.size(); i++){
                if(prefix[i] != it[i]){
                    prefix = prefix.substr(0, i);
                    break;
                }
            }
        }
        return prefix;
    }
};

int main(){
    Solution sol;
    
    return 0;
}