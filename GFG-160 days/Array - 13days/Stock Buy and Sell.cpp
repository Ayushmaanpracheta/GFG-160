// Stock Buy and Sell -Multiple Transaction Allowed :
// Question :
/*
Given an array prices[] of size n denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

Input: prices[] = {100, 180, 260, 310, 40, 535, 695}
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 - 100 = 210
                       Buy the stock on day 4 and sell it on day 6 => 695 - 40 = 655
                       Maximum Profit  = 210 + 655 = 865

Maximize-Profit--Graph
Input: prices[] = {4, 2, 2, 2, 4}
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 - 2 = 2
                       Maximum Profit  = 2
*/

// Approach 1 - Brute Force : Using Recursion :Time Complexity - O(n^2), Space Complexity -O(1) : Exponential Time

#include <iostream>
#include <vector>
using namespace std;

int maxProfitRec(vector<int> &price, int start, int end) {
    int res = 0;
  
    // Consider every valid pair, find the profit with it and recursively find profits on left and right of it
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr = (price[j] - price[i]) + 
                            maxProfitRec(price, start, i - 1) + 
                  			maxProfitRec(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}

// Wrapper function
int maximumProfit(vector<int> &prices) {
    return maxProfitRec(prices, 0, prices.size()-1);
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}

// Approach 2 :Local Minima and Maxima : Time Complexity - O(n), Space Complexity -O(1)
/*
1.The idea is to traverse the array from left to right and do following.
2.Find local minima and then a local maxima.
3.Compute the difference between two and add to the result.
*/

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = prices[0];  // Local Minima
    int lMax = prices[0];  // Local Maxima
    int res = 0;
  
    int i = 0;
    while (i < n - 1) {
      
        // Find local minima 
        while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
        lMin = prices[i];
       
        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
        lMax = prices[i];
      
        // Add current profit 
        res = res + (lMax - lMin);
    }
  
    return res;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}

// Approach 3 : Accumulate Profit : Time Complexity - O(n), Space Complexity -O(1)

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(const vector<int>& prices) {
    int res = 0;
  
    // Keep on adding the difference between adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}

int main() {
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    cout << maximumProfit(prices) << endl;
    return 0;
}