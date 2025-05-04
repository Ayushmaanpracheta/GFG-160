// Two Sum - Pair with Given Sum
// Question:

/*
Given an array arr[] of positive integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

Examples:

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16.
Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11.
Input: arr[] = [11], target = 11
Output: false
Explanation: No pair is possible as only one element is present in arr[].
*/

// Approach 1: Brute Force :Generating all Possible Pairs: Time Complexity- O(n^2) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to check whether any pair exists whose sum is equal to the given target value
bool twoSum(vector<int> &arr, int target) {
    int n = arr.size();

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
      
        // For each element arr[i], check every other element arr[j] that comes after it
        for (int j = i + 1; j < n; j++) {
          
            // Check if the sum of the current pair equals the target
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
  
    // If no pair is found after checking all possibilities
    return false;
}

int main() {
  
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    // Call the twoSum function and print the result
    if(twoSum(arr, target))
      cout << "true";
    else
      cout << "false";

    return 0;
}

// Approach 2: Sorting and Binary Search: Time Complexity- O(n*log(n)) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform binary search
bool binarySearch(vector<int> &arr, int left, int right, int target){
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// Function to check whether any pair exists whose sum is equal to the given target value
bool twoSum(vector<int> &arr, int target){
    
    sort(arr.begin(), arr.end());

    // Iterate through each element in the array
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];

        // Use binary search to find the complement
        if (binarySearch(arr, i + 1, arr.size() - 1, complement))
            return true;
    }
  
    // If no pair is found
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Approach 3:  Sorting and Two-Pointer Technique: Time Complexity-O(n*log(n)) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check whether any pair exists whose sum is equal to the given target value
bool twoSum(vector<int> &arr, int target){
  
    // Sort the array
    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    // Iterate while left pointer is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)
            left++; // Move left pointer to the right
        else
            right--; // Move right pointer to the left
    }
    // If no pair is found
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    // Call the twoSum function and print the result
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Approach 4: Using Hash Set: Time Complexity-O(n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check whether any pair exists whose sum is equal to the given target value
bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    // Iterate through each element in the vector
    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}