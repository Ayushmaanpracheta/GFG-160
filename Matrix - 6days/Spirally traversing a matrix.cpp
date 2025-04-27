// Spirally traversing a matrix
// Question :

/*
You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation: 

Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
Output: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
Output: [32, 44, 27, 23, 62, 50, 28, 54]
Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].
*/

// Approach 1 : Brute Force: Using Simulation by Visited Matrix:  Time Complexity- O(m*n) and  Space Complexity-O(m*n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    vector<vector<bool> > vis(m, vector<bool>(n, false));

    // Arrays to represent the changes in row and column indices:move right(0, +1), move down(+1, 0), move left(0, -1), move  up(-1, 0)
  
    // Change in row index for each direction
    vector<int> dr = { 0, 1, 0, -1 };

    // Change in column index for each direction
    vector<int> dc = { 1, 0, -1, 0 };

    // Initial position in the matrix
    int r = 0, c = 0;

    // Initial direction index (0 corresponds to 'right')
    int idx = 0;

    for (int i = 0; i < m * n; ++i) {
        res.push_back(mat[r][c]);
        vis[r][c] = true;

        // Calculate the next cell coordinates based on current direction
        int newR = r + dr[idx];
        int newC = c + dc[idx];

        // Check if the next cell is within bounds and not visited
        if (0 <= newR && newR < m && 0 <= newC && newC < n
            && !vis[newR][newC]) {

            // Move to the next row
            r = newR;

            // Move to the next column
            c = newC;
        }
        else {

            // Change direction (turn clockwise)
            idx = (idx + 1) % 4;

            // Move to the next row according to new direction
            r += dr[idx];

            // Move to the next column according to new  direction
            c += dc[idx];
        }
    }
  
    return res;
}


int main() {
    vector<vector<int>> mat = { { 1, 2, 3, 4 },
                                    { 5, 6, 7, 8 },
                                    { 9, 10, 11, 12 },
                                    { 13, 14, 15, 16 } };

    vector<int> res = spirallyTraverse(mat);

    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}

// Approach 2: sing Boundary Traversal: Time Complexity-O(m*n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> res;

    // Initialize boundaries
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    // Iterate until all elements are printed
    while (top <= bottom && left <= right) {

        // Print top row from left to right
        for (int i = left; i <= right; ++i) {
            res.push_back(mat[top][i]);
        }
        top++;

        // Print right column from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(mat[i][right]);
        }
        right--;

        // Print bottom row from right to left (if exists)
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // Print left column from bottom to top (if exists)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return res;
}

int main() {

    vector<vector<int>> mat = {{1, 2, 3, 4}, 
                               {5, 6, 7, 8}, 
                               {9, 10, 11, 12}, 
                               {13, 14, 15, 16}};

    vector<int> res = spirallyTraverse(mat);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}