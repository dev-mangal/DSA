#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int bookAllocate(vector<int> &arr, int  m){
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        if(m > arr.size()) return -1;
        if(arr.size() == m) return low;
        if(m == 1) return high;
        long long ans = -1;
        //use the max number of pages allotted as mid, this mid should be minimum
        //if books left, then mid needs to increase, if no books left and children left, then mid needs to decrease
        while(low <= high){
            long long numAlloc = 1; //we are assigning the student available, so first student is ready to receive, after assigned the second student is ready to receive and so on
            long long mid = low + (high - low)/2;
            long long pages = 0;
            //we allocate the books whenever the sum of pages allocated increases the max possible
            //so we are assigning each student with max possible contiguous books, now we check if all students are covered
            for(int i = 0; i < arr.size(); i++){
                pages += arr[i];
                if(pages > mid){
                    pages = arr[i];
                    numAlloc++;
                }
            }
            //if students allocated are more than allowed, then we need to increase max possible pages 
            if(numAlloc > m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
                ans = mid; //we are taking mid here, since if our algo uses m-1 students (< m), then one of the student's books can be divided further to achieve that m, so mid is a possible answer and we are checking if we can go lower
                //if mid goes lower then numAlloc increases and whenever > m we reduce the search space further so as long as numAlloc < m mid remains feasible
            }
        }
        return ans; //can return low directly
        //mid remains feasible ans as long as numAlloc (number of students required to allocate closest to <= mid pages per student) < m. since we increase numAlloc only when pages > mid we can divide those further into more students as long as we need to get m students
        //so we keep that mid as feasible, and we can go even lower using the same logic, and whenever infeasible, low increases, at one point low > high, where low is the lowest feasible answer, and high is the lowest infeasible answer, so we get low
    }
};

int main(){
    Solution sol;
    vector<int> arr = {15,10,19,10,5,18,7};
    int m = 5;
    cout << sol.bookAllocate(arr, m) << endl;
    return 0;
}