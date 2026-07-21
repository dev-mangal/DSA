#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //swapping using 2 pointers
    void revArr(vector<int>& arr){
        int count = arr.size();
        int p1 = 0;
        int p2 = count - 1;
        while(p1 < p2){
            swap(arr[p1], arr[p2]);
            p1++;
            p2--;
        }
        //using STL
        //reverse(arr.begin(), arr.end());
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,2,3,4,5};
    sol.revArr(v);
    for(int val : v){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}