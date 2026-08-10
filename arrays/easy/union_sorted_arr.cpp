#include <bits/stdc++.h>
using namespace std;

//two sorted arrays of size m and n, print union of the two in increasing order
//two pointer approach (O(M+N), O(M+N)), set(O((M+N)log(M+N))), map(O((N+M)log(N+M)))
class Solution{
public:
    void union_sorted(vector<int> &arr1, int m, vector<int> &arr2, int n){
        //{1,2,3,4} {2,3,4,6,9}
        vector<int> union_arr{};
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(arr1[i] < arr2[j]){
                //condition to check if the union is empty or given array doesnt contain duplicates only then insert the current one
                if(union_arr.empty() || union_arr.back() != arr1[i])
                    union_arr.push_back(arr1[i]);
                i++; //increment outside the condition since if duplicate found then also it has to incremet without inserting the element otherwise infinite loop
            }
            else if(arr2[j] < arr1[i]){
                if(union_arr.empty() || union_arr.back() != arr2[j])
                    union_arr.push_back(arr2[j]);
                j++;
            }
            else{
                if(union_arr.empty() || union_arr.back() != arr1[i])
                    union_arr.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        while(i < m){
            if(union_arr.empty() || union_arr.back() != arr1[i])
                union_arr.push_back(arr1[i]);
            i++;
        }
        while(j < n){
            if(union_arr.empty() || union_arr.back() != arr2[j])
                union_arr.push_back(arr2[j]);
            j++;
        }
        for(auto it : union_arr){
            cout << it << endl;
        }
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {1,2,2,3,4};
    int m = arr1.size();
    vector<int> arr2 = {2,3,4,6,9};
    int n = arr2.size();
    sol.union_sorted(arr1, m, arr2, n);
    return 0;
}