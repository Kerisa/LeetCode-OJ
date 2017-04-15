/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Note: 
 *     Elements in a subset must be in non-descending order.
 *     The solution set must not contain duplicate subsets.
 * For example, If nums = [1,2,3], a solution is:
 *  [
 *    [3]
 *    [2],
 *    [1],
 *    [1,2,2],
 *    [2,3],
 *    [1,2],
 *    [1,3],
 *    []
 *  ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
	// 和题90完全一样
	// 函数名不一样
    void setN(vector<int>& nums, int begin, vector<vector<int>>& ret, vector<int>& tmp, int n)
    {
        if (!n)
        {
            ret.push_back(tmp);
            return;
        }
        for (int i=begin; i<nums.size(); ++i)
        {
            tmp.push_back(nums[i]);
            swap(nums[i], nums[begin]);
            setN(nums, i+1, ret, tmp, n-1);
            swap(nums[i], nums[begin]);
            tmp.pop_back();
            
            while (i<nums.size()-1 && nums[i] == nums[i+1]) ++i;
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        ret.push_back(vector<int>());
        if (!nums.size()) return ret;
        
        vector<int> tmp;
        for (int i=1; i<nums.size(); ++i)
        {
			setN(nums, 0, ret, tmp, i);
        }
		ret.push_back(nums);
		return ret;
    }
};

int main()
{
	Solution S;
	int a [] = { 1, 2, 2, 4, 5, 5};
	vector<vector<int>> r = S.subsets(vector<int>(a,a+6));
	for (int i=0; i<r.size(); ++i)
	{
		copy(r[i].begin(), r[i].end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	}
	return 0;
}