// Union of Arrays with Duplicates
// Question:

/*
Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

Note: Elements of a[] and b[] are not necessarily distinct.

Examples

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
Output: 5
Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.
Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
Output: 7
Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.
Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
Output: 2
Explanation: We need to consider only distinct. So count of elements in union set will be 2.
*/

// Approach 1: Brute force :Using Nested Loops: Time Complexity- O(n^2) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> res;

    // Traverse through a[] and search every element a[i] in result
    for (int i = 0; i < a.size(); i++) {

        // check if the element is already in the result to avoid duplicates
        int j;
        for (j = 0; j < res.size(); j++)
            if (res[j] == a[i])
                break;
        if (j == res.size()) {
            res.push_back(a[i]);
        }
    }

    // Traverse through b[] and search every element b[i] in result
    for (int i = 0; i < b.size(); i++) {

        // check if the element is already in the result to avoid duplicates
        int j;
        for (j = 0; j < res.size(); j++)
            if (res[j] == b[i])
                break;
        if (j == res.size()) {
            res.push_back(b[i]);
        }
    }
    return res;
}

int main() {

    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}

// Approach 2: Using Hash Set: Time Complexity- O(n) and Space Complexity-O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
  	unordered_set<int> st;  
  
    // Put all elements of a[] in st
    for (int i = 0; i < a.size(); i++) 
      	st.insert(a[i]);
  	
  	// Put all elements of b[] in st
    for (int i = 0; i < b.size(); i++) 
      	st.insert(b[i]);
  	
    vector<int> res;                            
  	
  	// iterate through the set to fill the result array 
  	for(auto it: st) 
      	res.push_back(it);
    
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = findUnion(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}