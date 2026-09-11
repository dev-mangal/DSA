#include <bits/stdc++.h>
using namespace std;

//given arr[] in strictly increasing order, return kth positive number missing from array
//eg: arr = [2,3,4,7,11] k = 5; then missing number is [1,5,6,8,9,10,12,13...] so 5th is 9
//approach: for each mid using bs, find out the number of missing elements before it using number = arr[i] - (i + 1)
class Solution{
public:
    int brute(vector<int> vec, int n, int k) {
        for (int i = 0; i < n; i++) {
            if (vec[i] <= k) {
                k++;  // If current number is less than or equal to k, increment k
            } else {
                break; // Stop when we reach a number greater than k
            }
        }
        return k;  // Return the final value of k which is the missing number
    }

    int findKthPositive(vector<int> &arr, int k){
        int low = 0;
        int high = arr.size() - 1;
        //we find the element where number of missing integers before it are just >= k
        while(low <= high){
            int no_missing = 0;
            int mid = low + (high - low)/2;
            no_missing = arr[mid] - (mid + 1); //gives number of missing elements before mid
            if(no_missing < k) low = mid + 1; //we need to go right to expand search space
            else if(no_missing >= k) high = mid - 1;
        }
        //now when low > high, loop finishes, and low lies at the first element where no_missing >= k, and high lies right before low, therefore the one where no_missing < k
        //so we just find out m = how many missing before high, and then add k-m to high
        //if array has consecutive numbers like [1,2,3,4] then high ends up at 4, so this works again
        //boundary condition, when the first element is greater than the kth missing number, i.e it has k missing numbers before it then low = 0 and high = -1, which is invalid, so for high = -1, the answer is simply k
        if(high == -1) return k;
        int m = arr[high] - (high + 1);
        return arr[high] + k - m;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout << sol.findKthPositive(arr, k) << endl;
    return 0;
}