// Search in a sorted Matrix
// Question:

/*
Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.

Examples:

Input: mat[][] = [[1, 5, 9], [14, 20, 21], [30, 34, 43]], x = 14
Output: true
Explanation: 14 is present in the matrix, so output is true.
Input: mat[][] = [[1, 5, 9, 11], [14, 20, 21, 26], [30, 34, 43, 50]], x = 42
Output: false
Explanation: 42 is not present in the matrix.
Input: mat[][] = [[87, 96, 99], [101, 103, 111]], x = 101
Output: true
Explanation: 101 is present in the matrix.
*/

// Approach 1:Using Binary Search Twice: Time Complexity- O(logn + logm) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to binary search for x in arr[]
bool search(vector<int> &arr, int x) {
    int lo = 0, hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (x == arr[mid])
            return true;
        if (x < arr[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int lo = 0, hi = n - 1;
    int row = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        // If the first element of mid row is equal to x,return true
        if (x == mat[mid][0])
            return true;
      
        // If x is greater than first element of mid row, store the mid row and search in lower half
        if (x > mat[mid][0]) {
            row = mid;
            lo = mid + 1;
        }
      
        // If x is smaller than first element of mid row, search in upper half
        else
            hi = mid - 1;
    }
   
    // If x is smaller than all elements of mat[][]
    if (row == -1)
        return false;

    return search(mat[row], x);
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Approach 2: Using Binary Search Once: Time Complexity-O(log(n*m)) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // Find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // If x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // If x is greater than mat[row][col], search in right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // If x is less than mat[row][col], search in left half
        else 
            hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}