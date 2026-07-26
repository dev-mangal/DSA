#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void high_low_freq(int arr[], int n){
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        //min freq is the maximum possible vaue since we compare it and decrease the value each time, opp for max freq
        //elements are zero since it doesnt matter we will update it
        int minFreq = n, maxFreq = 0;
        int maxEle = 0, minEle = 0;

        for(auto it : mp){
            int element = it.first;
            //count is the frequency of the current element
            int count = it.second;

            //updating max and min values
            if(count < minFreq){
                minFreq = count;
                minEle = element;
            }

            if(count > maxFreq){
                maxFreq = count;
                maxEle = element;
            }
        }
        cout << "max freq element : " << maxEle << endl;
        cout << "min freq element : " << minEle << endl;
    }
};

int main(){
    Solution sol;
    int arr[] = {10,13,15,12,10,15,10,13};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.high_low_freq(arr, n);
    return 0;
}