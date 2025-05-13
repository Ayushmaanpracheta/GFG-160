// Count Subarrays with given XOR
// Question:

/*
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
*/

// Approach 1: Brute Force: Checking all Subarray - O(n^2) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

// Function to find count of subarrays of arr with XOR value equals to K
int subarrayXor(vector<int>& arr, int k) {
    int res = 0; 

    // Pick starting point i of subarrays
    for (int i = 0; i < arr.size(); i++) {
        int prefXOR = 0; 

        // Pick ending point j of subarray for each i
        for (int j = i; j < arr.size(); j++) {
          
            // calculate prefXOR if subarray arr[i...j]
            prefXOR = prefXOR ^ arr[j];

            // If prefXOR is equal to given value,increase ans by 1.
            if (prefXOR == k)
                res++;
        }
    }
    return res;
}

int main() {
    vector<int> arr = { 4, 2, 2, 6, 4 };
    int k = 6;

    cout << subarrayXor(arr, k);
    return 0;
}

// Approach 2:  Using Hash Map and Prefix Sum: Time Complexity- O(n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the count of subarrays of arr with XOR value equals to k
int subarrayXor(vector<int>& arr, int k) {
    int res = 0; 

    // Create hash map that stores number of prefix arrays corresponding to a XOR value
    unordered_map<int, int> mp;
  
  	int prefXOR = 0;
  
    for (int val : arr) {
      
        // Find XOR of current prefix
        prefXOR ^= val;

        // If prefXOR ^ k exist in mp then there is a subarray ending at i with XOR equal to k
        res = res + mp[prefXOR ^ k];

        // If this prefix subarray has XOR equal to k
        if (prefXOR == k)
            res++;

        // Add the XOR of this subarray to the map
        mp[prefXOR]++;
    }

    // Return total count of subarrays having XOR of elements as given value k
    return res;
}

int main() {
    vector<int> arr = { 4, 2, 2, 6, 4 };
    int k = 6;

    cout << subarrayXor(arr, k);
    return 0;
}