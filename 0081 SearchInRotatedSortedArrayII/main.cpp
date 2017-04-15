/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
	// -1改成false，其他改true
    bool Next(vector<int>& nums, int l, int r, int tar)
    {
        if (l == r)
            return nums[l] == tar ? true : false;
        if (l+1 == r)
        {
            if (nums[l] == tar) return true;
            if (nums[r] == tar) return true;
            return false;
        }
        if (l < r)
        {
            int m = (l + r) / 2, ret1, ret2;
            if (nums[m] == tar) return true;
            if ((ret1 = Next(nums, l, m-1, tar)) != false)
                return true;
            if ((ret2 = Next(nums, m+1, r, tar)) != false)
                return true;
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if (!nums.size()) return false;
        return Next(nums, 0, nums.size()-1, target);
    }
};

int main()
{
	Solution S;
	int a [] = { 1, 2, 1, 6, 6, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,0,1,2,3,4};
	cout << S.search(vector<int>(a,a+3), 0) << endl;
	return 0;
}