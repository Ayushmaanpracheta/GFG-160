// Count pairs with given sum
// Question:

/*
Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

Examples:

Input: arr[] = [1, 5, 7, -1, 5], target = 6 
Output: 3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 
Input: arr[] = [1, 1, 1, 1], target = 2 
Output: 6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
Input: arr[] = [10, 12, 10, 15, -1], target = 125
Output: 0
 */

//  Approach 1: Brute Force : By Generating all Possible Pairs: Time Complexity- O(n^2) and Space Complexity- O(1)
 
#include <iostream>
#include <vector>
using namespace std;

// Function to count all pairs whose sum is equal to the given target value
int countPairs(vector<int> &arr, int target) {
    int n = arr.size();
    int cnt = 0;

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
      
        // For each element arr[i], check every other element arr[j] that comes after it
        for (int j = i + 1; j < n; j++) {
          
            // Check if the sum of the current pair equals the target
            if (arr[i] + arr[j] == target) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout << countPairs(arr, target) << endl;
    return 0;
}

// Approach 2:  Using Hash Map or Dictionary: Time Complexity- O(n) and Space Complexity- O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns number of pairs in arr[0...n-1] with sum equal to 'target'
int countPairs(vector<int>& arr, int target) {
    unordered_map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
      
        // Check if the complement (target - arr[i]) exists in the map. If yes, increment count
        if (freq.find(target - arr[i]) != freq.end()) {
            cnt += freq[target - arr[i]]; 
        }
      
        // Increment the frequency of arr[i]
        freq[arr[i]]++; 
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5}; 
    int target = 6; 
    cout << countPairs(arr, target);    
    return 0;
}