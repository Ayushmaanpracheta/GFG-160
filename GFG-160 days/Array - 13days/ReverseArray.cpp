// Reverse Array : In this we have an array and we have to reverse an array in Time Complexity- O(n) and Space Complexity- O(1).

/*Question :
You are given an array of integers arr[]. Your task is to reverse the given array.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]

Input: arr = [4, 5, 2]
Output: [2, 5, 4]
*/
// Approach -1 : using extra space: in this we take last element(n-1) of arr[] and put at first at temp[]
// Time Complexity - O(n) , Space Complexity - O(n)

// Approach 2: Two Pointer Approach , in this just give first index - left and last index- right and swap(arr[left],arr[right]) , left++ , right --;
// Time Complexity - O(n) , Space Complexity - O(1)

// Approach 3 : swapping Array : for(int i =0;i<n/2;i++){swap(arr[i],arr[n-i-1]);}
// Approach 4: Inbuilt function : swap(arr.begin(),arr.end());

#include <iostream>
#include <vector>
using namespace std;

// function to reverse an array
void reverseArray(vector<int> &arr) {
    int n = arr.size();
    
    // Iterate over the first half and for every index i,
    // swap arr[i] with arr[n - i - 1]
    for(int i = 0; i < n/2; i++) {
    	swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    reverseArray(arr);
  
    for(int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}

// OOPs:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void reverseArray(vector<int>&arr){
        // Two pointet Approach : but fails if left is greater than right.
        // int left = 0, right =arr.size()-1;
        // while(left<right){
        //     swap(arr[left],arr[right]);
        //     left++;
        //     right --;

        // }

        // swaping Approach:
        int n = arr.size();
        for(int i =0;i<n/2;i++){
            swap(arr[i],arr[n-i-1]);
        }
    }
};
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        vector<int>arr;
        string input;
        getline(cin,input);
        stringstream ss(input);
        int number;
        while(ss >> number){
            arr.push_back(number);
        }

        Solution ob;
        ob.reverseArray(arr);
        for(int i = 0;i < arr.size();i++){
            cout << arr[i];
        }
        cout <<endl;
        cout << "~" << endl;
    }
    return 0;
}