/*
 * By	: Alisa
 * Date	: 15-08-14
 *
 * Given an array with n objects colored red, white or blue,
 * sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note: You are not suppose to use the library's sort function for this problem.
 * Follow up:
 *    A rather straight forward solution is a two-pass algorithm using counting sort.
 *    First, iterate the array counting number of 0's, 1's, and 2's,
 *    then overwrite array with total number of 0's, then 1's and followed by 2's.
 *    Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	// 两边逼近，并用另一对指针记录0、2的索引
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
		int wl = l, wr = r;
        
        if (!nums.size()) return;
        
		while (l <= r)
		{
			while (l<r && nums[l] != 2)
			{
				if (nums[l] == 0)
					nums[wl++] = 0;
				++l;
			}
			while (l<r && nums[r] != 0)
			{
				if (nums[r] == 2)
					nums[wr--] = 2;
				--r;
			}
			if (l == r)
			{
				if (nums[l] == 0) nums[wl++] = 0;
				else if (nums[r] == 2) nums[wr--] = 2;
				break;
			}
			if (l < r)
			{
				nums[wl++] = 0;
				nums[wr--] = 2;
			}
				++l;
				--r;
        }
        for (int i=wl; i<=wr; ++i)
			nums[i] = 1;
        return;
    }
};

int main()
{
	Solution S;
	int a [] = { 2, 0, 1, 0,1,1};
	vector<int> A(a,a+6);
	S.sortColors(A);

	copy(A.begin(), A.end(), ostream_iterator<int, char>(cout, "\t"));
	cout << endl;
	return 0;
}
