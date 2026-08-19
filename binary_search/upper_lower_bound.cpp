#include <bits/stdc++.h>
using namespace std;

//return the smallest index in a sorted array s.t arr[i] >= k, if not present then return size of array
//search for k and return, otherwise search for element just greater than k
//if we find an element greater than k, then we look to the left for an element greater than k and smaller than current
class Solution{
public:
    //this solution works, but if u have duplicates of the element or the lower bound, then it breaks, since it will return the first found element, we have to check if it has a duplicate on its left and return that lowest occurrence
    // int lower_bound(vector<int> &arr, int k){
    //     int low = 0;
    //     int high = arr.size() - 1;
    //     while(low <= high){
    //         int mid = (low + high)/2;   
    //         if(arr[mid] == k) return mid;
    //         else if(arr[mid] > k) high = mid - 1;
    //         else low = mid + 1;
    //     }
    //     return low;
    // }

    //O(logn), O(1)
    int lower_bound(vector<int> &arr, int k){
        int low = 0;
        int high = arr.size() - 1;
        //int ans = arr.size();
        while(low <= high){
            int mid = low + (high - low)/2;   
            if(arr[mid] >= k) high = mid - 1; //ans = mid;
            else low = mid + 1;
        }
        //loop breaks when low > high, so even if duplicate doesnt exist then low ends up at original value's index only
        return low; //return ans; also works 
    }

    //first index s.t arr[i] > k not >=, similar logic just one condition different
    //now if duplicate exists (k exists multiple times), we dont have to go left, we simply need to find a value greater than k so we dont care about equality, so we wont include it to the condition where we go left
    int upper_bound(vector<int> &arr, int k){
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > k) high = mid - 1;
            else low = mid + 1; //now if we have duplicate, we increase low, so we go right, and then it will stop at the value greater than k, after which high will start decreasing till high < low
        }
        return low;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,2,2,4};
    int k = 2;
    cout << sol.upper_bound(arr, k) << endl;
    return 0;
}