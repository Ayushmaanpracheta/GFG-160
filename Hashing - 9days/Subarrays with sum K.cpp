// Subarrays with sum K
// /Question:

/*
Given an unsorted array of integers, find the number of subarrays having sum exactly equal to a given number k.

Examples:

Input: arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
Input: arr = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
Input: arr = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.
*/

// Approach 1: Brute Force: Using Nested Loop: Time Complexity-O(n^2) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    int res = 0;

    // Pick a starting point of the subarray
    for (int s = 0; s < arr.size(); s++) {       
        int sum = 0; 
      
        // Pick an ending point
        for (int e = s; e < arr.size(); e++) {
            sum += arr[e];
            if (sum == k)
                res++;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << countSubarrays(arr, k);
    return 0;
}

// Approach 2: Using Hash Map and Prefix Sum: Time Complexity- O(n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find number of subarrays with sum as k
int countSubarrays(vector<int> &arr, int k) {
  
    // unordered_map to store prefix sums frequencies
    unordered_map<int, int> prefixSums;
  
    int res = 0;
    int currSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        
        // Add current element to sum so far.
        currSum += arr[i];

        // If currSum is equal to desired sum, then a new  subarray is found. So increase count of subarrays.
        if (currSum == k)
            res++;

        // Check if the difference exists in the prefixSums map.
        if (prefixSums.find(currSum - k) != prefixSums.end())
            res += prefixSums[currSum - k];

        // Add currSum to the set of prefix sums.
        prefixSums[currSum]++;
    }

    return res;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << countSubarrays(arr, k);
    return 0;
}