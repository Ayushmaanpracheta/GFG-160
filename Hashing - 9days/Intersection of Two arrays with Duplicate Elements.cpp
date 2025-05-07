// Intersection of Two arrays with Duplicate Elements
// Question

/*
Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not have duplicate elements and the result should contain items in any order.

Note: The driver code will sort the resulting array in increasing order before printing.

Examples:

Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]
Output: [1, 3]
Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.
Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]
Output: [1]
Explanation: 1 is the only common element present in both the arrays.
*/

// Approach 1: Brute Force: Using Triple Nested Loops - O(n*n*m) Time and O(1) Space

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
    vector<int> res;

    // Traverse through a[] and search every element a[i] in b[]
    for (int i = 0; i < a.size(); i++) {    
        for (int j = 0; j < b.size(); j++) {
          
            // If found, check if the element is already in the result to avoid duplicates
            if (a[i] == b[j]) { 
                int k;
                for (k = 0; k < res.size(); k++) 
                    if (res[k] == a[i]) 
                        break;
                if (k == res.size()) {
                    res.push_back(a[i]);
                }
            }
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersection(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}

// Approach 2: Using Two Hash Sets - O(n+m) Time and O(n) Space

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
  
    // Put all elements of a[] in as
    unordered_set<int> as(a.begin(), a.end());  
  
    unordered_set<int> rs;                    
    vector<int> res;                            

    // Traverse through b[]
    for (int i = 0; i < b.size(); i++) {
      
        // If the element is in as and not yet in rs
        // a) Add it to the result set
        // b) Add it to the result array
        if (as.find(b[i]) != as.end() && 
            rs.find(b[i]) == rs.end()) {
            rs.insert(b[i]); 
            res.push_back(b[i]); 
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersection(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}

// Approach 3: Using One Hash Set - O(n+m) Time and O(n) Space

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
  
    // Put all elements of a[] in sa
    unordered_set<int> sa(a.begin(), a.end());  
    vector<int> res;                            

    // Traverse through b[]
    for (int i = 0; i < b.size(); i++) {
      
        // If the element is in sa
        // a) Add it to the result array
        // b) Erase it from sa to avoid duplicates
        if (sa.find(b[i]) != sa.end()) {
            res.push_back(b[i]); 
            sa.erase(b[i]);  
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersection(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}