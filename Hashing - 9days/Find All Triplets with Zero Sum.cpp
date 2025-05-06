// Find All Triplets with Zero Sum
// Question

/*
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
*/

// Approach 1: Brute Force: Using Three Nested Loops :Time Complexity- O(n^3) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr) {
    vector<vector<int>> res; 
    int n = arr.size(); 

    // Generating all triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {

                // If the sum of a triplet equals to zero then add it's indices to the result
                if (arr[i] + arr[j] + arr[k] == 0) 
                    res.push_back({i, j, k});
            }
        }
    }
    return res; 
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> res = findTriplets(arr);
    for(int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
  
    return 0;
}


// Approach 2: Using Hash Map: Time Complexity- O(n^3) and Space Complexity-O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> &arr) {
    
    // Map to store indices for each value
    unordered_map<int, vector<int>> map;
    
    // Resultant array 
    vector<vector<int>> ans;
    
    // Check for all pairs i, j
    for (int j=0; j<arr.size(); j++) {
        for (int k=j+1; k<arr.size(); k++) {
            
            // Value of third index should be 
            int val = -1*(arr[j]+arr[k]);
            
            // If such indices exists
            if (map.find(val)!=map.end()) {
                
                // Append the i, j, k
                for (auto i: map[val]) {
                    ans.push_back({i, j, k});
                }
            }
        }
        
        // After j'th index is traversed We can use it as i.
        map[arr[j]].push_back(j);
    }
    
    return ans;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int>> res = findTriplets(arr);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;

    return 0;
}