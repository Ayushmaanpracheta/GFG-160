// Aggressive Cows
// Question:

/*
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
*/

// Approach 1: Brute Force: By iterating over all possible distances: Time Complexity- O(n*(MAX - MIN)) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check if we can place k cows with at least dist distance apart
bool check(vector<int> &stalls, int k, int dist) {
    
    // Place first cow at 0th index
    int cnt = 1;  
    int prev = stalls[0]; 
    for (int i = 1; i < stalls.size(); i++) {
        
        // If the current stall is at least dist away from the previous one place the cow here
        if (stalls[i] - prev >= dist) {
            prev = stalls[i]; 
            cnt++; 
        }
    }

    // Return true if we are able to place all 'k' cows
    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k) {
  
  	// sorting the array to ensure stalls in sequence
  	sort(stalls.begin(), stalls.end());
    int res = 0; 
  
  	// Minimum and maximum possible minimum distance between two stalls
    int minDist = 1;
    int maxDist = stalls.back() - stalls[0];  

    // Iterating through all possible distances 
    for (int i = minDist; i <= maxDist; i++) {
        
        // If we can place k cows with the current distance i, update the res
        if (check(stalls, k, i))
            res = i;  
    }

    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}

// Approach 2:  Using Binary Search: Time Complexity- O(n * log(MAX - MIN)) and Space Complexity- O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check if we can place k cows with at least dist distance apart
bool check(vector<int> &stalls, int k, int dist) {
    
    // Place first cow at 0th index
    int cnt = 1;  
    int prev = stalls[0]; 
    for (int i = 1; i < stalls.size(); i++) {
        
        // If the current stall is at least dist away from the previous one place the cow here
        if (stalls[i] - prev >= dist) {
            prev = stalls[i]; 
            cnt++;
        }
    }

    // Return true if we are able to place all 'k' cows
    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k) {
  
  	// sorting the array to ensure stalls in sequence
  	sort(stalls.begin(), stalls.end());
    int res = 0; 
  
    // Search Space for Binary Search
  	int lo = 1;
  	int hi = stalls.back() - stalls[0];
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        // If the mid ditance is possible, update the result and search for larger ditance
        if(check(stalls, k, mid)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}

