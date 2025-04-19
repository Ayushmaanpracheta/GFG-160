// Sorted and Rotated Minimum
// Question:

/*
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
*/

// Approach 1: Brute Force: Linear Search - Time Complexity-O(n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& arr) {
  
    int res = arr[0];

    // Traverse over arr[] to find minimum element
    for (int i = 1; i < arr.size(); i++) 
        res = min(res, arr[i]);

    return res;
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    int n = arr.size();

    cout << findMin(arr) << endl;
    return 0;
}

// Approach 2: Binary Search: Time Complexity-O(log n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr) {
    int lo = 0, hi = arr.size() - 1;

    while (lo < hi) {
      
        // The current subarray is already sorted,the minimum is at the low index
        if (arr[lo] < arr[hi])        
            return arr[lo];
           
        // We reach here when we have at least two elements and the current subarray is rotated
      
        int mid = (lo + hi) / 2;

        // The right half is not sorted. So the minimum element must be in the right half.
        if (arr[mid] > arr[hi])
            lo = mid + 1;
      
        // The right half is sorted. Note that in this case, we do not change high to mid - 1 but keep it to mid. As the mid element itself can be the smallest
        else
            hi = mid;
    }

    return arr[lo]; 
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << findMin(arr) << endl;
    return 0;
}