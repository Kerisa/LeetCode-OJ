/*
 * By	: Alisa
 * Date	: 15-08-14
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle
 *   [
 *        [2],
 *       [3,4],
 *      [6,5,7],
 *     [4,1,8,3]
 *   ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * Note: Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        vector<int> path(tri.size(), (int)0x80000000);
        
		if (!tri.size()) return 0;
        path[0] = tri[0][0];
        
        for (int i=1; i<tri.size(); ++i)
        {
			path[i] = path[i-1] + tri[i][i];
            for (int j=i-1; j>0; --j)
            {														// 一开始写成了这个...OTZ
                path[j] = tri[i][j] + min(path[j], path[j-1]);		// path[j] += min(tri[i][j], tri[i][j+1]);
            }
			path[0] += tri[i][0];
        }
        int ret = path[0];
        for (int i=1; i<tri.size(); ++i)
            if (path[i] < ret)
                ret = path[i];
                
        return ret;
    }
};

int main()
{
	Solution S;
	int a0 [] = { -1, 2, 3, 4, 5, 5};
	int a1 [] = { 3, 2, 9,10,11,12};
	int a2 [] = {-3,1,-1,17,17,18};
	int a3 [] = {19,20,21, 0,23,24};
	int a4 [] = {25,26,27,28,29,30};
	int a5 [] = {31,32,33,34,35,36};
	vector<vector<int>> A;
	A.push_back(vector<int>(a0, a0+1));
	A.push_back(vector<int>(a1, a1+2));
	A.push_back(vector<int>(a2, a2+3));
/*	A.push_back(vector<int>(a3, a3+4));
	A.push_back(vector<int>(a4, a4+5));
	A.push_back(vector<int>(a5, a5+6));
*/	
	cout << S.minimumTotal(A) << endl;
	return 0;
}