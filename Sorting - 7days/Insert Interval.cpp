// Insert Interval
// Question:
/*
Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

// Approach 1: Brute Force: Insertion and Merging: Time Complexity -O(n*log n) and Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {

    // Sort intervals based on start values
    sort(intervals.begin(), intervals.end());
  
    vector<vector<int>> res;
  
    // Insert the first interval into the result
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
      
        // Find the last interval in the result
        vector<int>& last = res.back();
        vector<int>& curr = intervals[i];

        // If current interval overlaps with the last interval in the result, merge them 
        if (curr[0] <= last[1]) 
            last[1] = max(last[1], curr[1]);
        else 
            res.push_back(curr);
    }

    return res;
}

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, 
                                   		  vector<int> &newInterval) {
    intervals.push_back(newInterval);
  	return mergeOverlap(intervals);
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
  	for (vector<int> interval: res) {
      	cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}

// Approach 2:  Contiguous Interval Merging: Time Complexity- O(n) and Space Complexity-O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to insert and merge intervals
vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int> &newInterval) {
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // Add all the remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
  	for (vector<int> interval: res) {
      	cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}