#include <bits/stdc++.h>
using namespace std;

//set aint better because of TC of insertion 
//TC = O(sqrt(N)), SC = O(2*sqrt(N)) (constant doesnt matter but for practice, since maximum divisors stored for each iteration are 2, so max space alloted is 2 times the number of iterations)
//only need to iterate thru sqrt(N) since after that the divisors are repeated
class Solution{
public:
    vector<int> getDivisors(int N){
        vector<int> result;
        for(int i = 1; i*i <= N; i++){
            if(N%i == 0) {
                result.push_back(i);
                if(i != N/i) result.push_back(N/i);
            }
        }
        // sort(result.begin(), result.end()); TC = O(klogk) where k = number of divisors
        return result;
    }
};

int main(){
    Solution sol;
    int N = 10;
    vector<int> result = sol.getDivisors(N);
    for(int val : result){
        cout << val << ' ';
    }
    cout << endl;
}