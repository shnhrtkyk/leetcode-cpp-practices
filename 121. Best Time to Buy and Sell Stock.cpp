/**
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
**/

//Runtime: 8 ms, faster than 99.32% of C++ online submissions for Best Time to Buy and Sell Stock.
//Memory Usage: 9.4 MB, less than 94.64% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int ans = 0;
        
        int start = prices[0], end = prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < start){
                //restart as session
                ans = max(ans, end - start);
                start = prices[i];
                end = prices[i];
            }else{
                //continue current session
                end = max(end, prices[i]);
            }
        }
        ans = max(ans, end - start);
        return ans;
    }
};

/**
Approach 2: One Pass
Algorithm

Say the given array is:

[7, 1, 5, 3, 6, 4]

If we plot the numbers of the given array on a graph, we get:

The points of interest are the peaks and valleys in the given graph. We need to find the largest peak following the smallest valley. We can maintain two variables - minprice and maxprofit corresponding to the smallest valley and maximum profit (maximum difference between selling price and minprice) obtained so far respectively.
**/

/**
Complexity Analysis

Time complexity : O(n)O(n). Only a single pass is needed.

Space complexity : O(1)O(1). Only two variables are used.
**/

/**
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = INT_MAX;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < valley){
                valley = prices[i];
            }else if(prices[i] - valley > ans){
                asn = prices[i] - valley;
            }
        }
        return ans;
    }
};
**/