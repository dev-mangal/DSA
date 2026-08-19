#include <bits/stdc++.h>
using namespace std;

//given numRows, generate the first numRows of pascal's triangle, where each element is the sum of the two directly above it
//O(n2) O(n2)
class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> matrix;
        for(int i = 0; i < numRows; i++){
            matrix.push_back(vector<int>(i+1)); //add a row with size equal to the number of row
            //initialize the first and last element of each row to 1
            matrix[i][0] = 1;
            matrix[i][matrix[i].size()-1] = 1;
        }
        for(int i = 0; i < numRows; i++){
            for(int j = 1; j < matrix[i].size() - 1; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1];
            }
        }
        return matrix;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = sol.generate(5);
    int rows = matrix.size();
    for(int i = 0; i < rows; i++){
        int cols = matrix[i].size();
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}