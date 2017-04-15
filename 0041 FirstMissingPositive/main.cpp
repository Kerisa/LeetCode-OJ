/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (!nums.size()) return 1;
        
		// 二分找到1，找不到就返回1
        int l=0, r = nums.size()-1, m = (l + r) / 2;
        while (l < r)
        {
			m = (l + r) / 2;
            if (m == l)
			{
				if (nums[l] == 1)
				{
					m = l;
					break;
				} else if (nums[r] == 1) {
					m = r;
					break;
				}
				return 1;
			}
            if (nums[m] == 1)
                break;
            if (nums[m] < 1)
                l = m;
            else r = m;
        }
		if (nums[m] != 1) return 1;
        int i, correct = m - 1, find = 2;

		for (i=m; i<nums.size(); ++i)
		{
			if (nums[i] > find)
				return find;
			else if (nums[i] == find)
				++find;
		}
		return find;
    }
};

int main()
{
	Solution S;
	int a [] = {1,0,-1,-2,6,8,-4,9,9,1,2,3,4,9,10,5,6,7,5,0,3,6,4,8,6};
	cout << S.firstMissingPositive(vector<int>(a+1,a+2)) << endl;
	return 0;
}