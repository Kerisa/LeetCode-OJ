/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * For example:
 *   Given array A = [2,3,1,1,4]
 *   The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int p = 0, end = nums.size()-1, step = 0;
        for (;p<end;)
        {
            int next = p + nums[p];
            if (next >= end)
                return ++step;
            int max = 0;
            for (int i=next; i>p; --i)
            {
                if (nums[i]+i-p > max && nums[i])	// 使下一个位置距离现在最远,并且下一个位置能跳的距离不为0(这个其实不用加)
				{
					max = nums[i]+i-p;
					next = i;
				}
            }
            p = next;
            ++step;
        }
		return step;
    }
};

int main()
{
	Solution S;
	int a [] = {2,3,1,1,4,1,5,6,5,4,3,3,1,0,3,6};
	cout << S.jump(vector<int>(a, a+16)) << endl;
	return 0;
}