// Sort 0s, 1s and 2s
// Question:

/*
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
*/

// Approach 1: Brute Force: Sorting : Time Complexity- O(n * log(n)) and Space Complexity-O(1)

// Approach 2: Counting 0s, 1s and 2s -Two Pass: Time Complexity- O(n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int c0 = 0, c1 = 0, c2 = 0;

    // Count 0s, 1s and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            c0 += 1;
        else if (arr[i] == 1)
            c1 += 1;
        else
            c2 += 1;
    }

    int idx = 0;
    
    // Place all the 0s
    for (int i = 0; i < c0; i++)
        arr[idx++] = 0;

    // Place all the 1s
    for (int i = 0; i < c1; i++)
        arr[idx++] = 1;

    // Place all the 2s
    for (int i = 0; i < c2; i++)
        arr[idx++] = 2;
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    sort012(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

// Approach 3: Dutch National Flag Algorithm - One Pass: Two Pass: Time Complexity- O(n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array of 0s, 1s and 2s
void sort012(vector<int> &arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements are sorted
    while (mid <= hi) {
        if (arr[mid] == 0)
            swap(arr[lo++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[hi--]);
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();

    sort012(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}