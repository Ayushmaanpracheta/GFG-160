// Count all triplets with given sum in sorted array
// Question:

/*
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Four triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1. 
*/

// Approach 1:Using Two Pointers Technique: Time Complexity- O(n^2) and Space Complexity- O(1)

#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size();
    int res = 0;

    // Iterate through each element as the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        // Use two-pointer approach to find triplets
        while (left < right) {

            // Calculate the sum of the triplet
            int sum = arr[i] + arr[left] + arr[right];

            // If sum is smaller, move to bigger values
            if (sum < target) {
                left += 1;
            }
          
            // If sum is greater, move to smaller values
            else if (sum > target) {
                right -= 1;
            }
            else if (sum == target) {
                int ele1 = arr[left], ele2 = arr[right];
                int cnt1 = 0, cnt2 = 0;

                // Count frequency of the current value at 'left'
                while (left <= right && arr[left] == ele1) {
                    left++;
                    cnt1++;
                }

                // Count frequency of the current value at 'right'
                while (left <= right && arr[right] == ele2) {
                    right--;
                    cnt2++;
                }

                // If both the elements are same, then count of pairs = the number of ways to choose 2 elements among cnt1 elements
                if (ele1 == ele2)
                    res += (cnt1 * (cnt1 - 1)) / 2;

                // If the elements are different, then count of pairs = product of the count of both elements
                else
                    res += (cnt1 * cnt2);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;

    cout << countTriplets(arr, target) << endl;
    return 0;
}


class Solution {
    public:
        int countTriplets(vector<int>& arr, int target) {
            sort(arr.begin(), arr.end()); // Required for two pointers
            int n = arr.size();
            int res = 0;
    
            for (int i = 0; i <= n - 3; i++) {
                int left = i + 1, right = n - 1;
    
                while (left < right) {
                    int sum = arr[i] + arr[left] + arr[right];
    
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        // sum == target
                        int ele1 = arr[left], ele2 = arr[right];
                        int c1 = 0, c2 = 0;
    
                        if (ele1 == ele2) {
                            int count = right - left + 1;
                            res += (count * (count - 1)) / 2;
                            break;
                        }
    
                        while (left <= right && arr[left] == ele1) {
                            c1++;
                            left++;
                        }
    
                        while (left <= right && arr[right] == ele2) {
                            c2++;
                            right--;
                        }
    
                        res += c1 * c2;
                    }
                }
            }
    
            return res;
        }
    };
    