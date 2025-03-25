// Majority Element II (n/3): Time Complexity - O(n), Space Complexity - O(1)
//Question:
/*
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: o candidate occur more than n/3 times.
*/

// Appraches 1 : Brute Force : Time Complexity -O(n^2) & Space Complexity - O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
        
        // Count the frequency of arr[i]
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == arr[i])
                cnt += 1;
        }
      
        // Check if arr[i] is a majority element
        if (cnt > (n / 3)) {
          
            // Add arr[i] only if it is not already present in the result
            if (res.size() == 0 || arr[i] != res[0]) {
                res.push_back(arr[i]);
            }
        }
      
        // If we have found two majority elements, we can stop our search
        if (res.size() == 2) {
            if(res[0] > res[1])
                swap(res[0], res[1]);
            break;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}

// Approach 2 : Using Hashmap or Dictonary :Time Complexity -O(n) & Space Complexity - O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> res;

    //frequency of each number
    for (int ele : arr)
        freq[ele]++;

    // Iterate over each key-value pair in the hash map
    for (auto it : freq) {
        int ele = it.first;
        int cnt = it.second;

        // Add the element to the result, if its frequency is greater than floor(n/3)
        if (cnt > n / 3)
            res.push_back(ele);
    }

    if (res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {

    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (auto ele : res) {
        cout << ele << " ";
    }
    return 0;
}

// Approach 3 :  Boyer-Moore’s Voting Algorithm :Time Complexity -O(n) & Space Complexity - O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();

    // Initialize two candidates and their counts
    int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

    for (int ele : arr) {
      
        // Increment count for candidate 1
        if (ele1 == ele) {
            cnt1++;
        }
      
        // Increment count for candidate 2
        else if (ele2 == ele) {
            cnt2++;
        }
      
        // New candidate 1 if count is zero
        else if (cnt1 == 0) {
            ele1 = ele;
            cnt1++;
        }
      
        // New candidate 2 if count is zero
        else if (cnt2 == 0) {
            ele2 = ele;
            cnt2++;
        }
      
        // Decrease counts if neither candidate
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> res;
    cnt1 = 0;
    cnt2 = 0;

    // Count the occurrences of candidates
    for (int ele : arr) {
        if (ele1 == ele) cnt1++;
        if (ele2 == ele) cnt2++;
    }

    // Add to result if they are majority elements
    if (cnt1 > n / 3) res.push_back(ele1);
    if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);
    
    if(res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {
  
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (int ele : res) {
        cout << ele << " ";
    }
    return 0;
}