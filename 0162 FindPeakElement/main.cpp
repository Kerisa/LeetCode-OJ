/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -¡Þ.
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int FindMin(vector<int>& nums, int l, int r)
    {
        int m = (l + r) / 2;
        if (m>l && m<r)
        {
            if (nums[m]>nums[m-1] && nums[m]>nums[m+1])
            return m;
            
			int left,right;
            if ((left = FindMin(nums, l, m)) != -1) return left;
			if ((right = FindMin(nums, m+1, r)) != -1) return right;
        }
		if (l > 0 || r < nums.size()-1)
		{
			return nums[m] > nums[m+1] && nums[m] > nums[m-1] ? m : -1;
		}
        return -1;
    }
public:
    int findPeakElement(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		if (nums[1] < nums[0]) return 0;
		if (nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
		
        return FindMin(nums, 0, nums.size()-1);
    }
};

int main()
{
	Solution S;
	int a [] = {1,2,3,1,5,6,7,8,9,10,44,1,2,3};
	cout << S.findPeakElement(vector<int>(a, a+14)) << endl;
	return 0;
}