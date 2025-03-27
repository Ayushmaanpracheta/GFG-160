// Stock Buy and Sell – Max one Transaction Allowed :
//  Question:
/*
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.
Input: prices[] = [7, 6, 4, 3, 1]
Output: 0 
Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.
Input: prices[] = [1, 3, 6, 9, 11]
Output: 10 
Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].
*/

// Approach 1: Brute Force: By exploring all possible pairs - Time Complexity-O(n^2) and Space Complexity-O(1).

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {  
    int n = prices.size();
    int res = 0;
  
    // Explore all possible ways to buy and sell stock
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
			res = max(res, prices[j] - prices[i]);
        }
    }
    return res;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}

// Approach 2 : One Traversal Solution - Time Complexity- O(n) and Space Complexity-O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  
    int minSoFar = prices[0], res = 0;
  
    for (int i = 1; i < prices.size(); i++) {

        // Update the minimum value seen so far if we see smaller
        minSoFar = min(minSoFar, prices[i]);
       
        // Update result if we get more profit                
        res = max(res, prices[i] - minSoFar);
    }
    return res;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}