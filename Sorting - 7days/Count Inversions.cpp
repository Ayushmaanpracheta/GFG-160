// Count Inversions
// Question:
/*
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
*/

// Approach 1: Brute Force :  Using Two Nested Loops: Time Complexity-O(n^2) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to count inversions in the array
int inversionCount(vector<int> &arr) {
    int n = arr.size(); 
    int invCount = 0; 
  
    // Loop through the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
          
            // If the current element is greater than the next, increment the count
            if (arr[i] > arr[j])
                invCount++;
        }
    }
    return invCount; 
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << inversionCount(arr) << endl; 
    return 0;
}

// Approach 2: Using Merge Sort: Time Complexity-O(n*log n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
using namespace std;

// This function merges two sorted subarrays arr[l..m] and arr[m+1..r] and also counts inversions in the whole subarray arr[l..r]
int countAndMerge(vector<int>& arr, int l, int m, int r) {
  
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}

int main(){
    vector<int> arr = {4, 3, 2, 1};
    
    cout << inversionCount(arr);
    return 0;
}