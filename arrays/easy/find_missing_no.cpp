#include <bits/stdc++.h>
using namespace std;

//given array of size n-1, range [1,n], find the missing number from this range
//approach : using bitwise xor, when we xor a number with itself then it is 0, and xor with 0 is the number itself, so when we xor given array with req range we get the missing number
//can also initialize hash array with 0 for req range, then for the array find the hash array freq and if it is zero return the element
class Solution{
public:
    int find_missing(vector<int> &arr){
        int range = arr.size()+1;
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 1; i <= range; i++){
            xor1 ^= i;
        }
        for(auto it : arr){
            xor2 ^= it;
        }
        return xor1 ^ xor2;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {6,2,4,5,3,1,8};
    int result = sol.find_missing(arr);
    cout << result << endl;
    return 0;
}