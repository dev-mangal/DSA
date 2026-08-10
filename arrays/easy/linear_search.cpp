#include <bits/stdc++.h>
using namespace std;

//given array and num, return the index of the num if it is present in the array, otherwise -1
class Solution{
public:
    int linear_search(vector<int> &arr, int num){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == num) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {5,4,4,1,0};
    int num = 7;
    int index = sol.linear_search(arr, num);
    cout << index << endl;
    return 0;
}