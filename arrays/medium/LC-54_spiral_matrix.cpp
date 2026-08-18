#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        vector<int> result = {};
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        //when all equal for odd sized array then this will print center element 4 times
        //top = 0; left = 0; right = 3; bottom = 2;
        //jaise hi top = left, then dont execute top + 1 vala loop
        //top = bottom dont execute right - 1 vala loop
        //left = right dont execute one of the top + 1 or bottom - 1 vala loops
        while(top <= bottom && left <= right){
            for(int j = left; j <= right; j++){
                result.push_back(matrix[top][j]);
            }
            for(int i = top + 1; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            for(int j = right - 1; j >= left; j--){
                if(top == bottom) break;
                result.push_back(matrix[bottom][j]);
            }
            for(int i = bottom - 1; i > top; i--){
                if(left == right) break;
                result.push_back(matrix[i][left]);
            }
            top++; left++; right--; bottom--;
        //top = 1; left = 1; bottom = 1; right = 2;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    vector<int> result = sol.spiralOrder(matrix);
    for(auto it : result){
        cout << it << ' ';
    }
    return 0;
}