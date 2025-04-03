// Next Permutation:
// Question:
/*
Given an array arr[] of size n, the task is to print the lexicographically next greater permutation of the given array. If there does not exist any greater permutation, then find the lexicographically smallest permutation of the given array.

Let us understand the problem better by writing all permutations of [1, 2, 4] in lexicographical order: [1, 2, 4], [1, 4, 2], [2, 1, 4], [2, 4, 1], [4, 1, 2] and [4, 2, 1]. If we give any of the above (except the last) as input, we need to find the next one in sequence. If we give last as input, we need to return the first one.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is 2 4 5 0 1 7

Input: arr = {3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation. So, the next permutation is the lowest one.

Input: arr = [1, 3, 5, 4, 2]
Output: [1, 4, 2, 3, 5]
Explanation: The next permutation of the given array is found by rearranging the elements in the next lexicographical order.
*/

// Approach 1: Brute Force: Generating All Permutations -Time Complexity- O(n!*n*log(n!)) and Space Complexity O(n!) 

#include <bits/stdc++.h>
using namespace std;

// Generates all permutations
void permutations(vector<vector<int>>& res, vector<int>& curr, 
                  int idx);

// Function to get the next permutation
void nextPermutation(vector<int>& arr) {
  
    // Generate all permutations and store in res
    vector<vector<int>> res;
    permutations(res, arr, 0);
    sort(res.begin(), res.end());

    // Traverse through res and find the next permutation
    for (int i = 0; i < res.size(); i++) {
      
        // Found a match
        if (res[i] == arr) {
          
            // Store the next
            if (i < res.size() - 1)
                arr = res[i + 1];
          
            // If the given permutation is the last
            if (i == res.size() - 1)
                arr = res[0];
          
            break;
        }
    }
}

// Function to generate all possible permutations
void permutations(vector<vector<int>>& res, vector<int>& arr, 
                  int idx) {
  
    // Base case: if idx reaches the end of the array
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }

    // Permutations made by swapping each element starting from index `idx`
    for (int i = idx; i < arr.size(); i++) {
      
        // Swapping
        swap(arr[idx], arr[i]);

        // Recursive call to create permutations for the next element
        permutations(res, arr, idx + 1);

        // Backtracking
        swap(arr[idx], arr[i]);
    }
}

int main() {
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);
  
  	for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

// Approach 2:  Generating Only Next - Time Complexity-O(n) and Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr) {
  
    int n = arr.size(); 

     // Find the pivot index
    int pivot = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    // If pivot point does not exist, reverse the whole array
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element from the right that is greater than pivot
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Reverse the elements from pivot + 1 to the end to get the next permutation
    reverse(arr.begin() + pivot + 1, arr.end());
}

int main()
{
    vector<int> arr = { 2, 4, 1, 7, 5, 0 };
    nextPermutation(arr);    
    for (int x : arr) 
        cout << x << " ";    
    return 0;
}

// Approach 3: in-built function
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = { 2,4,1,7,5,0 };
    next_permutation(arr.begin(), arr.end());
    for (int num : arr)
        cout << num << " ";
    return 0;
}