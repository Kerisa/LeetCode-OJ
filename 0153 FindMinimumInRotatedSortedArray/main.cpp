/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int min(const int a, const int b)
    {
        return a>b ? b : a;
    }
    int FindMin(vector<int>& nums, int l, int r)
    {
        if (l == r) return nums[l];
        
        int m = (l + r) / 2;
        if (m>l && m<r)
        {
            if (nums[m]>nums[m-1] && nums[m]>nums[m+1])
            return nums[m+1];
            
            return min(FindMin(nums, l, m), FindMin(nums, m+1, r));
        }
        return min(nums[m], nums[m+1]);
    }
public:
    int findMin(vector<int>& nums) {
		if (!nums.size()) return 0;
        return FindMin(nums, 0, nums.size()-1);
    }
};

int main()
{
	Solution S;
	int a [] = {5,6,7,8,9,10,44,1,2,3};
	cout << S.findMin(vector<int>(a, a+10)) << endl;
	return 0;
}