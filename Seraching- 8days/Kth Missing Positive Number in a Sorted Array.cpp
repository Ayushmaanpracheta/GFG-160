// Kth Missing Positive Number in a Sorted Array
// Question:

/*
Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  

Examples :

Input: arr[] = [2, 3, 4, 7, 11], k = 5
Output: 9
Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.
Input: arr[] = [1, 2, 3], k = 2
Output: 5
Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
Input: arr[] = [3, 5, 9, 10, 11, 12], k = 2
Output: 2
Explanation: Missing are 1, 2, 4, 6… and 2nd missing number is 2.
*/

// Approach 1: Brute Force :Using Hash Set: Time Complexity- O(n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int kthMissing(vector<int>& arr, int k) {
  
    // Insert all array elements into a set
    unordered_set<int> s(arr.begin(), arr.end());
  
    int count = 0, curr = 0;
    while (count < k) {
        curr++;
      
        // Increment missing count if current element is missing
        if (s.find(curr) == s.end()) {
            count++;
        }      
    }
    return curr;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}

// Approach 2: Using Index Comparison: Time Complexity- O(n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

int kthMissing(vector<int> &arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] > (k + i))
            return (k + i);
    }

    // If all numbers from 1 to n are present in arr[], return k + n
    return k + n;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}

// Approach 3: Using Binary Search: Time Complexity- O(log n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to find the k-th missing positive number
int kthMissing(vector<int> &arr, int k) {
    int lo = 0, hi = arr.size() - 1;
    int res = arr.size() + k;

    // Binary Search for index where arr[i] > (i + k)
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] > mid + k) {
            res = mid + k;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << kthMissing(arr, k);
    return 0;
}