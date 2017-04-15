/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
    int Next(vector<int>& nums, int l, int r, int tar)
    {
        if (l == r)
            return nums[l] == tar ? l : -1;
        if (l+1 == r)
        {
            if (nums[l] == tar) return l;
            if (nums[r] == tar) return r;
            return -1;
        }
        if (l < r)
        {
            int m = (l + r) / 2, ret1, ret2;
            if (nums[m] == tar) return m;
            if ((ret1 = Next(nums, l, m-1, tar)) != -1)
                return ret1;
            if ((ret2 = Next(nums, m+1, r, tar)) != -1)
                return ret2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
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