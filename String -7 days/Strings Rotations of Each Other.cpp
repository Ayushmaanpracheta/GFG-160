// Strings Rotations of Each Other:
// Question:
/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
*/

// Approach 1: Brute Force: Generating all rotations: Time Complexity-O(n^2) and Space Complexity- O(1)

#include <iostream>
using namespace std;

// Function to check if s1 and s2 are rotations of each other
bool areRotations(string &s1, string &s2) {
    int n = s1.size();
  	
  	// generate and check all possible rotations of s1
    for (int i = 0; i < n; ++i) {
      
      	// if current rotation is equal to s2 return true
        if (s1 == s2)
            return true;
      
      	// right rotate s1
        char last = s1.back();
        s1.pop_back();
        s1 = last + s1;
    }
    return false;
}

int main() {
    string s1 = "aab";
    string s2 = "aba";

    cout << (areRotations(s1, s2) ? "true" : "false");
    return 0;
}

// Approach 2: Using KMP Algorithm : Time Complexity- O(n) and Space Complexity- O(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPSArray(string& pat) {
  	int n = pat.size();
  	vector<int> lps(n);
  
    // Length of the previous longest prefix suffix
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    // loop calculates lps[i] for i = 1 to n-1
    int i = 1;
    while (i < n) {
      
        // If the characters match, increment len and extend the matching prefix
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
      
        // If there is a mismatch
        else {
          
            // If len is not zero, update len to last known prefix length
            if (len != 0) {
                len = lps[len - 1];
            }
          
            // No prefix matches, set lps[i] = 0 and move to the next character
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
  	return lps;
}


// Function to check if s1 and s2 are rotations of each other
bool areRotations(string &s1, string &s2) {
  	string txt = s1 + s1;
  	string pat = s2;
  	
  	// search the pattern string s2 in the concatenation string 
  	int n = txt.length();
    int m = pat.length();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps = computeLPSArray(pat);
  
    int i = 0; 
    int j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            return true;
        }

        // Mismatch after j matches
        else if (i < n && pat[j] != txt[i]) {

            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

int main() {
    string s1 = "aab"; 
  	string s2 = "aba";
  	
    cout << (areRotations(s1, s2) ? "true" : "false");
}

// Approach 3: Using Built-in Method : Time Complexity- O(n) and Space Complexity- O(n)

#include <iostream>
using namespace std;

// Function to check if s1 and s2 are rotations of each other
bool areRotations(string &s1, string &s2) {
  	s1 += s1;
  
  	// find s2 in concatenated string
  	return s1.find(s2) != string::npos;
}

int main() {
    string s1 = "aab"; 
  	string s2 = "aba";
  	
    cout << (areRotations(s1, s2) ? "true" : "false");
}