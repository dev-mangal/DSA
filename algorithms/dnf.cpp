#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    //0 to low - 1 = 0, low to mid - 1 = 1, mid to high = unsorted, high + 1 to n-1 = 2
    void dnf(vector<int> &arr){
        int n = arr.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else if(arr[mid] == 2){
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr = {0,1,1,2,0,1,0,1,2,1,0,0,2,2};
    sol.dnf(arr);
    for(auto it : arr){
        cout << it << endl;
    }
    return 0;
}