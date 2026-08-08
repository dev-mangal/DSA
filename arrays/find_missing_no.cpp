#include <bits/stdc++.h>
using namespace std;

//given array of size n-1, range [1,n], find the missing number from this range
//approach : sum of first n elements - sum of array (O(N), O(1)) might overflow for large integers
class Solution{
public:
    int find_missing(vector<int> &arr){
        int range = arr.size()+1;
        int req_sum = range*(range+1)/2;
        int sum = 0;
        for(auto it : arr){
            sum += it;
        }
        return req_sum - sum;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {6,2,4,5,3,7,8};
    int result = sol.find_missing(arr);
    cout << result << endl;
    return 0;
}