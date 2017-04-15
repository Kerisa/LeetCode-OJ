/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        
        int min, max, min_t, max_t;
		
		max = min = max_t = min_t = prices[prices.size()-1];

		for (int i=prices.size()-2; i>=0;)
		{
			if (prices[i] < max_t)
			{
				for (;i>=0 && prices[i] < max_t; --i)	// 递减区间(仮)
					if (prices[i] < min_t)
						min_t = prices[i];
				if (max_t-min_t > max-min)	// 更新值
				{
					max = max_t;
					min = min_t;
				}
			}
			else max_t = min_t = prices[i--];	// 有新的最高点
		}
        return max-min;
    }
};

int main()
{
	Solution S;
	vector<int> A;
	srand(time(0));
next:
	A.clear();
	for (int i=rand()%20; i>=0; --i)
	{
		int j = rand()%100;
		cout << j << " ";
		A.push_back(j);
	}
	cout << endl << S.maxProfit(A) << endl;
	char cc;
	if ('\n' == (cc = getchar()))
		goto next;
	return 0;
}
