/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 * Ensure that numbers within the set are sorted in ascending order.
 * Example 1:
 *   Input: k = 3, n = 7
 *   Output: [[1,2,4]]
 * Example 2:
 *   Input: k = 3, n = 9
 *   Output: [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void Combine(int tar, int deep, int start, vector<vector<int>> & ret, vector<int> & tmp)
    {
		if (!deep) return;
        for (int i=start; i<=9; ++i)
        {
            if (i == tar && deep == 1)
            {
                tmp.push_back(i);
                ret.push_back(tmp);
				tmp.pop_back();
                return;
            }
            tmp.push_back(i);
            Combine(tar-i, deep-1, i+1, ret, tmp);
            tmp.pop_back();
        }
    }
    
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ret;

        if (!k)
			return ret;
		else if (k == 1)
			ret.push_back(vector<int>(1, n));
		else {
			vector<int> tmp;
			Combine(n, k, 1, ret, tmp);
		}
		return ret;
    }
};

int main()
{
	Solution S;
	vector<vector<int>> R = S.combinationSum3(3,7);
	for (int i=0; i<R.size(); ++i)
	{
		for (int j=0; j<R[i].size(); ++j)
			cout << R[i][j] << " ";
		cout << endl;
	}
	getchar();
	return 0;
}