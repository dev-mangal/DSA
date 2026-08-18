#include <bits/stdc++.h>
using namespace std;

//rotate given n*n 2d image (matrix) by 90 degrees
class Solution{
public:
    //approach: copy of matrix and fill
    vector<vector<int>> brute(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> copy(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                copy[j][rows - i - 1] = matrix[i][j];
            }
        }
        return copy;
    }

    //approach: transpose and reverse the rows
    //in-place, O(n2), O(1)
    void rotate(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        //this way we skip the diagonal elements and the elements before it which are already transposed
        for(int i = 0; i < rows; i ++){
            for(int j = i + 1; j < cols; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(matrix);
    // vector<vector<int>> result = sol.brute(matrix);
    // int rows = result.size();
    // int cols = result[0].size();
    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < cols; j++){
    //         cout << result[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}