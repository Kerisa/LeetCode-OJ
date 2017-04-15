/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 * For example,
 *   Given height = [2,1,5,6,2,3],
 *   return 10.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	// 栈保存数组索引，栈中索引指向的值(height[idx in stack])都是递增的
	// 即栈保存了一个非递减区间，并在非递减区间结束时计算当前区间中的最大面积
	int largestRectangleArea(vector<int>& height) {
		stack<int> st;
		int Area = 0;
		height.push_back(0);	// dummy
		for (int i=0; i<height.size();)
		{
			if (st.empty() || height[st.top()] < height[i])
				st.push(i++);
			else
			{
				int t = st.top();
				st.pop();
				Area = max(Area, height[t] * (st.empty() ? i : i-1-st.top()));
			}
		}
		return Area;
	}
};

int main()
{
	Solution S;
	int a [] = {2,1,5,6,2,1,2,2,2,2,2,2,2};
	cout << S.largestRectangleArea(vector<int>(a,a+13)) << endl;
	return 0;
}