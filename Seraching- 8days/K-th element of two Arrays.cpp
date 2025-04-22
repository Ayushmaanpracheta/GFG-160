// K-th element of two Arrays
// Question:

/*
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
*/

// Approach 1: Brute Force: Using Sorting: Time Complexity- O((m + n) * log(m + n)) and Space Complexity-O(m + n)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {

    // to merge both the arrays
    vector<int> arr;

    // add the elements of array a
    for(auto i: a)
        arr.push_back(i);

    // add the elements of array a
    for(auto i: b)
        arr.push_back(i);

    // sort the merged array
    sort(arr.begin(), arr.end());

    // return the kth element
    return arr[k-1];
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k);
    return 0;
}

// Approach 2: Using Priority Queue: Time Complexity-O((m + n + k) * log(m + n)) and Space Complexity-O(m + n)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {

    // to store the elements of both the arrays in sorted order
    priority_queue<int, vector<int>, greater<int>> pq;

    // add the elements of array a
    for(auto i: a)
        pq.push(i);

    // add the elements of array a
    for(auto i: b)
        pq.push(i);

    // pop the elements from the heap till k-1 elements are popped
    while(k-- > 1)
        pq.pop();
    
    // return the kth element
    return pq.top();
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k);
    return 0;
}

// Approach 3: Using Merge Step of Merge Sort: Time Complexity- O(m + n) and Space Complexity-O(m + n)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();

    // array to store the merged sorted array
    vector<int> arr(n + m);
    int i = 0, j = 0, d = 0;
    while (i < n && j < m) {

        // If the element of a[] is smaller, insert the element to the sorted array
        if (a[i] < b[j])
            arr[d++] = a[i++];
        
        // If the element of b[] is smaller, insert the element to the sorted array
        else
            arr[d++] = b[j++];
    }

    // Push the remaining elements of a[]
    while (i < n)
        arr[d++] = a[i++];

    // Push the remaining elements of b[]
    while (j < m)
        arr[d++] = b[j++];

    return arr[k - 1];
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k);
    return 0;
}

// Approach 4: Using Optimized Merge of Merge Sort: Time Complexity-O(k) and Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();
  
    // last element added to the merged sorted array
    int last = 0;
    int i = 0, j = 0;

    for (int d = 0; d < k; ++d) {
        if (i < n) {
          
            // If a[i] > b[j] then increment j
            if (j < m && a[i] > b[j]) {
                last = b[j];
                j++;
            } 
            // Otherwise increment i
            else {
                last = a[i];
                i++;
            }
        }
        
        // If reached end of first array then increment j
        else if (j < m) {
            last = b[j];
            j++;
        }
    }

    // Return the last (kth) element
    return last;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k) << endl;
    return 0;
}

// Approach 5: Using Binary Search: Time Complexity- O(log(min(n, m)) and Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();

        // If a[] has more elements, then call kthElement with reversed parameters
    if (n > m)
        return kthElement(b, a, k);

    // Binary Search on the number of elements we can include in the first set from a[]
    int lo = max(0, k - m), hi = min(k, n);
  
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = k - mid1;

        // Find elements to the left and right of partition in a[]
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        // Find elements to the left and right of partition in b[]
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        // If it is a valid partition
        if (l1 <= r2 && l2 <= r1) {
          	
          	// Find and return the maximum of l1 and l2
            return max(l1, l2);
        }

        // Check if we need to take lesser elements from a[]
        if (l1 > r2)
            hi = mid1 - 1;

        // Check if we need to take more elements from a[]
        else
            lo = mid1 + 1;
    }
  
    return 0;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << kthElement(a, b, k);
    return 0;
}