/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 *   A = [2,3,1,1,4], return true.
 *   A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int p = 0, end = nums.size()-1;
        for (;p<end;)
        {
            if (!nums[p]) return false;
            int next = p + nums[p];
            if (next >= end)
                return true;
            int max = 0;
            for (int i=next; i>p; --i)
            {
                if (nums[i]+i-p > max)
				{
					max = nums[i]+i-p;
					next = i;
				}
            }
            p = next;
        }
		return true;
    }
};

int main()
{
	Solution S;
	int a [] = {2,3,1,1,4,1,5,6,5,4,3,3,1,0,3,6};
	cout << S.canJump(vector<int>(a, a+16)) << endl;
	return 0;
}