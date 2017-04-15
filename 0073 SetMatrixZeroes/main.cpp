/*
 * By	: Alisa
 * Date	: 15-08-14
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * Follow up:
 *   Did you use extra space?
 *   A straight forward solution using O(mn) space is probably a bad idea.
 *   A simple improvement uses O(m + n) space, but still not the best solution.
 *   Could you devise a constant space solution?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
	// 用矩阵的0行 0列作为标志位以达到O(1)空间的效果
    void setZeroes(vector<vector<int>>& m) {
        bool ZeroRow = false, ZeroCol = false;
		int i, j;
        if (!m.size() || !m[0].size()) return;
        
        for (i=0; i<m[0].size() && !ZeroRow; ++i)
            if (!m[0][i])
                ZeroRow = true;
                
        for (i=0; i<m.size() && !ZeroCol; ++i)
            if (!m[i][0])
                ZeroCol = true;
                
        for (i=1; i<m.size(); ++i)
            for (j=1; j<m[0].size(); ++j)
                if (!m[i][j])
                    m[i][0] = m[0][j] = 0;
                
        // Replace
        for (i=1; i<m.size(); ++i)
            for (j=1; j<m[0].size(); ++j)
                if (!m[i][0] || !m[0][j])
                    m[i][j] = 0;
                    
        if (ZeroRow)
            for (i=0; i<m[0].size(); ++i)
                m[0][i] = 0;
                
        if (ZeroCol)
            for (i=0; i<m.size(); ++i)
                m[i][0] = 0;
    }
};

int main()
{
	Solution S;
	int a0 [] = { 1, 2, 3, 4, 5, 5};
	int a1 [] = { 7, 8, 9,10,11,12};
	int a2 [] = {13,14,15,17,17,18};
	int a3 [] = {19,20,21, 0,23,24};
	int a4 [] = {25,26,27,28,29,30};
	int a5 [] = {31,32,33,34,35,36};
	vector<vector<int>> A;
	A.push_back(vector<int>(a0, a0+6));
	A.push_back(vector<int>(a1, a1+6));
	A.push_back(vector<int>(a2, a2+6));
	A.push_back(vector<int>(a3, a3+6));
	A.push_back(vector<int>(a4, a4+6));
	A.push_back(vector<int>(a5, a5+6));/*
*/	
	S.setZeroes(A);
	for (int i=0; i<A.size(); ++i)
	{
		copy(A[i].begin(), A[i].end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	}
	return 0;
}