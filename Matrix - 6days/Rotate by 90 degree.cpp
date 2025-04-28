// Rotate by 90 degree
// Question:

/*
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
*/

/*

class Solution {
    public:
      // Function to rotate matrix anticlockwise by 90 degrees.
      void rotateby90(vector<vector<int>>& mat) {
          int n = mat.size();
          
          // Step 1: Transpose the matrix
          for (int i = 0; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  swap(mat[i][j], mat[j][i]);
              }
          }
          
          // Step 2: Reverse each column
          for (int j = 0; j < n; j++) {
              int top = 0, bottom = n - 1;
              while (top < bottom) {
                  swap(mat[top][j], mat[bottom][j]);
                  top++;
                  bottom--;
              }
          }
      }
  };
  */