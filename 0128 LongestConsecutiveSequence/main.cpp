/*
 * By	: Alisa
 * Date	: 15-08-12
 *
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example,
 *   Given [100, 4, 200, 1, 3, 2],
 *   The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_len = 1;
        for (int i=0; i<nums.size()-1; ++i)
        {
            int len = 1;
            if (nums[i]+1 == nums[i+1])
            {
                while (i<nums.size()-1 && nums[i]+1 == nums[i+1])
                {
					++i;
					while (i<nums.size()-1 && nums[i]==nums[i+1]) ++i;	// 跳过相等的
                    ++len;
                }
                if (len > max_len) max_len = len;
            }
        }
		return max_len;
    }
};

int main()
{
	Solution S;
	int a [] = {100,4,200,2,2,3,1,7,6,101,9,11,12,13,15};
	cout << S.longestConsecutive(vector<int>(a,a+15)) << endl;
	return 0;
}