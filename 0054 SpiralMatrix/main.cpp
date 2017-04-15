/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example, Given n = 3, You should return the following matrix:
 *  [
 *    [ 1, 2, 3 ],
 *    [ 8, 9, 4 ],
 *    [ 7, 6, 5 ]
 *  ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	// 没有任何技巧的直接生成
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> m;
		int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        int num = 1;
        while (1)
        {
            if (up > down) break;
			for (int i=left; i<=right; ++i) m.push_back(matrix[up][i]);
            ++up;
            
            if (right < left) break;
            for (int i=up; i<=down; ++i) m.push_back(matrix[i][right]);
            --right;
            
            if (down < up) break;
            for (int i=right; i>=left; --i) m.push_back(matrix[down][i]);
            --down;
            
            if (left > right) break;
            for (int i=down; i>=up; --i) m.push_back(matrix[i][left]);
            ++left;
        }
        return m;
    }
};

int main()
{
	Solution S;
	int a0 [] = { 1, 2, 3, 4, 5, 5};
	int a1 [] = { 7, 8, 9,10,11,12};
	int a2 [] = {13,14,15,17,17,18};
	int a3 [] = {19,20,21,22,23,24};
	int a4 [] = {25,26,27,28,29,30};
	int a5 [] = {31,32,33,34,35,36};
	vector<vector<int>> A;
	A.push_back(vector<int>(a0, a0+6));
	A.push_back(vector<int>(a1, a1+6));
	A.push_back(vector<int>(a2, a2+6));
	A.push_back(vector<int>(a3, a3+6));
	A.push_back(vector<int>(a4, a4+6));
/*	A.push_back(vector<int>(a5, a5+6));
*/	
	vector<int> r = S.spiralOrder(A);

		copy(r.begin(), r.end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	return 0;
}