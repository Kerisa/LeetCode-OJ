/*
 * By	: Alisa
 * Date	: 15-08-12
 * 
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 * Hint: How many majority elements could it possibly have?
 */

#include <map>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 容器 map
    vector<int> _majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i=nums.size()-1; i>=0; --i)
        {
            if (m.end() == m.find(nums[i]))
                m.insert(pair<int,int>(nums[i], 1));
            else
                ++m[nums[i]];
        }

        int times = nums.size() / 3;
        vector<int> ret;

        for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
            if ((*it).second > times)
                ret.push_back((*it).first);
                
        return ret;
    }

	// 可能的值最多只有两个
	vector<int> majorityElement(vector<int>& nums) {
		int maj1 = 0, maj2 = 0;
		int cnt1 = 0, cnt2 = 0;

		for (int i=nums.size()-1; i>=0; --i)
			if (!cnt1)
			{
				maj1 = nums[i];
				cnt1 = 1;
			}
			else if (nums[i] == maj1)
				++cnt1;
			else if (!cnt2)
			{
				maj2 = nums[i];
				cnt2 = 1;
			}
			else if (nums[i] == maj2)
				++cnt2;
			else
			{
				--cnt1;
				--cnt2;
			}

		vector<int> ret;
		cnt1 = cnt2 = 0;
		for (int i=0; i<nums.size(); ++i)
			if (nums[i] == maj1) ++cnt1;
			else if (nums[i] == maj2) ++cnt2;

		if (cnt1 > nums.size() / 3) ret.push_back(maj1);
		if (cnt2 > nums.size() / 3) ret.push_back(maj2);

		return ret;
	}
};

int main()
{
	Solution S;
	int a [] = {1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,7,1,3,2,4,5,6,2,1,4,5,6,1,5,6,3,1};
	vector<int> r = S.majorityElement(vector<int>(a,a+5));
	copy(r.begin(), r.end(), ostream_iterator<int,char>(cout, " "));
	return 0;
}