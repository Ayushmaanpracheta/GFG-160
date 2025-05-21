// Sum Pair closest to target
// Question:

/*
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.
Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.
*/

// Approach 1: Brute Force: Explore all possible pairs - O(n^2) Time and O(1) Space

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

vector<int> sumClosest(vector<int> &arr, int target) {
    int n = arr.size();

    vector<int> res;
    int minDiff = INT_MAX;

    // Generating all possible pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            int currSum = arr[i] + arr[j];
            int currDiff = abs(currSum - target);

            // if currDiff is less than minDiff, it indicates that this pair is closer to the target
            if (currDiff < minDiff) {
                minDiff = currDiff;
                res = { min(arr[i], arr[j]), max(arr[i], arr[j]) };
            }

            // if currDiff is equal to minDiff, find the one with largest absolute difference
            else if (currDiff == minDiff && 
                       (res[1] - res[0]) < abs(arr[i] - arr[j])) {
                res = { min(arr[i], arr[j]), max(arr[i], arr[j]) };
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if(res.size() > 0)
    	cout << res[0] << " " << res[1];

    return 0;
}

// Approach 2: Two Pointer Technique - O(nlogn+n) Time and O(1) Space

#include <bits/stdc++.h>
using namespace std;

// function to return the pair with sum closest to target
vector<int> sumClosest(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> res;
    int minDiff = INT_MAX;

    int left = 0, right = n - 1;

    while (left < right) {
        int currSum = arr[left] + arr[right];

        // Check if this pair is closer than the closest
        // pair so far
        if (abs(target - currSum) < minDiff) {
            minDiff = abs(target - currSum);
            res = {arr[left], arr[right]};
        }

        // If this pair has less sum, move to greater values
        if (currSum < target)
            left++;

        // If this pair has more sum, move to smaller values
        else if (currSum > target)
            right--;

        // If this pair has sum = target, return it
        else
            return res;
    }

    return res;
}

int main() {
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if(res.size() > 0)
    	cout << res[0] << " " << res[1];
    return 0;
}

class Solution {
    public:
      vector<int> sumClosest(vector<int>& arr, int target) {
          int n = arr.size();
          sort(arr.begin(), arr.end());
          vector<int> res;
          int minDiff = INT_MAX;
          int left = 0, right = n - 1;
  
          while (left < right) {
              int currsum = arr[left] + arr[right];
              int diff = abs(target - currsum);
  
              if (diff < minDiff) {
                  minDiff = diff;
                  res = {arr[left], arr[right]};
              }
  
              if (currsum < target)
                  left++;
              else if (currsum > target)
                  right--;
              else
                  return {arr[left], arr[right]}; // exact match
          }
  
          return res;
      }
  };
  