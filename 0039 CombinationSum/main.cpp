/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Given a set of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 *   All numbers (including target) will be positive integers.
 *   Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 *   The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 *   A solution set is: 
 *   [7] 
 *   [2, 2, 3] 
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    void Combine(vector<int> & cand, int start, int end, int tar, vector<vector<int>> & ret, vector<int> & tmp)
    {
        for (int i=start; i<=end && cand[i]<=tar;)
        {
            if (cand[i] == tar)
            {
                tmp.push_back(cand[i]);
                ret.push_back(tmp);
				tmp.pop_back();
                return;
            }
            tmp.push_back(cand[i]);
            Combine(cand, i, end, tar-cand[i], ret, tmp);
            tmp.pop_back();

			while (i<end && cand[i+1]==cand[i]) ++i;
			++i;
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if (!candidates.size()) return vector<vector<int>>();
        
		sort(candidates.begin(), candidates.end());

        int i=candidates.size()-1;
        while (i>=0 && candidates[i] > target) --i;

        vector<int> tmp;
        Combine(candidates, 0, i, target, ret, tmp);
        return ret;
    }
};

int main()
{
	Solution S;
	int a [] = {7, 3, 2, 6};
	vector<int> A(a, a+4);
	vector<vector<int>> R = S.combinationSum(A, 7);
	for (int i=0; i<R.size(); ++i)
	{
		for (int j=0; j<R[i].size(); ++j)
			cout << R[i][j] << " ";
		cout << endl;
	}
	getchar();
	return 0;
}