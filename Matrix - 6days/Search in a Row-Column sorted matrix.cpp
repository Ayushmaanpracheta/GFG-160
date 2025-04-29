// Search in a Row-Column sorted matrix
// Question:

/*
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

Examples:

Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.
Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
Output: true
Explanation: 55 is present in the matrix.
Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
Output: true
Explanation: 3 is present in the matrix.
*/

// Approach 1: Comparing with all elements: Time Complexity- O(n*m) and Space Complexity-O(1)

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // Iterate over all the elements to find x
	for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) {
        	if(mat[i][j] == x)
                return true;
        }
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}

// Approach 2: Binary Search: Time Complexity- O(n*logm) and Space Complexity-O(1)

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> &mat, int target) {
    int n = mat.size();
    int low = 0, high = n - 1;

    // Standard binary search algorithm
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (mat[mid] == target) 
            return true;  // Element found
        else if (target > mat[mid]) 
            low = mid + 1; // Search in the right half
        else 
            high = mid - 1; // Search in the left half
    }
    return false;  // Element not found
}

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size();

    // Iterate over each row and perform binary search
    for (int i = 0; i < n; i++) {
        if (binarySearch(mat[i], x)) 
            return true;  // Element found in one of the rows
    }
    
    return false;  // Element not found in any row
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}


// Approach 3: Eliminating rows or columns: Time Complexity-O(n + m) and Space Complexity-O(1)

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m - 1;
  
    while(i < n && j >= 0) {
      
        // If x > mat[i][j], then x will be greater than all elements to the left of mat[i][j] in row i, so increment i
    	if(x > mat[i][j]) {
        	i++;
        }
      
        // If x < mat[i][j], then x will be smaller than all elements to the bottom of mat[i][j] in column j, so decrement j
        else if(x < mat[i][j]) {
        	j--;
        }
      
        // If x = mat[i][j], return true
        else {
            return true;
        }
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}