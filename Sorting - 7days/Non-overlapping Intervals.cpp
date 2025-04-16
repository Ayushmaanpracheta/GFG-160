// Non-overlapping Intervals
// Question:
/*
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
*/

// Approach 1: Brute Force : Sorting by the Starting Values: Time Complexity-O(n*log n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRemoval(vector<vector<int>>& intervals) {
  	int cnt = 0;
  
    // Sort by minimum starting point
    sort(intervals.begin(), intervals.end());

    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {

        // If the current starting point is less than the previous interval's ending point (ie. there is an overlap)
        if (intervals[i][0] < end) {
          
            // Increase cnt and remove the interval with the higher ending point
          	cnt++;
            end = min(intervals[i][1], end);
        }
      	
      	// Incase of no overlapping, this interval is not removed and 'end' will be updated
        else
            end = intervals[i][1];
    }

    return cnt;
}

int main() {
    vector<vector<int> > intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << minRemoval(intervals) << endl;
}

// Approach 2: Sorting by the Ending Values: Time Complexity- O(n*log n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// comparator function
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int minRemoval(vector<vector<int> >& intervals) {
	int cnt = 0;
  
    // Sort by minimum ending point
    sort(intervals.begin(), intervals.end(), compare);

    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // if there is an overlap increase the count
        if (intervals[i][0] < end)
            cnt++;

        // else increment the ending point
        else
            end = intervals[i][1];
    }

    // return the count
    return cnt;
}

int main() {
    vector<vector<int>> intervals = 
    				{{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
}