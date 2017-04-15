/*
 * By	: Alisa
 * date	: 15-08-14
 *
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * Here are few examples.
 *   [1,3,5,6], 5 ¡ú 2
 *   [1,3,5,6], 2 ¡ú 1
 *   [1,3,5,6], 7 ¡ú 4
 *   [1,3,5,6], 0 ¡ú 0
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = -1;		// -1
        
        while (l <= r)								// l<=r
        {
            m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (r == l+1 && nums[r]==target)
                return r;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        if (target < nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();
		if (nums[m] > target)					// nums[m] <> target
			return m;
		return m + 1;							// m+1
    }
};

int main()
{
	Solution S;
	int a [] = {1,3,3,3,5,5,5,5,6};
	cout << S.searchInsert(vector<int>(a,a+2), 2) << endl;
	return 0;
}