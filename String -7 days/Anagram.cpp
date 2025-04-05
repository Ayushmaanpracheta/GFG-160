// Anagram.cpp
// Question:
/*
Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

Examples :

Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.
Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.
Input: s1 = "g", s2 = "g"
Output: true
Explanation: Character in both the strings are same, so they are anagrams.
*/

// Approach 1: Brute Force: Using Sorting: Time Complexity-O(m*log(m) + n*log(n)) and Space Complexity-O(1)

#include <algorithm>
#include <iostream>
using namespace std;

// Function to check if two strings are anagrams
bool areAnagrams(string &s1, string &s2) {
    
    // Sort both strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    // Compare sorted strings
    return s1 == s2;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
	cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}

// Approach 2: Using Hash Map or Dictionary: Time Complexity-O(m + n) and Space Complexity-O(26)=O(1)

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2) {
    
    // Create a hashmap to store character frequencies
    unordered_map<char, int> charCount;
    
    // Count frequency of each character in string s1
    for(char ch: s1) 
    	charCount[ch] += 1;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
    	charCount[ch] -= 1;
  
    // Check if all frequencies are zero
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    // If all conditions satisfied, they are anagrams
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
	cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}

// Approach 3:  Using Frequency Array: Time Complexity- O(m + n) and Space Complexity-O(MAX_CHAR) =O(26)=O(1)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// As the input strings can only have lowercase characters, the maximum characters will be 26
const int MAX_CHAR = 26;

bool areAnagrams(string &s1, string &s2) {
    vector<int> freq(MAX_CHAR, 0);
    
    // Count frequency of each character in string s1
    for(char ch: s1) 
    	freq[ch - 'a']++;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
    	freq[ch - 'a']--;
  
    // Check if all frequencies are zero
    for (int count : freq) {
        if (count != 0) 
            return false;
    }
    
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
	cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}