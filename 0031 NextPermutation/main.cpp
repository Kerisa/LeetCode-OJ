/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *   1,2,3 → 1,3,2
 *   3,2,1 → 1,2,3
 *   1,1,5 → 1,5,1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
		int i;
        for (i=nums.size()-2; i>=0; --i)
            if (nums[i] < nums[i+1])
                break;
        if (i >= 0)
		{
			int j = nums.size()-1;
			while (j>i && nums[j] <= nums[i]) --j;	// 交换第一个大于nums[i]的数
			swap(nums[i], nums[j]);
			sort(nums.begin()+1+i, nums.end());
		} else 
			sort(nums.begin(), nums.end());
    }
};

int main()
{
	Solution S;
	int a [] = {2,3,1,2,7,6,5,4};
	vector<int> r(a+1,a+3);
	S.nextPermutation(r);
	copy(r.begin(), r.end(), ostream_iterator<int, char>(cout, " "));
	return 0;
}