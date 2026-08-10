#include <bits/stdc++.h>
using namespace std;

//Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
//subarray should be continuous
class Solution{
public:
    //approach : we find the sums upto i and store them, if we have current sum - any prev sum = k then we find the difference between the two indices and store them, return the max value of this diff
    //O(n) (avg) O(n2) (worst case when mp.count takes O(n)), O(n)
    int longest_subarr(int arr[], int n, int k){
        unordered_map<int, int> mp; //stores {sum,index}
        int sum = 0;
        int prev_index = 0;
        int length = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k) length = max(length, i + 1);
            //sum - prevsum = k so if prev sum exists in map we can get the index and length
            int prev_sum = sum - k;
            if(mp.count(prev_sum)) {
                prev_index = mp[prev_sum];
                if(i - prev_index > length) length = i - prev_index;
            }
            //if we remove the if condition then the code breaks for the given test case, since we need the first index of the prevsum, not the latest one for the max length, by the time we reach the last element the prev sum index would be overwritten for repeated values of the prev sum, so if it already exists then no need to change the index
            if(!mp.count(sum))  mp[sum] = i; 
        }
        return length;
    }
};

int main(){
    Solution sol;
    int arr[] = {2,0,0,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << sol.longest_subarr(arr, n , k) << endl;
    return 0;
}