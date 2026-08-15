#include <bits/stdc++.h>
using namespace std;

//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's in-place

//matrix is of format matrix[row][column], vector<vector<int>> = {[1,2,3], [4,5,6], [7,8,9]};
//min tc possible is O(n2) since we need to iterate over the matrix
class Solution{
public:
    void markRow(vector<vector<int>> &matrix, int i, int cols){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = -1; //-1 is our placeholder, assume matrix has only 0s and 1s
        }
    }
    void markCol(vector<vector<int>> &matrix, int j, int rows){
        for(int i = 0; i < rows; i++){
            matrix[i][j] = -1; //-1 is our placeholder, assume matrix has only 0s and 1s
        }
    }
    //only works if matrix has limited values, and we use non conficting value as placeholder
    //O(mn * (m+n) + mn)
    void brute(vector<vector<int>> &matrix){
        //rows => matrix[..][cols]
        //cols => matrix[rows][..]
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    markRow(matrix, i, cols);
                    markCol(matrix, j, rows);
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //O(mn), O(m+n)
    void better(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> row1(rows, 0);
        vector<int> col1(cols, 0);
        for(int i = 0; i < rows; i++){
            //rows and columns marked
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    row1[i] = 1;
                    col1[j] = 1;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(row1[i] == 1 || col1[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //optimal (O(N2), O(1)), we move the rows and cols vectors into the matrix (treat first row and col as that) 
    void setZeroes(vector<vector<int>> &matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col1 = 1;
        //zero found in the first column, then col1 set to zero to make the first column zero IN THE END
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                col1 = 0;
                break;
            }
        }
        //now we need to iterate over the first row, if zero found then make matrix[0][0] = 0
        for(int j = 1; j < cols; j++){
            if(matrix[0][j] == 0){
                matrix[0][0] = 0;
                break;
            }
        }
        //the entire matrix excluding first row and column
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //first column and row now have correct 0 values, just make the matrix elements zero accordingly
        //start with inner values first since we dont want to change the 1st row and col values while iterating
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //now first row
        for(int j = 0; j < cols; j++){
            if(matrix[0][0] == 0){
                matrix[0][j] = 0;
            }
        }
        //finally first column
        if(col1 == 0){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
    } 
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    sol.setZeroes(matrix);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}