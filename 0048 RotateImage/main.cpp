/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up: Could you do this in-place?
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	// 坐标关系算对就行
    void rotate(vector<vector<int>>& matrix) {
        vector<int> tmp;
        int n = matrix.size(), times = (matrix.size() - 1) / 2;
        for (int i=0; i<=times; ++i)
        {
            for (int j=i; j<n-i-1; ++j)
				tmp.push_back(matrix[i][j]);
            for (int j=i+1; j<n-i; ++j)
            {
                matrix[i][n-j-1] = matrix[j][i];			// 左→上
                matrix[j][i] = matrix[n-i-1][j];			// 下→左
                matrix[n-i-1][j] = matrix[n-j-1][n-1-i];    // 右→下
				matrix[n-j-1][n-1-i] = tmp.back();			// 上→右
				tmp.pop_back();
            }
            tmp.clear();
        }
    }
};
int main()
{
	Solution S;
	int a0 [] = { 1, 2, 3, 4, 5, 6};
	int a1 [] = { 7, 8, 9,10,11,12};
	int a2 [] = {13,14,15,16,17,18};
	int a3 [] = {19,20,21,22,23,24};
	int a4 [] = {25,26,27,28,29,30};
	int a5 [] = {31,32,33,34,35,36};
	vector<vector<int>> A;
	A.push_back(vector<int>(a0, a0+6));
	A.push_back(vector<int>(a1, a1+6));
	A.push_back(vector<int>(a2, a2+6));
	A.push_back(vector<int>(a3, a3+6));
	A.push_back(vector<int>(a4, a4+6));
	A.push_back(vector<int>(a5, a5+6));/*
*/	S.rotate(A);
	for (int i=0; i<A.size(); ++i)
	{
		copy(A[i].begin(), A[i].end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	}
	return 0;
}