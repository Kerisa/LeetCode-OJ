/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int l, r, sum = 0;
        for (l=r=0 ;r < nums.size(); ++r)
        {
            if ((sum += nums[r]) >= s)
            {
                while (l<r && sum - nums[l] >= s)
				{
					sum -= nums[l];
					++l;
				}
                len = len > r-l+1 ? r-l+1 : len;
            }
        }
        return len < nums.size() ? len : 0;
    }
};

int main()
{
	Solution S;
	int a [] = {2,3,1,1,1,1,1};
	cout << S.minSubArrayLen(5, vector<int>(a,a+7)) << endl;
	return 0;
}