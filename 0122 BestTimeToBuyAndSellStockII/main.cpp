/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 */
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int sum = 0;
        for (int i=1; i<prices.size(); ++i)
            sum += prices[i]>prices[i-1] ? prices[i]-prices[i-1] : 0;
        return sum;
    }
};