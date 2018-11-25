/*
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

    Example:
    Consider the following matrix:

    [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    Given target = 5, return true.

    Given target = 20, return false.
*/

// select probable row first, and try each one in the row, if num > target then shift to the row above

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size() - 1;
        int c = 0;
        while (r >= 0 && c < matrix[0].size())
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                --r;
            else
                ++c;
        }
        return false;
    }
};


#include <cassert>
#include <iterator>
int main()
{
    vector<vector<int>> M{ {1,4,7,11,15}, { 2,5,8,12,19 }, { 3,6,11,16,22 }, { 10,13,14,17,24 }, {18,21,23,26,30} };
    assert(Solution().searchMatrix(M, 1));
    assert(Solution().searchMatrix(M, 11));
    assert(Solution().searchMatrix(M, 30));
    assert(Solution().searchMatrix(M, 22));
    assert(Solution().searchMatrix(M, 10));
    
    assert(!Solution().searchMatrix(M, 100));
    assert(!Solution().searchMatrix(M, 9));

    assert(Solution().searchMatrix(vector<vector<int>>{{ 18,21,23,26,30 } }, 18));
    assert(Solution().searchMatrix(vector<vector<int>>{{ 18,21,23,26,30 } }, 30));
    assert(!Solution().searchMatrix(vector<vector<int>>{{ 18,21,23,26,30 } }, 9));
    
    assert(Solution().searchMatrix(vector<vector<int>>{{ 18 } }, 18));
    assert(!Solution().searchMatrix(vector<vector<int>>{{ 18 } }, 30));
    return 0;
}