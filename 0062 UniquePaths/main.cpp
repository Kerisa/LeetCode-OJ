/*
 * By	: Alisa
 * Date	: 15-08-14
 *
 * Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example, There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *   [
 *    [0,0,0],
 *    [0,1,0],
 *    [0,0,0]
 *   ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (!m || !n) return 1;
        
        vector<vector<int>> p(m, vector<int>(n, 0));
        
        for (int i=0; i<n; ++i)
            p[0][i] = 1;
        for (int i=0; i<m; ++i)
            p[i][0] = 1;
            
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
                p[i][j] = p[i-1][j] + p[i][j-1];
                
        return p[m-1][n-1];
    }
};

int main()
{
	Solution S;
	
	cout << S.uniquePaths(1,2) << endl;
	return 0;
}