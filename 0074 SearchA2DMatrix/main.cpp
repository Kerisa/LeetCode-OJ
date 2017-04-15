/*
 * By	: Alisa
 * Date	: 15-08-13
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example, Consider the following matrix:
 *  [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 *  ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	// 两次二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        
        int row = matrix.size(), col = matrix[0].size();
        
        int l = 0, r = row-1, m1 = 1;
        while (l <= r)
        {
            m1 = (l + r) / 2;
            if (matrix[m1][0] == target) return true;
            else if (matrix[m1][0] > target && m1 && matrix[m1-1][0] < target)
			{
				--m1;
                break;
			}
            else if (matrix[m1][0] > target)
                r = m1-1;
            else l = m1+1;
        }
        
        l = 0;  r = col;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (matrix[m1][m] == target) return true;
            else if (matrix[m1][m] > target && m && matrix[m1][m-1] < target)
                break;
            else if (matrix[m1][m] > target)
                r = m-1;
            else l = m+1;
        }
        return false;
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
	A.push_back(vector<int>(a0, a0+2));
	A.push_back(vector<int>(a1, a1+1));
	A.push_back(vector<int>(a2, a2+6));
/*	A.push_back(vector<int>(a3, a3+6));
	A.push_back(vector<int>(a4, a4+6));
	A.push_back(vector<int>(a5, a5+6));
*/	
	cout << S.searchMatrix(A, 0) << endl;/*
	for (int i=0; i<A.size(); ++i)
	{
		copy(A[i].begin(), A[i].end(), ostream_iterator<int, char>(cout, "\t"));
		cout << endl;
	}
*/	return 0;
}