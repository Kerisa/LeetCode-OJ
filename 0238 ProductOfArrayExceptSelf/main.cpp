/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given an array of n integers where n > 1, nums,
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 * Follow up:
 * Could you solve it with constant space complexity?
 * (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);	// 超过1个0就全部都是0
        
        int m = 1, zeroidx, zeronum = 0;
        for (int i=nums.size()-1; i>=0; --i)
		{
			if (!nums[i])
			{
				if (++zeronum > 1) break;
				zeroidx = i;
			}
            else m *= nums[i];
		}
			
		if (!zeronum)
			for (int i=0; i<nums.size(); ++i)
				ret[i] = m / nums[i];

		if (zeronum == 1)	// 一个0时除它以外都是0
			ret[zeroidx] = m;
            
        return ret;
    }
};
int main()
{
	Solution S;
	int a [] = {2,1,2,3,4,5,6,7,8};
	vector<int> r = S.productExceptSelf(vector<int>(a,a+9));
	copy(r.begin(), r.end(), ostream_iterator<int, char>(cout, " "));
	return 0;
}