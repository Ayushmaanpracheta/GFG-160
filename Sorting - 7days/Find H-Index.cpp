// Find H-Index
// Question:
/*
Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

Examples:

Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.
Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.
Input: citations[] = [0, 0]
Output: 0
*/

// Approach 1: Brute force : Using Comparison-based Sorting: Time Complexity-O(n*logn) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int> &citations) {

    // Sort the citations in descending order
    sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    int idx = 0;

    // Keep incrementing idx till citations[idx] > idx
	while(idx < n && citations[idx] > idx) {
        idx += 1;
    }
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}

// Approach 2: Using Counting Sort: Time Complexity-O(n) and Space Complexity-O(n) 

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> &citations) {

    int n = citations.size();
    vector<int> freq(n + 1);

    // Count the frequency of citations
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }

    int idx = n;
    
    // Variable to keep track of the count of papers having at least idx citations
    int s = freq[n]; 
    while (s < idx) {
        idx--;
        s += freq[idx];
    }
  
    // Return the largest index for which the count of papers with at least idx citations becomes >= idx
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}