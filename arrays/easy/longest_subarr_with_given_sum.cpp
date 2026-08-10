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

    //for arr containing just positive integers and zero - Sliding Window (two pointer)
    //i is the start of the subarray and j is the end, we keep increasing j, and when sum > k, we increase i to shorten the subarray from the left side, and keep repeating till j = n
    int sliding_window(int arr[], int n, int k){
        int i = 0;
        int j = 0;
        int len = 0;
        long long sum = arr[0];
        while(j < n){
            //the idea is to calc sum like a normal iteration is calculated, and just subtract arr[i] whenever i++
            //first we trim the subarray before changing the sum
            while(i <= j && sum > k){
                sum -= arr[i];
                i++;
            }
            if(sum == k) len = max(len, j-i+1);
            j++;
            if(j < n) sum += arr[j]; //we check the condition again cuz of edge case
        }
        return len;
    }
};

int main(){
    Solution sol;
    int arr[] = {1,2,-2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int arr2[] = {1,2,3,1,1,1,1};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int l = 3;
    cout << sol.longest_subarr(arr, n , k) << endl;
    cout << sol.sliding_window(arr2, m, l) << endl;
    return 0;
}