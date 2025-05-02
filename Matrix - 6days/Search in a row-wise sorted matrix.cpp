// Search in a row-wise sorted matrix
// Question:

/*
Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

Examples :

Input: mat[][] = [[3, 4, 9],[2, 5, 6],[9, 25, 27]], x = 9
Output: true
Explanation: 9 is present in the matrix, so the output is true.
Input: mat[][] = [[19, 22, 27, 38, 55, 67]], x = 56
Output: false
Explanation: 56 is not present in the matrix, so the output is false.
Input: mat[][] = [[1, 2, 9],[65, 69, 75]], x = 91
Output: false
Explanation: 91 is not present in the matrix.
*/

// Approach 1: Using Binary Search: Time Complexity- O(n * log(m)) and Space Complexity-O(1)

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &arr, int x) {
	int lo = 0, hi = arr.size();
    while(lo <= hi) {
    	int mid = (lo + hi) / 2;
      
        // If x = mid, return true
        if(x == arr[mid]) 
            return true;
      
        // If x < arr[mid], search in left half
        if(x < arr[mid])
            hi = mid - 1;
       
        // If x > arr[mid], search in right half
        else
            lo = mid + 1;
    }
    return false;
}

bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // Iterate over all the rows to find x
    for(int i = 0; i < n; i++) {
      
        // binary search on ith row
        if(search(mat[i], x))
        	return true;
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(searchRowMatrix(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}


/*
class Solution {
  public:
    // Function to search a given number in row-wise sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        for (const auto& row : mat) {
            int low = 0, high = row.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (row[mid] == x)
                    return true;
                else if (row[mid] < x)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
*/
  