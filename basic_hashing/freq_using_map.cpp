#include <bits/stdc++.h>
using namespace std;

void num_hash(){
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        cout << mp[num] << endl;
    }
}

void string_hash(){
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for(u_int64_t i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }

    //iterate over map
    for(auto i : mp){
        cout << i.first << "->" << i.second << endl;
    }

    // int q;
    // cin >> q;
    // while(q--){
    //     char c;
    //     cin >> c;
    //     cout << mp[c] << endl;
    // }
}

int main(){
    string_hash();
}