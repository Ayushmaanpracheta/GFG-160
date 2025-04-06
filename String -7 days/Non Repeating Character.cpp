// Non Repeating Character
// Question:
/*
Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.
*/

// Approach 1:Brute Force: Using Nested Loop – Time Complexity-O(n^2) and Space Complexity-O(1)

#include <bits/stdc++.h>
using namespace std;

char nonRep(string &s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        bool found = false;

        for (int j = 0; j < n; ++j) {
            if (i != j && s[i] == s[j]) {
                found = true;
                break;
            }
        }
        if (!found) 
            return s[i];
    }

    return '$';
}

int main() {
    string s = "racecar";
    cout << nonRep(s);
    return 0;
}

// Approach 2:Using Frequency Array (Two Traversal) – Time Complexity-O(2*n) and Space Complexity-O(MAX_CHAR )

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;  

char nonRep(const string &s) {
    vector<int> freq(MAX_CHAR, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find the first character with frequency 1
    for (char c : s) {
        if (freq[c - 'a'] == 1) {
            return c;
        }
    }
    return '$';
}

int main() {
    string s = "geeksforgeeks";
    cout << nonRep(s) << endl;
    return 0;
}

// Approach 3:  By Storing Indices (Single Traversal) – Time Complexity-O(n) and Space Complexity-O(MAX_CHAR )

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;  

char nonRep(const string& s) {
    vector<int> vis(MAX_CHAR, -1);
    for (int i = 0; i < s.length(); ++i) {
        int index = s[i] - 'a';
        if (vis[index] == -1) {
            
            // Store the index when character is first seen
            vis[index] = i;  
        } else {
            
            // Mark character as repeated
            vis[index] = -2; 
        }
    }

    int min_idx = INT_MAX;

    // Find the smallest index of the non-repeating characters
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (vis[i] >= 0 &&  vis[i] < min_idx) {
            min_idx = vis[i];
        }
    }
    return (min_idx == INT_MAX) ? '$' : s[min_idx];
}

int main() {
    string s = "aabbccc";
    cout << nonRep(s) << endl;
    return 0;
}