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
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        if (!G.size() || !G[0].size() || G[0][0]==1) return 0;	//G[0][0]
        int row = G.size(), col = G[0].size();
        
        for (int i=0; i<col; ++i)
            if (!G[0][i])
                ++G[0][i];
            else while (i<col) G[0][i++] = 0;
            
        for (int i=1; i<row; ++i)
            if (!G[i][0])
                ++G[i][0];
            else while (i<row) G[i++][0] = 0;
            
        for (int i=1; i<row; ++i)
            for (int j=1; j<col; ++j)
                if (!G[i][j])
                {
                    G[i][j] = G[i][j-1] + G[i-1][j];
                }
                else G[i][j] = 0;
                
        return G[row-1][col-1];
    }
};

int main()
{
	Solution S;
	int a0 [] = {1,0,0,0};
	int a1 [] = {0,0,0,1};
	int a2 [] = {0,0,0,0};
	int a3 [] = {1,1,0,0};
	int a4 [] = {0,0,0,1};
	int a5 [] = {0,0,0,0};
	vector<vector<int>> A;
	A.push_back(vector<int>(a0, a0+1));
	A.push_back(vector<int>(a1, a1+1));
/*	A.push_back(vector<int>(a2, a2+4));
	A.push_back(vector<int>(a3, a3+4));
	A.push_back(vector<int>(a4, a4+4));
	A.push_back(vector<int>(a5, a5+4));
*/	
	cout << S.uniquePathsWithObstacles(A) << endl;
	return 0;
}