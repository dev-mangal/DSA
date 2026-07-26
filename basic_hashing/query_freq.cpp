#include <bits/stdc++.h>
using namespace std;

void num_hash(){
    int n;
    cin >> n;
    int arr[n];
    //assume max value entered is 12
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //prestore, size = max value entered + 1
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        //hash stores the values as index, so we get the index using the value from arr[i]
        hash[arr[i]] += 1;
    }
    int q;
    cin >> q;

    //fetch
    while(q--){
        int num;
        cin >> num;
        cout << hash[num] << endl;
    }
}

//for uc just do 'A' instead of 'a'
void lc_char_hash(){
    string s;
    cin >> s;
    int hash[26] = {0}; //26 total lc chars

    for(int i; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c - 'a'] << endl;
    }
}

//general char hashing
void char_hash(){
    string s;
    cin >> s;
    //256 total extended ascii chars
    int hash[256] = {0}; 
    for(int i; i < s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
}

int main(){
   lc_char_hash();
}  