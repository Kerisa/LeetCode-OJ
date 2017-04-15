/*
 * By	: Alisa
 * Date	: 15-08-11
 *
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6]
 */

#include <iostream>
#include <vector>
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
            Combine(cand, i+1, end, tar-cand[i], ret, tmp);
            tmp.pop_back();

			while (i<end && cand[i+1]==cand[i]) ++i;
			++i;
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if (!candidates.size()) return ret;
        
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
	//int a [] = {7, 10, 2, 1, 1, 5, 6};
	int a [] = {5};
	vector<int> A(a, a+1);
	vector<vector<int>> R = S.combinationSum2(A, 5);
	for (int i=0; i<R.size(); ++i)
	{
		for (int j=0; j<R[i].size(); ++j)
			cout << R[i][j] << " ";
		cout << endl;
	}
	getchar();
	return 0;
}