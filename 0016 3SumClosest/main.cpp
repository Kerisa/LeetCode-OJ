/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	inline int abs(int a, int b)
	{
		return a>b ? a-b : b-a;
	}

public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0, closest = 0x7fffffff;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-2;)
        {

			int l = i + 1, r = nums.size()-1;
			int suml = nums[i] + nums[l] + nums[l+1];
			int sumr = nums[i] + nums[r] + nums[r-1];

			if ((suml - target) * (sumr - target) > 0)	// 都大于(或都小于)target则缩小搜索区间
			{
				if (suml > target)
					r = l + 1;		// +1 -1 是为所有组合都大于(或小于)target而留的
				else l = r - 1;		// 不然算不出值
			}

			while (l < r)
			{
				int tmp = nums[r] + nums[l] + nums[i];

				if (tmp == target) return target;

				if (abs(tmp, target) < closest)
				{
					closest = abs(tmp, target);
					ret = tmp;
				}
				if (tmp > target)
				{
					while (l < r && nums[r-1] == nums[r]) --r;
					--r;
				}
				else
				{
					while (l < r && nums[l+1] == nums[l]) ++l;
					++l;
				}
			}
			while (i < nums.size()-2 && nums[i+1] == nums[i]) ++i;
			++i;
		}
        return ret;
    }
};

int main()
{
	//int a [] = {1,1,1,1};
	//int a [] = {-1,0,1,2,-1,-4};
	int a[16] = {7,-4,-3,-2,1,0,0,0,0,-1,2,3,4,-5,6,5};
	//int a [] = {7,-13,-1,1,-6,14,10,-2,1,9,11,-10,8,-10,14,13,-1,4,-6,-3,-5,3,3,12,-5,11,5,-6,-2,0,-6,12,3,0,-2,12,-1,-7,-5,8,10,13,13,3,10,12,-7,-6,-7,-5,-1,3,5,-13,-8,-15,13,13,-14,-12,-2,-5,-15,8,11,-1,6,-13,-1,8,10,-14,-1,0,-4,-6,-3,5,-4,-2,7,10,8,-3,12,-14,-10,3,14,-9,-2,-11,-6,-9,13,12,-3,4,14,3,-11,2,5,-5,-13,-14,-3,-8};
	Solution S;
	vector<int> A(a, a + 5);
	cout << S.threeSumClosest(A, 7) << endl;;
	getchar();
	return 0;
}