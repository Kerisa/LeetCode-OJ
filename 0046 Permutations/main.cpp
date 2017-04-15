/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given a collection of numbers, return all possible permutations.
 * For example,
 *   [1,2,3] have the following permutations:
 *   [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
    void Enterence(vector<int>& nums, int begin, vector<int>& tmp, vector<vector<int>>& ret)
    {
        if (begin == nums.size())
            ret.push_back(tmp);
        else for (int i=begin; i<nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            swap(nums[i], nums[begin]);
            Enterence(nums, begin+1, tmp, ret);
            swap(nums[i], nums[begin]);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ret;
        vector<int> tmp;
        Enterence(nums, 0, tmp, ret);
        return ret;
    }
};
int main()
{
	Solution S;
	int a [] = {1,6,7,2,3,4,9,8,1};
	vector<vector<int>> r = S.permute(vector<int>(a,a+3));
	for (int i=0; i<r.size(); ++i)
	{
		copy(r[i].begin(), r[i].end(), ostream_iterator<int, char>(cout, " "));
		cout << endl;
	}
	return 0;
}