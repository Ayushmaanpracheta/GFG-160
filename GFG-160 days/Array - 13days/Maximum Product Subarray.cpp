// Maximum Product Subarray:
// Question:
/*
Given an integer array, the task is to find the maximum product of any subarray.

Examples:

Input: arr[] = {-2, 6, -3, -10, 0, 2}
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180

Input: arr[] = {-1, -3, -10, 0, 60}
Output: 60
Explanation: The subarray with maximum product is {60}.
*/

// Approach 1:Brute Force:By using two nested loops : Time Complexity -O(n^2) , Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to return the product of max product subarray
int maxProduct(vector<int> &arr) {
    int n = arr.size();
  
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int mul = 1;
      
        // traversing in current subarray
        for (int j = i; j < n; j++) {
          	mul *= arr[j];
          
            // updating result every time to keep track of the maximum product
            result = max(result, mul);
        }
    }
    return result;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}

// Approach 2: Using minimum and maximum product ending at any index : Time Complexity -O(n) , Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

// function to find the product of max product subarray
int maxProduct(vector<int> &arr) {
  	int n = arr.size();
  
    // max product ending at the current index
    int currMax = arr[0];

    // min product ending at the current index
    int currMin = arr[0];

    // Initialize overall max product
    int maxProd = arr[0];
  
    // Iterate through the array 
    for (int i = 1; i < n; i++) {
      	
      	// Temporary variable to store the maximum product ending at the current index
        int temp = max({ arr[i], arr[i] * currMax,
                        					arr[i] * currMin });
        
      	// Update the minimum product ending at the current index
      	currMin = min({ arr[i], arr[i] * currMax,
                    						arr[i] * currMin });
      
      	// Update the maximum product ending at the current index
        currMax = temp;
      
      	// Update the overall maximum product
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}

// Approach 3:  By traversing in both directions: Time Complexity -O(n) , Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

// function to find the product of max product subarray.
int maxProduct(vector<int> &arr) {
  	int n = arr.size();
    int maxProd = INT_MIN;
  
    // leftToRight to store product from left to Right
    int leftToRight = 1;
  
    // rightToLeft to store product from right to left
    int rightToLeft = 1;
  
    for (int i = 0; i < n; i++) {
        if (leftToRight == 0)
            leftToRight = 1;
        if (rightToLeft == 0)
            rightToLeft = 1;
      
        // calculate product from index left to right
        leftToRight *= arr[i];
      
        // calculate product from index right to left
        int j = n - i - 1;
        rightToLeft *= arr[j];
        maxProd = max({leftToRight, rightToLeft, maxProd});
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}