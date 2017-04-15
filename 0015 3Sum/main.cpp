#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {	// 遍历
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size() && nums[i] <= 0; /*++i*/)
        {
            for (int j=i+1; j<nums.size() && nums[j] <= 0-nums[i]; /*++j*/)
            {
                for (int k=j+1; k<nums.size(); /*++k*/)
				{
                    if (nums[k]+nums[j] == 0-nums[i])
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        ret.push_back(tmp);
						++k;
                    }
					else if (nums[k]+nums[j] > 0-nums[i])
						break;
					++k;	// 跳过相同数字
					while (k<nums.size() && nums[k] == nums[k-1])
						++k;
				}
				++j;	// 跳过相同数字
				while (j<nums.size() && nums[j] == nums[j-1])
					++j;
            }
			++i;	// 跳过相同数字
			while (i<nums.size() && nums[i] == nums[i-1])
				++i;
        }
        return ret;
    }
};

int main()
{
	int a [] = {-1,0,1,2,-1,-4};
	//int a[16] = {7,-4,-3,-2,1,0,0,0,0,-1,2,3,4,-5,6,5};
	//int a [] = {7,-13,-1,1,-6,14,10,-2,1,9,11,-10,8,-10,14,13,-1,4,-6,-3,-5,3,3,12,-5,11,5,-6,-2,0,-6,12,3,0,-2,12,-1,-7,-5,8,10,13,13,3,10,12,-7,-6,-7,-5,-1,3,5,-13,-8,-15,13,13,-14,-12,-2,-5,-15,8,11,-1,6,-13,-1,8,10,-14,-1,0,-4,-6,-3,5,-4,-2,7,10,8,-3,12,-14,-10,3,14,-9,-2,-11,-6,-9,13,12,-3,4,14,3,-11,2,5,-5,-13,-14,-3,-8};
	Solution S;
	vector<int> A(&a[0], &a[6]);
	vector<vector<int>> r = S.threeSum(A);
	
	for (int i=0; i<r.size(); ++i)
	{
		for (int j=0; j<r[i].size(); ++j)
			cout << r[i][j] << ' ';
		cout << endl;
	}
	return 0;
}