// Print Anagrams Together
// Question:

/*
Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification.

Examples:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
Explanation: 
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
*/

// Approach 1: Using Frequency as key: Time Complexity-O(n*k) and Space Complexity-O(n*k)

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// function to generate hash of word s
string getHash(string &s) {
    string hash;
	vector<int> freq(MAX_CHAR, 0);
    
    // Count frequency of each character
    for(char ch: s)
        freq[ch - 'a'] += 1;
    
    // Append the frequency to construct the hash
    for(int i = 0; i < MAX_CHAR; i++) {
        hash.append(to_string(freq[i]));
    	hash.append("$");
    }
    
    return hash;
}

vector<vector<string>> anagrams(vector<string> &arr) {
    vector<vector<string>> res;
    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        string key = getHash(arr[i]);
      
        // If key is not present in the hash map, add an empty group (vector) in the result and store the index of the group in hash map
        if (mp.find(key) == mp.end()) {
            mp[key] = res.size();
            res.push_back({});
        }
      
        // Insert the string in its correct group
        res[mp[key]].push_back(arr[i]);
    }
    return res;
}

int main() {
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    
    vector<vector<string>> res = anagrams(arr);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}