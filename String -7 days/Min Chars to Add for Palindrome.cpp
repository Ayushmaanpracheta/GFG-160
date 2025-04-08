// Min Chars to Add for Palindrome
// Question:
/*
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
*/

// Approach 1:Brute Force: Checking all prefixes: Time Complexity-O(n^2) and Space Complexity-O(1) 

#include <iostream>
using namespace std;

// Function to check if the substring s[i...j] is a palindrome
bool isPalindrome(string &s, int i, int j) {
    while (i < j) {
      
        // If characters at the ends are not equal, it's not a palindrome
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minChar(string &s) {
    int cnt = 0;
    int i = s.size() - 1;
    
    // Iterate from the end of the string, checking for the longest palindrome starting from the beginning
    while (i >= 0 && !isPalindrome(s, 0, i)) {
        
        i--;
        cnt++;
    }
    
    return cnt;
}

int main() {
    string s = "AACECAAAA";
  
    cout << minChar(s);
    return 0;
}

// Approach 2:  Using lps array of KMP Algorithm :Time Complexity-O(n)and Space Complexity-O(n)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPSArray(string &pat) {
    int n = pat.length();
    vector<int> lps(n);

    // lps[0] is always 0
    lps[0] = 0;
    int len = 0;

    // loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < n) {

        // If the characters match, increment len and set lps[i]
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else if (pat[i] != pat[len]) {

            // If len is not zero, update len to the last known prefix length
            if (len != 0) {
                len = lps[len - 1];
            }

            // No prefix matches, set lps[i] to 0
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Method returns minimum character to be added at front to make string palindrome
int minChar(string &s) {
    int n = s.length();
    string rev = s;
    reverse(rev.begin(), rev.end());

    // Get concatenation of string, special character and reverse string
    s = s + "$" + rev;

    //  Get LPS array of this concatenated string
    vector<int> lps = computeLPSArray(s);

    // By subtracting last entry of lps vector from string length, we will get our result
    return (n - lps.back());
}

int main() {
    string s = "AACECAAAA";
    cout << minChar(s);
    return 0;
}