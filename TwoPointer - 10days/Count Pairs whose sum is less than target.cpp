// Count Pairs whose sum is less than target
// Question

/*
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

Examples:

Input: arr[] = [7, 2, 5, 3], target = 8
Output: 2
Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3). 
Input: arr[] = [5, 2, 3, 2, 4, 1], target = 5
Output: 4
Explanation: There are 4 pairs whose sum is less than 5: (2, 2), (2, 1), (3, 1) and (2, 1).
Input: arr[] = [2, 1, 8, 3, 4, 7, 6, 5], target = 7
Output: 6
Explanation: There are 6 pairs whose sum is less than 7: (2, 1), (2, 3), (2, 4), (1, 3), (1, 4) and (1, 5).
*/

// Approach 1: Brute Force :By Generating all the pairs- O(n^2) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int target) {
    int cnt = 0;
    
    // Generating all possible pairs
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            
            // If sum of this pair is less than target, then increment the cnt
            if(arr[i] + arr[j] < target)
                cnt++;
        }
    }
    
    return cnt;
}

int main() {
	vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << countPairs(arr, target);
    return 0;
}

// Approach 2: Using Binary Search - O(2*nlogn) Time and O(1) Space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search to find lower bound
int binarySearch(vector<int> &arr, int complement) {
  	int lo = 0, hi = arr.size() - 1;
  	int res = arr.size();
  
  	while(lo <= hi) {
     	int mid = (lo + hi) / 2;
      	
      	if(arr[mid] >= complement) {
          res = mid;
          hi = mid - 1;
        }
      	else {
          lo = mid + 1;
        }
    }
  	return res;
}

int countPairs(vector<int> &arr, int target) {
    int cnt = 0;
  
  	// Sort the array to use binary search
  	sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        
      	// Index of the element which is greater or equal to the complement
        int ind = binarySearch(arr, complement);
          
      	// arr[i] with make valid pairs with each element before the index 'ind'
        cnt += ind;
      
      	// If element has made a pair with itself
        if(ind > i)
            cnt--;
    }
    
  	// Each pair is counted twice
    return cnt/2;
}

int main() {
	vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << countPairs(arr, target);
    return 0;
}

// Approach 3: Using Two Pointers Technique - O(n*logn+n) Time and O(1) Space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countPairs(vector<int> &arr, int target) {
  
  	// Sort the array to use two pointer technique
  	sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int cnt = 0;
    
    // Two pointer technique
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        // If the sum is less than target, then arr[left] will form a valid pair with every element from index left + 1 to right.
        if (sum < target) {
            cnt += right-left;
            left++;
        }
        else {
            right--;
        }
    }
    
    return cnt;
}

int main() {
	vector<int> arr = {2, 1, 8, 3, 4, 7, 6, 5};
    int target = 7;
    cout << countPairs(arr, target);
    return 0;
}