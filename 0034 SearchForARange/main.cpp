/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 *   Given [5, 7, 7, 8, 8, 10] and target value 8,
 *   return [3, 4].
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
    vector<int> FindRange(vector<int>& nums, int start, int tar)
    {
        int m1, l1 = 0, r1 = start;
        while (l1 < r1)
        {
            m1 = (l1 + r1) / 2;
            if (nums[m1] == tar && r1 != m1)
                r1 = m1;
			else if (r1 == l1+1 && nums[l1]==tar)
			{
				--r1;
				break;
			}
            else
                l1 = m1 + 1;
        }
        
        int m2, l2 = start, r2 = nums.size()-1;
        while (l2 < r2)
        {
            m2 = (l2 + r2) / 2;
            if (nums[m2] == tar && l2 != m2)
                l2 = m2;
            else if (r2 == l2+1 && nums[r2]==tar)
			{
				++l2;
				break;
			}
			else
                r2 = m2 - 1;
        }
		vector<int> ret;
		ret.push_back(r1);
		ret.push_back(l2);
        return ret;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
		int l = 0, r = nums.size()-1;

        if (!nums.size()) l = r + 1;
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return FindRange(nums, m, target);
			else if (r == l+1 && nums[r]==target)
				return FindRange(nums, r, target);
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
    }
};

int main()
{
	Solution S;
	int a [] = { 1, 4, 5, 5, 6, 6, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,31,32,33,34,35,36};
	vector<int> r = S.searchRange(vector<int>(a,a+7), 4);
	copy(r.begin(), r.end(), ostream_iterator<int, char>(cout, "\t"));
	return 0;
}