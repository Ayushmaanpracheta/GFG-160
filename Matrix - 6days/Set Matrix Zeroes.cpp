// Set Matrix Zeroes
// Question

/*
You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

Examples:

Input: mat[][] = [[1, -1, 1],
                [-1, 0, 1],
                [1, -1, 1]]
Output: [[1, 0, 1],
        [0, 0, 0],
        [1, 0, 1]]
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
Input: mat[][] = [[0, 1, 2, 0],
                [3, 4, 5, 2],
                [1, 3, 1, 5]]
Output: [[0, 0, 0, 0],
        [0, 4, 5, 0],
        [0, 3, 1, 0]]
Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
*/

// Approach 1:Brute Force: Using Two Auxiliary Arrays: Time Complexity-O(n*m) and Space Complexity-O(n+m)

#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    // To store which rows and columns are supposed to mark with zeroes
    vector<bool> rows(n, false), cols(m, false);

    // Traverse the matrix to fill rows[] and cols[]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If the cell contains zero then mark its row and column as zero
            if (mat[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Mark cell (i, j) with zero if either of rows[i] or cols[j] is true
            if (rows[i] || cols[j])
                mat[i][j] = 0;
        }
    }
}

int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Approach 2:  Using First Row and Column: Time Complexity- O(n*m) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    int c0 = 1;

    // Traverse the arr and mark first cell of each row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {

                // mark i-th row
                mat[i][0] = 0;

                // mark j-th column
                if (j == 0)
                    c0 = 0;
                else
                    mat[0][j] = 0;
            }
        }
    }

    // Traverse and mark the matrix from (1, 1) to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            // Check for col & row
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Mark the first row
    if (mat[0][0] == 0) {
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;
    }
  
    // Mark the first column
    if (c0 == 0) {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
}

int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}