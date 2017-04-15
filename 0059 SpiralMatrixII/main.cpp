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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, n));
        int up = 0, down = n-1, left = 0, right = n-1;
        int num = 1;
        while (1)
        {
            if (up > down) break;
            for (int i=left; i<=right; ++i) m[up][i] = num++;
            ++up;
            
            if (right < left) break;
            for (int i=up; i<=down; ++i) m[i][right] = num++;
            --right;
            
            if (down < up) break;
            for (int i=right; i>=left; --i) m[down][i] = num++;
            --down;
            
            if (left > right) break;
            for (int i=down; i>=up; --i) m[i][left] = num++;
            ++left;
        }
        return m;
    }
};

int main()
{
	Solution S;

	vector<vector<int>> A = S.generateMatrix(5);
	for (int i=0; i<A.size(); ++i)
	{
		copy(A[i].begin(), A[i].end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	}
	return 0;
}