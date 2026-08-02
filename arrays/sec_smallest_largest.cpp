#include <bits/stdc++.h>
using namespace std;

// Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.
class Solution{
public:
    //TC: O(NlogN) (set insertions take logm time where m = current size of set) SC: O(1) 
    // void answer(int arr[], int n){
    //     set<int> s;
    //     for(int i = 0; i < n; i++){
    //         s.insert(arr[i]);
    //     }
    //     if(s.size() < 2){
    //         cout << "-1" << endl;
    //         return;
    //     }
    //     auto start = s.begin();
    //     auto last = s.end();
    //     advance(start, 1);
    //     advance(last, -2);
    //     cout << "second smallest: " << *start << " and second largest: " << *last << endl;
    // }
    void answer(int arr[], int n){
        if(n < 2){
            cout << "-1" << endl;
            return;
        }
        int small = INT_MAX;
        int second_small = INT_MAX;
        int large = INT_MIN;
        int second_large = INT_MIN;
        //we compare the values as we go and update in one traversal of the array
        for(int i = 0; i < n; i++){
            if(arr[i] < small){
                //second gets the older smallest value uptil now. and small gets the smallest value uptil now
                //by the time whole array traversed we get the correct values
                second_small = small; //intmax
                small = arr[i]; //1 
            }
            //!= condition handles duplicates
            else if(arr[i] != small && arr[i] < second_small){
                second_small = arr[i]; //2
            }

            if(arr[i] > large){
                second_large = large; //intmin 1 2 4
                large = arr[i]; //1 2 4 7 
            }
            else if(arr[i] != large && arr[i] > second_large){
                second_large = arr[i];
            }
        }
        //this if condition handles the case where they never get updated because the array has just 2 identical elements
        if(second_large == INT_MIN || second_small == INT_MAX){
            cout << "-1" << endl;
            return;
        }
        cout << "second smallest: " << second_small << " second largest: " << second_large << endl;
        cout << "smallest and largest are " << small << " and " << large << endl;
    }
};

int main(){
    Solution sol;
    int arr[] = {7,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sol.answer(arr, n);
    return 0;
}