// Overlapping Intervals
// Question:

/*
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
*/

// Approach 1: Brute Force : Checking All Possible Overlaps: Time Complexity-O(n^2) and Space Complexity-O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int>> res;

    // Checking for all possible overlaps
    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // Skipping already merged intervals
        if (!res.empty() && res.back()[1] >= end)
            continue;

        // Find the end of the merged range
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
        }
        res.push_back({start, end});
    }
    return res;
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

    for (auto interval : res)
        cout << interval[0] << " " << interval[1] << endl;

    return 0;
}

// Approach 2: Checking Last Merged Interval: Time Complexity-O(n*log(n)) and Space Complexity-O(n)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());
  
    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];

        // If current interval overlaps with the last merged interval, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    vector<vector<int>> res = mergeOverlap(arr);

  	for (vector<int>& interval: res) 
        cout << interval[0] << " " << interval[1] << endl;
 
    return 0;
}

// Approach 3: In-Place Merging: Time Complexity- O(n*log(n)) and Space Complexity-O(1)

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    // Sort intervals based on start value
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> result;
    result.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        if (result.back()[1] >= arr[i][0]) {
            result.back()[1] = max(result.back()[1], arr[i][1]);
        } else {
            result.push_back(arr[i]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    
    int newSize = mergeOverlap(arr);

    for (int i = 0; i < newSize; i++) {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    return 0;
}
