/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
	int min(const int a, const int b)
	{
		return a>b ? b : a;
	}

	int max(const int a, const int b)
	{
		return a<b ? b : a;
	}
public:
	//sell1st正向遍历数组，sell1st[i]表示在i天(或之前)第1次买卖时的最高利润
	//sell2nd反向遍历数组，sell2nd[i]表示在i天(或之后)第2次买卖时的最高利润
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1) return 0;

		vector<int> sell1st(prices.size());
		vector<int> sell2nd(prices.size());

		int cheapest = prices[0];
		sell1st[0] = 0;
		for (int i=1; i<prices.size(); ++i)
		{
			cheapest = min(cheapest, prices[i]);
			sell1st[i] = max(sell1st[i-1], prices[i] - cheapest);
		}

		int hignest = prices[prices.size()-1];
		sell2nd[prices.size()-1] = 0;
		for (int i=prices.size()-2; i>=0; --i)
		{
			hignest = max(hignest, prices[i]);
			sell2nd[i] = max(sell2nd[i+1], hignest-prices[i]);
		}

		int maxPro = 0;
		for (int i=prices.size()-1; i>=0; --i)
			maxPro = max(maxPro, sell1st[i]+sell2nd[i]);

		return maxPro;
	}
};

int main()
{
	Solution S;
	int a[]={3,2,6,5,0,3};
	//int a[]={6,1,3,2,4,7};
	//int a[]={1,2,4,2,5,7,2,4,9,0,9};
	vector<int>C(a, a+6);
	cout << endl << S.maxProfit(C) << endl;

	return 0;
}
