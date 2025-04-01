// Find Smallest Missing Positive Number:
// Question :
/*
Given an unsorted array arr[] with both positive and negative elements, the task is to find the smallest positive number missing from the array.

Note: You can modify the original array.

Examples:

Input: arr[] = {2, -3, 4, 1, 1, 7}
Output: 3
Explanation: 3 is the smallest positive number missing from the array.

Input: arr[] = {5, 3, 2, 5, 1}
Output: 4
Explanation: 4 is the smallest positive number missing from the array.

Input: arr[] = {-8, 0, -1, -4, -3}
Output: 1
Explanation: 1 is the smallest positive number missing from the array.
*/

// Approach 1: Brute Force :  By Sorting - O(n*log n) Time and O(n) Space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the first positive missing number
int missingNumber(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int res = 1;
    for (int i = 0; i < arr.size(); i++) {

        // If we have found 'res' in the array,'res' is no longer missing, so increment it
        if (arr[i] == res) 
            res++;

        // If the current element is larger than 'res','res' cannot be found in the array, so it is our final answer
        else if (arr[i] > res) 
            break;
    }
    return res;
}

int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};

    cout << missingNumber(arr);
    return 0;
}

// Approach 2: Using Visited Array - O(n) Time and O(n) Space

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr) {
    int n = arr.size();

    // To mark the occurrence of elements
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {

        // if element is in range from 1 to n then mark it as visited
        if (arr[i] > 0 && arr[i] <= n)
            vis[arr[i] - 1] = true;
    }

    // Find the first element which is unvisited in the original array
    for (int i = 1; i <= n; i++) {
        if (!vis[i - 1]) {
            return i;
        }
    }

    // if all elements from 1 to n are visited then n + 1 will be first positive missing number
    return n + 1;
}

int main() {

    vector<int> arr = {2, -3, 4, 1, 1, 7};
	cout << missingNumber(arr);
}

// Approach 3: Using Cycle Sort - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

// Function for finding the first missing positive number
int missingNumber(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {

        // if arr[i] is within range [1, n] and arr[i] is not placed at (arr[i]-1)th index in arr
        while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
                   
            // then swap arr[i] and arr[arr[i]-1] to place arr[i] to its corresponding index
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // If any number is not at its corresponding index then it is the missing number
    for (int i = 1; i <= n; i++) {
        if (i != arr[i-1]) {
            return i;
        }
    }

    // If all number from 1 to n are present then n + 1 is smallest missing number
    return n + 1;
}

int main() {
    
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
    return 0;
}